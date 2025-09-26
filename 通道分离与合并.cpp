#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

void channels_demo(Mat &image)
{
	std::vector<Mat>mv;
	split(image, mv);  //分离通道,储存在容器mv中，按照B、G、R顺序分离
	imshow("蓝色", mv[0]);
	imshow("绿色", mv[1]);
	imshow("红色", mv[2]);

	Mat dst;
	mv[1] = 0;
	mv[2] = 0;
	merge(mv, dst);  //合并通道
	imshow("合并蓝色", dst);  //绿色和红色通道赋值0，则合并3个通道时只剩下蓝色

	int from_to[] = { 0,2,1,1,2,0 };  //输入图像的0号通道复制到输出图像的2号通道，1号到1号，2号到0号
	mixChannels(&image, 1, &dst, 1, from_to, 3);
	//参数：输入图像或图像集（图像大小深度必须相同）；输入图像的个数；输出图像或图像集（图像大小深度必须与输入图像相同）；输出图像的个数；from_to设置输入矩阵的通道对应输出矩阵的通道；from_to中的索引对数）
	imshow("通道混合", dst);
}

int main()
{
	Mat src = imread("D:/Image/1024.png");
	if (src.empty()) {
		printf("could not load image....");
		return -1;
	}
	imshow("输入窗口", src);

	channels_demo(src);

	waitKey(0);
	return 0;
}

