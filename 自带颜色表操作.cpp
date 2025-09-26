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
		int c = waitKey(500);  //��2����û���û�а�����Ӧ����waitkey��������-1
		if (c == 27) {
			break;
		}
		applyColorMap(image, dst, colormap[index % 19]);  //������ͼ����colormap������ķ����Ⱦ���������������ͼ��Ϊ�Ҷ�ͼ��ʱ��Ҳ����Ϊ�Ҷ�ͼ����ɫ
		index++;
		imshow("��ɫ���", dst);
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

	imshow("���봰��", src);

	key_style_demo(src);

	waitKey(0);
	return 0;
}
