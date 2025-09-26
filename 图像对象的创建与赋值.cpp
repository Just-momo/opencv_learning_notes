#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

//1.��ô������ 2.��ô����ÿһ�����ص� 3.��ô����һ����ͼ��Mat

void mat_creation_demo() {
	//Mat m1, m2;
	//m1 = image.clone();
	//image.copyTo(m2);

	//һ�������հ�ͼ�񣬳���ones��zeros��ʼ��
	Mat m3 = Mat::zeros(Size(150, 150), CV_8UC3);  //8λ�޷����ַ���1Ϊ��ͨ����ÿ�����ص���1�����ݣ���Ϊ3������ͨ����ÿ�����ص���3������
	//Mat m3 = Mat::ones(Size(8, 8), CV_8UC3);  //oens��ʼ������ͨ��ʱ��ֻ�ڵ�һ��ͨ����ʾΪ1������Ĭ��Ϊ0������۲����ص��������ʼλ��

	//������ͨ����ֵ
	//m3 = 127;
	m3 = Scalar(0, 0, 255);  //RGB��ͨ����ֵ���õ���Ҫ��ɫ��ͼ��

	//��ȡͼ��ĳߴ���Ϣ��ͼ���ʵ�ʿ���ǳ�ʼ���*ͨ����
	std::cout << "width:" << m3.cols << std::endl;  //��ȡͼ��Ŀ�ȣ���ͨ����
	std::cout << "height:" << m3.rows << std::endl;  //��ȡͼ��ĸ߶�
	std::cout << "channels:" << m3.channels() << std::endl;  //��ȡͼ���ͨ����
	std::cout << m3 << std::endl;

	//ֱ�Ӹ�ֵ
	//Mat m4 = m3;   //��m3����m4,��m4�ı�ʱ��m3Ҳ�ı�
	//m4 = Scalar(0, 255, 255);
	//imshow("ͼ��", m3);

	//��¡��ֵ
	//Mat m4 = m3.clone();   //��m3��¡��m4,��m4�ı�ʱ��m3�����
	//m4 = Scalar(0, 255, 255);
	//imshow("ͼ��3", m3);
	//imshow("ͼ��4", m4);

	//������ֵ
	Mat m4;
	m3.copyTo(m4);  //��m3������m4,��m4�ı�ʱ��m3�����
	m4 = Scalar(0, 255, 255);
	imshow("ͼ��3", m3);
	imshow("ͼ��4", m4);
}

int main()
{
	Mat src = imread("D:/Image/1024.png");
	if (src.empty()) {
		printf("could not load image....");
		return -1;
	}

	imshow("���봰��", src);

	mat_creation_demo();

	waitKey(0);
	return 0;
}