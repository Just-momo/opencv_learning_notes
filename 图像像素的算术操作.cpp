#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

void operators_demo(Mat &image)
{
	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type()); //����һ����С��������ͼ��imageһ�µĿ�ͼ��m
	m = Scalar(5, 5, 5);
	//multiply(image, m, dst);  //����ͼ����˵ĺ�������һ������Ϊ����ͼ�񣬵ڶ�����˵�ͼ�񣬵��������ͼ��
	//dst = image*2;  //Ҳ����ֱ������ͼ���һ������������255�ͽض�Ϊ255��

	//�ӷ�����
	/*int w = image.cols;
	int h = image.rows;
	int dims = image.channels();

	for (int row = 0; row < h; row++)
	{
		for (int col = 0; col < w; col++)
		{
			Vec3b p1 = image.at<Vec3b>(row, col);  //3ͨ����һ�����ص�������ֵ��Vec3b����һ���Ի�ȡ3��ֵ
			Vec3b p2 = m.at<Vec3b>(row, col);
			dst.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(p1[0] + p2[0]); //saturate_cast������ֹ�����������Ϊ������תΪ0���������255����Ϊ255
			dst.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(p1[1] + p2[1]);
			dst.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(p1[2] + p2[2]);
		}
	}
	*/
	//ֱ�ӵ���api
	//add(image, m, dst);
	//subtract(image, m, dst);
	divide(image, m, dst);
	imshow("�ӷ�����", dst);
}

int main()
{
	Mat src = imread("D:/Image/1024.png");
	if (src.empty()) {
		printf("could not load image....");
		return -1;
	}

	imshow("���봰��", src);

	operators_demo(src);

	waitKey(0);
	return 0;
}