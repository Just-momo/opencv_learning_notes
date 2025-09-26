#pragma once

#include<opencv2/opencv.hpp>

using namespace cv;

class  QuickDemo {
   public:
	 void colorSpace_Demo(Mat &image);  //ͼ��ɫ�ʿռ�ת��
	 void mat_creation_demo();  //ͼ�񴴽��븳ֵ
	 void pixel_visit_demo(Mat &image);  //ͼ�����صĶ�д����
	 void operators_demo(Mat &image);  //ͼ����������������ı�ͼ������
	 void tracking_bar_demo(Mat &image);  // ������������ʾ��������ͼ�����ȺͶԱȶ�
	 void key_demo(Mat &image);  //������Ӧ����
	 void key_style_demo(Mat &image);  //�Դ���ɫ����������ɶ��ַ���ͼ��
	 void bitwise_demo(Mat &image);  //λ������ͼ�����ص��߼�����
	 void channels_demo(Mat &image);  //ͨ��������ϲ�
	 void inRange_demo(Mat &image);  //��ֵ������Ҫ�ǽ���������ֵ�ڵ�����ֵ����Ϊ��ɫ��255������������ֵ�����ڵ�����ֵ����Ϊ��ɫ��0��
	 
};
