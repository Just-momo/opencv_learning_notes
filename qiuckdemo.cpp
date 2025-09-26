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

//1.��ô������ 2.��ô����ÿһ�����ص� 3.��ô����һ����ͼ��Mat

void QuickDemo::mat_creation_demo() {
	//Mat m1, m2;
	//m1 = image.clone();
	//image.copyTo(m2);

	//һ�������հ�ͼ�񣬳���ones��zeros��ʼ��
	Mat m3 = Mat::zeros(Size(300, 300), CV_8UC3);  //8λ�޷����ַ���1Ϊ��ͨ����ÿ�����ص���1�����ݣ���Ϊ3������ͨ����ÿ�����ص���3������
	//Mat m3 = Mat::ones(Size(8, 8), CV_8UC3);  //oens��ʼ������ͨ��ʱ��ֻ�ڵ�һ��ͨ����ʾΪ1������Ĭ��Ϊ0������۲����ص��������ʼλ��

	//������ͨ����ֵ
	//m3 = 127;
	m3 = Scalar(0, 0, 255);  //RGB��ͨ����ֵ���õ���Ҫ��ɫ��ͼ��

	//��ȡͼ��ĳߴ���Ϣ��ͼ���ʵ�ʿ���ǳ�ʼ���*ͨ����
	std::cout << "width:" << m3.cols << std::endl;  //��ȡͼ��Ŀ�ȣ���ͨ����
	std::cout << "height:" << m3.rows << std::endl;  //��ȡͼ��ĸ߶�
	std::cout << "channels:" << m3.channels()<< std::endl;  //��ȡͼ���ͨ����
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

void QuickDemo::pixel_visit_demo(Mat &image) 
{
	int w = image.cols;
	int h = image.rows;
	int dims = image.channels();

	//���鷽ʽ��д
	/*
	for (int row = 0; row < h; row++)
	{
		for (int col = 0; col < w; col++) 
		{
			if (dims == 1) //��ͨ�����Ҷ�ͼ��ÿһ������ֵ���ֽ�����uchar
			{    
			int pv = image.at<uchar>(row, col);  //��ȡ��ǰ����ֵ����0-255֮��
				image.at<uchar>(row, col) = 255 - pv;  //�ı䵱ǰ������ֵ��ȡ����
			}
			if (dims == 3)   //��ͨ������ɫͼ��
			{
				Vec3b bgr = image.at<Vec3b>(row, col);  //3ͨ����һ�����ص�������ֵ��Vec3b����һ���Ի�ȡ3��ֵ
				image.at<Vec3b>(row, col)[0] = 255 - bgr[0];
				image.at<Vec3b>(row, col)[1] = 255 - bgr[1];
			image.at<Vec3b>(row, col)[2] = 255 - bgr[2];

			}
		}
	}
	*/
	//imshow("���ض�д��ʾ",image);

	//ָ�뷽ʽ��д
	for (int row = 0; row < h; row++)
	{
		uchar*current_row = image.ptr<uchar>(row);  //ptr��ȡ��ָ���һ��������rowΪ1�����ȡ��һ������ֵ�ĵ�ַ��
		for (int col = 0; col < w; col++)
		{
			if (dims == 1) //��ͨ�����Ҷ�ͼ��ÿһ������ֵ���ֽ�����uchar
			{
				int pv = *current_row;  //��ȡ���е�ǰ���е�����ֵ
				*current_row++ = 255 - pv;  //�ı䵱ǰ���е�����ֵ��ȡ������Ȼ��ǰ���еĵ�ַ++
			}
			if (dims == 3)   //��ͨ������ɫͼ��
			{
				*current_row++ = 255 - *current_row;
				*current_row++ = 255 - *current_row;
				*current_row++ = 255 - *current_row;
			}
		}
	}
	imshow("���ض�д��ʾ", image);
}

void QuickDemo::operators_demo(Mat &image) 
{
	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type()); //����һ����С��������ͼ��imageһ�µĿ�ͼ��m
	m = Scalar(5, 5, 5);
	//multiply(image, m, dst);  //����ͼ����˵ĺ�������һ������Ϊ����ͼ�񣬵ڶ�����˵�ͼ�񣬵��������ͼ��
	//dst = image*2;  //Ҳ����ֱ������ͼ���һ������������255�ͽض�Ϊ255��

	//�ӷ�����
	/*int w = image.cols;
	int h = image.rows;
	int dims = image.channels();

	for (int row = 0; row < h; row++)
	{
		for (int col = 0; col < w; col++)
		{
			Vec3b p1 = image.at<Vec3b>(row, col);  //3ͨ����һ�����ص�������ֵ��Vec3b����һ���Ի�ȡ3��ֵ
			Vec3b p2 = m.at<Vec3b>(row, col);
			dst.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(p1[0] + p2[0]); //saturate_cast������ֹ�����������Ϊ������תΪ0���������255����Ϊ255
			dst.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(p1[1] + p2[1]);
			dst.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(p1[2] + p2[2]);
		}
	}
	*/
	//ֱ�ӵ���api
	//add(image, m, dst);
	//subtract(image, m, dst);
	divide(image, m, dst);
	imshow("�ӷ�����", dst);
}


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

