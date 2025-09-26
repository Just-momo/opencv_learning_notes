#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

void colorSpace_Demo(Mat &image) {
	Mat gray, hsv;
	cvtColor(image, hsv, COLOR_BGR2HSV);
	//H(色调)S(饱和度)V(亮度)三通道，H为0~180，S,V均为0~255，
	cvtColor(image, gray, COLOR_BGR2GRAY);
	imshow("HSV", hsv);
	imshow("灰度", gray);
	imwrite("D:/hsv.png", hsv);    //第一个参数为图像保存的位置，第二个参数是图像内存对象；
	imwrite("D:/gray.png", gray);

	//色彩空间转换函数：cv_Color
	//COLOR_BGR2GRAY = 6 彩色到灰度；
	//COLOR_GRAY2BGR = 8 灰度到彩色；
	//COLOR_BGR2HSV = 40 BGR到HSV;
	//COLOR_HSV2BGR = 54 HSV到BGR;
	//图像保存：imwrite:
	//第一个参数为图像保存的位置，第二个参数是图像内存对象；

	}

int main()
{
	Mat src = imread("D:/Image/1024.png"); 
	if (src.empty()) {
		printf("could not load image....");
		return -1;
	}

	imshow("输入窗口", src);

	 colorSpace_Demo(src);

	waitKey(0);
	return 0;
}