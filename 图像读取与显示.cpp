#include<opencv2/opencv.hpp>
#include<quickopencv.h>
#include<iostream>

using namespace cv;
using namespace std;

//图像的读取与显示

int main(int argc, char**argv) 
{
	// 图像的基本知识：IMREAD_GRAYSCALE，将图像灰度展示；IMREAD_UNCHANGED，不改变图像的通道，有透明通道也可以显示；IMREAD_ANYCOLOR显示任意格式的图像，如浮点型图像；IMREAD_ANYDEPTH，8位，16位,32位等的图像都可以显示；
	Mat src = imread("D:/Image/green.png");  //B,G,R三通道，取值范围都是0~255，透明通道也是0~255
	if (src.empty()) {
		printf("could not load image....");
		return -1;
	}
	//namedWindow("输入窗口", WINDOW_FREERATIO);  //创建一个窗口，若图像过大，通过此窗口自由显示图像
	//namedWindow创建自由比例窗口时，imshow的标题名要跟namedWindow一致

	imshow("输入窗口", src);   //第一个参数为窗口名称，src为该图像的数据类型
	//imshow只能展示8位的图片，其它格式可能会出问题，如展示不全等

	waitKey(0);//阻断程序执行，参数0表示一直阻断，参数1则为阻断1毫秒
	return 0;
}