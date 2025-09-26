#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

void inRange_demo(Mat &image)
{
	Mat hsv;
	cvtColor(image, hsv, COLOR_BGR2HSV);
	Mat mask;  //mask也成为掩码图
	//二值化，inrange函数将阈值内的像素值设为白色255，阈值外像素值设为黑色0
	inRange(hsv, Scalar(35, 43, 46), Scalar(77, 255, 255), mask); //扣绿幕：输入图像；hsv表中绿色像素的下限；hsv表中绿色像素的上限；输出图像
	imshow("mask", mask);

	Mat redback = Mat::zeros(image.size(), image.type());
	redback = Scalar(40, 40, 200);  //创建一个纯红色图像作为背景
	bitwise_not(mask, mask);  //mask掩码图取反，保证背景为黑色0,
	imshow("mask", mask);
	image.copyTo(redback, mask);  //把输入图像image复制到redback上，并且输入图像对应掩码mask中像素值为0的点不会复制到redback上（mask图中背景为黑色，即原图背景不复制，仅复制人像）
	imshow("roi区域提取", redback);

}
int main()
{
	Mat src = imread("D:/Image/green.png");
	if (src.empty()) {
		printf("could not load image....");
		return -1;
	}
	imshow("输入窗口", src);

	inRange_demo(src);

	waitKey(0);
	return 0;
}
