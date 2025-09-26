#pragma once

#include<opencv2/opencv.hpp>

using namespace cv;

class  QuickDemo {
   public:
	 void colorSpace_Demo(Mat &image);  //图像色彩空间转换
	 void mat_creation_demo();  //图像创建与赋值
	 void pixel_visit_demo(Mat &image);  //图像像素的读写操作
	 void operators_demo(Mat &image);  //图像像素运算操作，改变图像亮度
	 void tracking_bar_demo(Mat &image);  // 滚动条操作演示——调整图像亮度和对比度
	 void key_demo(Mat &image);  //键盘响应操作
	 void key_style_demo(Mat &image);  //自带颜色表操作，生成多种风格的图像
	 void bitwise_demo(Mat &image);  //位操作，图像像素的逻辑操作
	 void channels_demo(Mat &image);  //通道分离与合并
	 void inRange_demo(Mat &image);  //二值化，主要是将在两个阈值内的像素值设置为白色（255），而不在阈值区间内的像素值设置为黑色（0）
	 
};
