#include<opencv2/opencv.hpp>
#include<quickopencv.h>
#include<iostream>

using namespace cv;
using namespace std;

//ͼ��Ķ�ȡ����ʾ

int main(int argc, char**argv) 
{
	// ͼ��Ļ���֪ʶ��IMREAD_GRAYSCALE����ͼ��Ҷ�չʾ��IMREAD_UNCHANGED�����ı�ͼ���ͨ������͸��ͨ��Ҳ������ʾ��IMREAD_ANYCOLOR��ʾ�����ʽ��ͼ���縡����ͼ��IMREAD_ANYDEPTH��8λ��16λ,32λ�ȵ�ͼ�񶼿�����ʾ��
	Mat src = imread("D:/Image/green.png");  //B,G,R��ͨ����ȡֵ��Χ����0~255��͸��ͨ��Ҳ��0~255
	if (src.empty()) {
		printf("could not load image....");
		return -1;
	}
	//namedWindow("���봰��", WINDOW_FREERATIO);  //����һ�����ڣ���ͼ�����ͨ���˴���������ʾͼ��
	//namedWindow�������ɱ�������ʱ��imshow�ı�����Ҫ��namedWindowһ��

	imshow("���봰��", src);   //��һ������Ϊ�������ƣ�srcΪ��ͼ�����������
	//imshowֻ��չʾ8λ��ͼƬ��������ʽ���ܻ�����⣬��չʾ��ȫ��

	waitKey(0);//��ϳ���ִ�У�����0��ʾһֱ��ϣ�����1��Ϊ���1����
	return 0;
}