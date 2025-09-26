#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

//1.怎么操作它 2.怎么访问每一个像素点 3.怎么创建一个空图或Mat

void mat_creation_demo() {
	//Mat m1, m2;
	//m1 = image.clone();
	//image.copyTo(m2);

	//一、创建空白图像，常用ones和zeros初始化
	Mat m3 = Mat::zeros(Size(150, 150), CV_8UC3);  //8位无符号字符，1为单通道，每个像素点有1个数据，若为3则是三通道，每个像素点有3个数据
	//Mat m3 = Mat::ones(Size(8, 8), CV_8UC3);  //oens初始化，多通道时，只在第一个通道显示为1，其余默认为0，方便观察像素点个数和起始位置

	//二、给通道赋值
	//m3 = 127;
	m3 = Scalar(0, 0, 255);  //RGB三通道赋值，得到想要颜色的图像

	//获取图像的尺寸信息，图像的实际宽度是初始宽度*通道数
	std::cout << "width:" << m3.cols << std::endl;  //获取图像的宽度（单通道）
	std::cout << "height:" << m3.rows << std::endl;  //获取图像的高度
	std::cout << "channels:" << m3.channels() << std::endl;  //获取图像的通道数
	std::cout << m3 << std::endl;

	//直接赋值
	//Mat m4 = m3;   //将m3赋给m4,当m4改变时，m3也改变
	//m4 = Scalar(0, 255, 255);
	//imshow("图像", m3);

	//克隆赋值
	//Mat m4 = m3.clone();   //将m3克隆给m4,当m4改变时，m3不会变
	//m4 = Scalar(0, 255, 255);
	//imshow("图像3", m3);
	//imshow("图像4", m4);

	//拷贝赋值
	Mat m4;
	m3.copyTo(m4);  //将m3拷贝给m4,当m4改变时，m3不会变
	m4 = Scalar(0, 255, 255);
	imshow("图像3", m3);
	imshow("图像4", m4);
}

int main()
{
	Mat src = imread("D:/Image/1024.png");
	if (src.empty()) {
		printf("could not load image....");
		return -1;
	}

	imshow("输入窗口", src);

	mat_creation_demo();

	waitKey(0);
	return 0;
}