#include<quickopencv.h>


//ɫ�ʿռ�ת��������cv_Color
//COLOR_BGR2GRAY = 6 ��ɫ���Ҷȣ�
//COLOR_GRAY2BGR = 8 �Ҷȵ���ɫ��
//COLOR_BGR2HSV = 40 BGR��HSV;
//COLOR_HSV2BGR = 54 HSV��BGR;

//ͼ�񱣴棺imwrite:
//��һ������Ϊͼ�񱣴��λ�ã��ڶ���������ͼ���ڴ����

void QuickDemo::colorSpace_Demo(Mat &image) {
	Mat gray, hsv;
	cvtColor(image, hsv, COLOR_BGR2HSV);
	//H(ɫ��)S(���Ͷ�)V(����)��ͨ����HΪ0~180��S,V��Ϊ0~255��
	cvtColor(image, gray, COLOR_BGR2GRAY);
	imshow("HSV", hsv);
	imshow("�Ҷ�", gray);
	imwrite("D:/hsv.png", hsv);    //��һ������Ϊͼ�񱣴��λ�ã��ڶ���������ͼ���ڴ����
	imwrite("D:/gray.png", gray);






}