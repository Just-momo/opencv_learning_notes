#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

void bitwise_demo(Mat &image)
{
	Mat m1 = Mat::zeros(Size(256, 256), CV_8UC3);
	Mat m2 = Mat::zeros(Size(256, 256), CV_8UC3);
	//rectangle函数参数：输入图像，图像位置大小，图像像素值，图像线条厚度（负数则为填充整个图像），抗锯齿强度，坐标点的小数点位数
	//Rect函数：（图像左上角x,y坐标，图像宽度，高度）
	rectangle(m1, Rect(100, 100, 80, 80), Scalar(255, 255, 0), -1, LINE_8, 0);
	rectangle(m2, Rect(150, 150, 80, 80), Scalar(0, 255, 255), -1, LINE_8, 0);
	imshow("m1", m1);
	imshow("m2", m2);
	Mat dst;
	//像素与操作
	//bitwise_and(m1, m2, dst);  //像素逻辑与，求两图像的交集，图像颜色由Scalar也进行与操作，输出Scalar(0,255,0)

	//像素或操作
	//bitwise_or(m1, m2, dst);

	//像素非操作
	//bitwise_not(image,dst);

	//像素异或操作
	bitwise_xor(m1, m2, dst);

	imshow("像素位操作", dst);

}


int main()
{
	Mat src = imread("D:/Image/1024.png");
	if (src.empty()) {
		printf("could not load image....");
		return -1;
	}

	imshow("输入窗口", src);

	bitwise_demo(src);

	waitKey(0);
	return 0;
}
