#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

static void on_lightness(int b, void* userdata) {
	Mat image = *((Mat*)userdata);  //ǿ������ת����createTrackbar��&image��ָ�룩����userdata����Ϊ�������ͣ�ǿ��ת��ΪMat���ͣ������õõ�ֵimage
	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type());
	//���Աȶ�ʱ�������m = Scalar(b, b, b);  //�β�b��createTrackbar�е�lightness���ô��ݣ�b��Ϊlightness
	//subtract(image, m, dst);  //����ͼ�����ʵ�����ȵ���
	addWeighted(image, 1.0, m, 0, b, dst);  //addWeighted��Ҫ��ʽΪ:dst = src1 * alpha + src2 * beta + gamma
	imshow("������Աȶȵ���", dst);

}

static void on_contrast(int b, void* userdata) {
	Mat image = *((Mat*)userdata);  //ǿ������ת����createTrackbar��&image��ָ�룩����userdata����Ϊ�������ͣ�ǿ��ת��ΪMat���ͣ������õõ�ֵimage
	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type());
	double contrast = b / 100.0;
	//addWeighted���������Ե�������ͼ��ı��������һ����ϵ�ͼ��
	addWeighted(image, contrast, m, 0.0, 0, dst);  //�������dst=imagecontrast+0+0,��ֻ�����Աȶ�
	imshow("������Աȶȵ���", dst);

}

void tracking_bar_demo(Mat &image)
{
	namedWindow("������Աȶȵ���", WINDOW_AUTOSIZE);  //ͼ�񲻴��ʱ��������Զ���С
	int lightness = 50;  //��ǰ����ֵ
	int max_value = 100;  //�������ֵ
	int contrast_value = 100;
	createTrackbar("lightness Bar:", "������Աȶȵ���", &lightness, max_value, on_lightness, &image);
	createTrackbar("Contrast Bar:", "������Աȶȵ���", &contrast_value, 200, on_contrast, &image);
	/*createTrackbar����������Ϊ��1���������ƣ�2���������ڵĴ������ƣ�3�����ʼֵλ���Լ��������ڵ�λ�ã�4�ı�����ֵ����Сֵ����д��Ĭ��Ϊ0����
	5�������ص��������϶���������ϵͳ���øú�����ʵʱ����lightness��ֵ��ȡ��ַ����&��6����������������͵����ݣ�Ҳ���Բ���
	*/
}

int main()
{
	Mat src = imread("D:/Image/1024.png");
	if (src.empty()) {
		printf("could not load image....");
		return -1;
	}
	imshow("���봰��", src);

	tracking_bar_demo(src);

	waitKey(0);
	return 0;
}
