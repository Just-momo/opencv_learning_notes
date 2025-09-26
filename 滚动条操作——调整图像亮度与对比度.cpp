#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

static void on_lightness(int b, void* userdata) {
	Mat image = *((Mat*)userdata);  //强制类型转换，createTrackbar将&image（指针）传进userdata，其为任意类型，强制转换为Mat类型，解引用得到值image
	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type());
	//调对比度时不用这句m = Scalar(b, b, b);  //形参b由createTrackbar中的lightness引用传递，b即为lightness
	//subtract(image, m, dst);  //两张图相减，实现亮度调节
	addWeighted(image, 1.0, m, 0, b, dst);  //addWeighted主要公式为:dst = src1 * alpha + src2 * beta + gamma
	imshow("亮度与对比度调整", dst);

}

static void on_contrast(int b, void* userdata) {
	Mat image = *((Mat*)userdata);  //强制类型转换，createTrackbar将&image（指针）传进userdata，其为任意类型，强制转换为Mat类型，解引用得到值image
	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type());
	double contrast = b / 100.0;
	//addWeighted函数，可以调整两张图像的比例来输出一个混合的图像
	addWeighted(image, contrast, m, 0.0, 0, dst);  //这里输出dst=imagecontrast+0+0,即只调整对比度
	imshow("亮度与对比度调整", dst);

}

void tracking_bar_demo(Mat &image)
{
	namedWindow("亮度与对比度调整", WINDOW_AUTOSIZE);  //图像不大的时候可以用自动大小
	int lightness = 50;  //当前亮度值
	int max_value = 100;  //最大亮度值
	int contrast_value = 100;
	createTrackbar("lightness Bar:", "亮度与对比度调整", &lightness, max_value, on_lightness, &image);
	createTrackbar("Contrast Bar:", "亮度与对比度调整", &contrast_value, 200, on_contrast, &image);
	/*createTrackbar函数各参数为：1滚动条名称；2滚动条所在的窗口名称；3滑块初始值位置以及后面所在的位置；4改变的最大值（最小值不用写，默认为0）；
	5滚动条回调函数，拖动滚动条后，系统调用该函数来实时调整lightness的值，取地址故用&；6可以外带的任意类型的数据，也可以不用
	*/
}

int main()
{
	Mat src = imread("D:/Image/1024.png");
	if (src.empty()) {
		printf("could not load image....");
		return -1;
	}
	imshow("输入窗口", src);

	tracking_bar_demo(src);

	waitKey(0);
	return 0;
}
