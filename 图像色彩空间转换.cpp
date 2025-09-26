#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

void colorSpace_Demo(Mat &image) {
	Mat gray, hsv;
	cvtColor(image, hsv, COLOR_BGR2HSV);
	//H(ɫ��)S(���Ͷ�)V(����)��ͨ����HΪ0~180��S,V��Ϊ0~255��
	cvtColor(image, gray, COLOR_BGR2GRAY);
	imshow("HSV", hsv);
	imshow("�Ҷ�", gray);
	imwrite("D:/hsv.png", hsv);    //��һ������Ϊͼ�񱣴��λ�ã��ڶ���������ͼ���ڴ����
	imwrite("D:/gray.png", gray);

	//ɫ�ʿռ�ת��������cv_Color
	//COLOR_BGR2GRAY = 6 ��ɫ���Ҷȣ�
	//COLOR_GRAY2BGR = 8 �Ҷȵ���ɫ��
	//COLOR_BGR2HSV = 40 BGR��HSV;
	//COLOR_HSV2BGR = 54 HSV��BGR;
	//ͼ�񱣴棺imwrite:
	//��һ������Ϊͼ�񱣴��λ�ã��ڶ���������ͼ���ڴ����

	}

int main()
{
	Mat src = imread("D:/Image/1024.png"); 
	if (src.empty()) {
		printf("could not load image....");
		return -1;
	}

	imshow("���봰��", src);

	 colorSpace_Demo(src);

	waitKey(0);
	return 0;
}