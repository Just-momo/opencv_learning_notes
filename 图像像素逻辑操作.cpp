#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

void bitwise_demo(Mat &image)
{
	Mat m1 = Mat::zeros(Size(256, 256), CV_8UC3);
	Mat m2 = Mat::zeros(Size(256, 256), CV_8UC3);
	//rectangle��������������ͼ��ͼ��λ�ô�С��ͼ������ֵ��ͼ��������ȣ�������Ϊ�������ͼ�񣩣������ǿ�ȣ�������С����λ��
	//Rect��������ͼ�����Ͻ�x,y���꣬ͼ���ȣ��߶ȣ�
	rectangle(m1, Rect(100, 100, 80, 80), Scalar(255, 255, 0), -1, LINE_8, 0);
	rectangle(m2, Rect(150, 150, 80, 80), Scalar(0, 255, 255), -1, LINE_8, 0);
	imshow("m1", m1);
	imshow("m2", m2);
	Mat dst;
	//���������
	//bitwise_and(m1, m2, dst);  //�����߼��룬����ͼ��Ľ�����ͼ����ɫ��ScalarҲ��������������Scalar(0,255,0)

	//���ػ����
	//bitwise_or(m1, m2, dst);

	//���طǲ���
	//bitwise_not(image,dst);

	//����������
	bitwise_xor(m1, m2, dst);

	imshow("����λ����", dst);

}


int main()
{
	Mat src = imread("D:/Image/1024.png");
	if (src.empty()) {
		printf("could not load image....");
		return -1;
	}

	imshow("���봰��", src);

	bitwise_demo(src);

	waitKey(0);
	return 0;
}
