#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

void inRange_demo(Mat &image)
{
	Mat hsv;
	cvtColor(image, hsv, COLOR_BGR2HSV);
	Mat mask;  //maskҲ��Ϊ����ͼ
	//��ֵ����inrange��������ֵ�ڵ�����ֵ��Ϊ��ɫ255����ֵ������ֵ��Ϊ��ɫ0
	inRange(hsv, Scalar(35, 43, 46), Scalar(77, 255, 255), mask); //����Ļ������ͼ��hsv������ɫ���ص����ޣ�hsv������ɫ���ص����ޣ����ͼ��
	imshow("mask", mask);

	Mat redback = Mat::zeros(image.size(), image.type());
	redback = Scalar(40, 40, 200);  //����һ������ɫͼ����Ϊ����
	bitwise_not(mask, mask);  //mask����ͼȡ������֤����Ϊ��ɫ0,
	imshow("mask", mask);
	image.copyTo(redback, mask);  //������ͼ��image���Ƶ�redback�ϣ���������ͼ���Ӧ����mask������ֵΪ0�ĵ㲻�Ḵ�Ƶ�redback�ϣ�maskͼ�б���Ϊ��ɫ����ԭͼ���������ƣ�����������
	imshow("roi������ȡ", redback);

}
int main()
{
	Mat src = imread("D:/Image/green.png");
	if (src.empty()) {
		printf("could not load image....");
		return -1;
	}
	imshow("���봰��", src);

	inRange_demo(src);

	waitKey(0);
	return 0;
}
