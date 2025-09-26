#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

void channels_demo(Mat &image)
{
	std::vector<Mat>mv;
	split(image, mv);  //����ͨ��,����������mv�У�����B��G��R˳�����
	imshow("��ɫ", mv[0]);
	imshow("��ɫ", mv[1]);
	imshow("��ɫ", mv[2]);

	Mat dst;
	mv[1] = 0;
	mv[2] = 0;
	merge(mv, dst);  //�ϲ�ͨ��
	imshow("�ϲ���ɫ", dst);  //��ɫ�ͺ�ɫͨ����ֵ0����ϲ�3��ͨ��ʱֻʣ����ɫ

	int from_to[] = { 0,2,1,1,2,0 };  //����ͼ���0��ͨ�����Ƶ����ͼ���2��ͨ����1�ŵ�1�ţ�2�ŵ�0��
	mixChannels(&image, 1, &dst, 1, from_to, 3);
	//����������ͼ���ͼ�񼯣�ͼ���С��ȱ�����ͬ��������ͼ��ĸ��������ͼ���ͼ�񼯣�ͼ���С��ȱ���������ͼ����ͬ�������ͼ��ĸ�����from_to������������ͨ����Ӧ��������ͨ����from_to�е�����������
	imshow("ͨ�����", dst);
}

int main()
{
	Mat src = imread("D:/Image/1024.png");
	if (src.empty()) {
		printf("could not load image....");
		return -1;
	}
	imshow("���봰��", src);

	channels_demo(src);

	waitKey(0);
	return 0;
}

