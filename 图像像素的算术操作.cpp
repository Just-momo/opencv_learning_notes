#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

void operators_demo(Mat &image)
{
	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type()); //创建一个大小和类型与图像image一致的空图像m
	m = Scalar(5, 5, 5);
	//multiply(image, m, dst);  //两个图像相乘的函数，第一个参数为输入图像，第二个相乘的图像，第三个输出图像
	//dst = image*2;  //也可以直接输入图像乘一个数，若超出255就截断为255，

	//加法运算
	/*int w = image.cols;
	int h = image.rows;
	int dims = image.channels();

	for (int row = 0; row < h; row++)
	{
		for (int col = 0; col < w; col++)
		{
			Vec3b p1 = image.at<Vec3b>(row, col);  //3通道则一个像素点有三个值，Vec3b可以一次性获取3个值
			Vec3b p2 = m.at<Vec3b>(row, col);
			dst.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(p1[0] + p2[0]); //saturate_cast函数防止溢出，运算结果为负，则转为0，结果超出255，则为255
			dst.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(p1[1] + p2[1]);
			dst.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(p1[2] + p2[2]);
		}
	}
	*/
	//直接调用api
	//add(image, m, dst);
	//subtract(image, m, dst);
	divide(image, m, dst);
	imshow("加法操作", dst);
}

int main()
{
	Mat src = imread("D:/Image/1024.png");
	if (src.empty()) {
		printf("could not load image....");
		return -1;
	}

	imshow("输入窗口", src);

	operators_demo(src);

	waitKey(0);
	return 0;
}