void QuickDemo::tracking_bar_demo(Mat &image)
{
	namedWindow("������Աȶȵ���", WINDOW_AUTOSIZE);  //ͼ�񲻴��ʱ��������Զ���С
	int lightness = 50 ;  //��ǰ����ֵ
	int max_value = 100;  //�������ֵ
	int contrast_value = 100;
	createTrackbar("Value Bar:", "������Աȶȵ���", &lightness, max_value, on_lightness, &image);
	createTrackbar("Contrast Bar:", "������Աȶȵ���", &contrast_value, 200, on_contrast, &image);
	/*createTrackbar����������Ϊ��1���������ƣ�2���������ڵĴ������ƣ�3�����ʼֵλ���Լ��������ڵ�λ�ã�4�ı�����ֵ����Сֵ����д��Ĭ��Ϊ0����
	5�������ص��������϶���������ϵͳ���øú�����ʵʱ����lightness��ֵ��ȡ��ַ����&��6����������������͵����ݣ�Ҳ���Բ���
	*/
}


void QuickDemo::key_demo(Mat &image)
{
	Mat dst = Mat::zeros(image.size(), image.type());
	while (true) {
		int c = waitKey(100);
		if (c == 27) {  //��Esc�˳�ѭ��
			break;
		}
		if (c == 49) {  //key = 1
			std::cout << "you enter key # 1" << std::endl;
			cvtColor(image, dst, COLOR_BGR2GRAY);  //�Ҷ�ת��
		
		}
		if (c == 50) {  //key = 2
			std::cout << "you enter key # 2" << std::endl;
			cvtColor(image, dst, COLOR_BGR2HSV);  //HSVת��

		}
		if (c == 51) {  //key = 3
			std::cout << "you enter key # 3"<< std::endl;
			dst = Scalar(50, 50, 50);  //��������
			add(image, dst, dst);

		}
			imshow("������Ӧ",dst);
	}
}

void QuickDemo::key_style_demo(Mat &image)
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

void QuickDemo::bitwise_demo(Mat &image)
{
	Mat m1 = Mat::zeros(Size(256, 256), CV_8UC3);
	Mat m2 = Mat::zeros(Size(256, 256), CV_8UC3);
	//rectangle��������������ͼ��ͼ��λ�ô�С��ͼ������ֵ��ͼ��������ȣ�������Ϊ�������ͼ�񣩣������ǿ�ȣ�������С����λ��
	//Rect��������ͼ�����Ͻ�x,y���꣬ͼ���ȣ��߶ȣ�
	rectangle(m1, Rect(100, 100, 80, 80), Scalar(255, 255, 0), -1, LINE_8, 0);
	rectangle(m2, Rect(150, 150, 80, 80), Scalar(0, 255,255), -1, LINE_8, 0);
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
	bitwise_xor(m1,m2,dst);

	imshow("����λ����",dst);

	}

void QuickDemo::channels_demo(Mat &image)
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

void QuickDemo::inRange_demo(Mat &image) 
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