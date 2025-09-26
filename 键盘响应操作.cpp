#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

void key_demo(Mat &image)
{
	Mat dst = Mat::zeros(image.size(), image.type());
	while (true) {
		int c = waitKey(100);
		if (c == 27) {  //按Esc退出循环
			break;
		}
		if (c == 49) {  //key = 1
			std::cout << "you enter key # 1" << std::endl;
			cvtColor(image, dst, COLOR_BGR2GRAY);  //灰度转换

		}
		if (c == 50) {  //key = 2
			std::cout << "you enter key # 2" << std::endl;
			cvtColor(image, dst, COLOR_BGR2HSV);  //HSV转换

		}
		if (c == 51) {  //key = 3
			std::cout << "you enter key # 3" << std::endl;
			dst = Scalar(50, 50, 50);  //调整亮度
			add(image, dst, dst);

		}
		imshow("键盘响应", dst);
	}
}

int main()
{
	Mat src = imread("D:/Image/1024.png");
	if (src.empty()) {
		printf("could not load image....");
		return -1;
	}
	imshow("输入窗口", src);

	key_demo(src);

	waitKey(0);
	return 0;
}
