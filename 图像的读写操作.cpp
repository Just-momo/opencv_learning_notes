#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

void pixel_visit_demo(Mat &image)
{
	int w = image.cols;
	int h = image.rows;
	int dims = image.channels();

	//���鷽ʽ��д
	/*
	for (int row = 0; row < h; row++)
	{
		for (int col = 0; col < w; col++)
		{
			if (dims == 1) //��ͨ�����Ҷ�ͼ��ÿһ������ֵ���ֽ�����uchar
			{
			int pv = image.at<uchar>(row, col);  //��ȡ��ǰ����ֵ����0-255֮��
				image.at<uchar>(row, col) = 255 - pv;  //�ı䵱ǰ������ֵ��ȡ����
			}
			if (dims == 3)   //��ͨ������ɫͼ��
			{
				Vec3b bgr = image.at<Vec3b>(row, col);  //3ͨ����һ�����ص�������ֵ��Vec3b����һ���Ի�ȡ3��ֵ
				image.at<Vec3b>(row, col)[0] = 255 - bgr[0];
				image.at<Vec3b>(row, col)[1] = 255 - bgr[1];
			image.at<Vec3b>(row, col)[2] = 255 - bgr[2];

			}
		}
	}
	*/
	//imshow("���ض�д��ʾ",image);

	//ָ�뷽ʽ��д
	for (int row = 0; row < h; row++)
	{
		uchar*current_row = image.ptr<uchar>(row);  //ptr��ȡ��ָ���һ��������rowΪ1�����ȡ��һ������ֵ�ĵ�ַ��
		for (int col = 0; col < w; col++)
		{
			if (dims == 1) //��ͨ�����Ҷ�ͼ��ÿһ������ֵ���ֽ�����uchar
			{
				int pv = *current_row;  //��ȡ���е�ǰ���е�����ֵ
				*current_row++ = 255 - pv;  //�ı䵱ǰ���е�����ֵ��ȡ������Ȼ��ǰ���еĵ�ַ++
			}
			if (dims == 3)   //��ͨ������ɫͼ��
			{
				//ͼ������ֵȡ��
				*current_row++ = 255 - *current_row;
				*current_row++ = 255 - *current_row;
				*current_row++ = 255 - *current_row;
			}
		}
	}
	imshow("���ض�д��ʾ", image);
}


int main()
{
	Mat src = imread("D:/Image/1024.png");
	if (src.empty()) {
		printf("could not load image....");
		return -1;
	}
	imshow("���봰��", src);

	pixel_visit_demo(src);

	waitKey(0);
	return 0;
}