#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

void key_style_demo(Mat &image)
{
	int colormap[] =
	{
		COLORMAP_AUTUMN,
		COLORMAP_BONE,
		COLORMAP_JET,
		COLORMAP_WINTER,
		COLORMAP_RAINBOW,
		COLORMAP_OCEAN,
		COLORMAP_SUMMER,
		COLORMAP_SPRING,
		COLORMAP_COOL,
		COLORMAP_HSV,
		COLORMAP_PINK,
		COLORMAP_HOT,
		COLORMAP_PARULA,
		COLORMAP_MAGMA,
		COLORMAP_INFERNO,
		COLORMAP_PLASMA,
		COLORMAP_VIRIDIS,
		COLORMAP_CIVIDIS,
		COLORMAP_TWILIGHT,
		COLORMAP_TWILIGHT_SHIFTED,
	};

	Mat dst;
	int index = 0;
	while (true) {
		int c = waitKey(500);  //等2秒后用户还没有按键反应，则waitkey函数返回-1
		if (c == 27) {
			break;
		}
		applyColorMap(image, dst, colormap[index % 19]);  //将输入图像用colormap数组里的风格渲染后再输出，当输入图像为灰度图像时，也可以为灰度图像上色
		index++;
		imshow("颜色风格", dst);
		std::cout << "you enter key # " << c << std::endl;
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

	key_style_demo(src);

	waitKey(0);
	return 0;
}
