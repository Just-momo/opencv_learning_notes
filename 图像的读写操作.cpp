#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

void pixel_visit_demo(Mat &image)
{
	int w = image.cols;
	int h = image.rows;
	int dims = image.channels();

	//数组方式读写
	/*
	for (int row = 0; row < h; row++)
	{
		for (int col = 0; col < w; col++)
		{
			if (dims == 1) //单通道，灰度图像，每一个像素值是字节类型uchar
			{
			int pv = image.at<uchar>(row, col);  //获取当前像素值，在0-255之间
				image.at<uchar>(row, col) = 255 - pv;  //改变当前的像素值（取反）
			}
			if (dims == 3)   //三通道，彩色图像
			{
				Vec3b bgr = image.at<Vec3b>(row, col);  //3通道则一个像素点有三个值，Vec3b可以一次性获取3个值
				image.at<Vec3b>(row, col)[0] = 255 - bgr[0];
				image.at<Vec3b>(row, col)[1] = 255 - bgr[1];
			image.at<Vec3b>(row, col)[2] = 255 - bgr[2];

			}
		}
	}
	*/
	//imshow("像素读写演示",image);

	//指针方式读写
	for (int row = 0; row < h; row++)
	{
		uchar*current_row = image.ptr<uchar>(row);  //ptr获取行指针的一个函数。row为1，则获取第一行所有值的地址？
		for (int col = 0; col < w; col++)
		{
			if (dims == 1) //单通道，灰度图像，每一个像素值是字节类型uchar
			{
				int pv = *current_row;  //获取该列当前这行的像素值
				*current_row++ = 255 - pv;  //改变当前这行的像素值（取反），然后当前这行的地址++
			}
			if (dims == 3)   //三通道，彩色图像
			{
				//图像像素值取反
				*current_row++ = 255 - *current_row;
				*current_row++ = 255 - *current_row;
				*current_row++ = 255 - *current_row;
			}
		}
	}
	imshow("像素读写演示", image);
}


int main()
{
	Mat src = imread("D:/Image/1024.png");
	if (src.empty()) {
		printf("could not load image....");
		return -1;
	}
	imshow("输入窗口", src);

	pixel_visit_demo(src);

	waitKey(0);
	return 0;
}