#include<quickopencv.h>


//色彩空间转换函数：cv_Color
//COLOR_BGR2GRAY = 6 彩色到灰度；
//COLOR_GRAY2BGR = 8 灰度到彩色；
//COLOR_BGR2HSV = 40 BGR到HSV;
//COLOR_HSV2BGR = 54 HSV到BGR;

//图像保存：imwrite:
//第一个参数为图像保存的位置，第二个参数是图像内存对象；

void QuickDemo::colorSpace_Demo(Mat &image) {
	Mat gray, hsv;
	cvtColor(image, hsv, COLOR_BGR2HSV);
	//H(色调)S(饱和度)V(亮度)三通道，H为0~180，S,V均为0~255，
	cvtColor(image, gray, COLOR_BGR2GRAY);
	imshow("HSV", hsv);
	imshow("灰度", gray);
	imwrite("D:/hsv.png", hsv);    //第一个参数为图像保存的位置，第二个参数是图像内存对象；
	imwrite("D:/gray.png", gray);

}

//1.怎么操作它 2.怎么访问每一个像素点 3.怎么创建一个空图或Mat

void QuickDemo::mat_creation_demo() {
	//Mat m1, m2;
	//m1 = image.clone();
	//image.copyTo(m2);

	//一、创建空白图像，常用ones和zeros初始化
	Mat m3 = Mat::zeros(Size(300, 300), CV_8UC3);  //8位无符号字符，1为单通道，每个像素点有1个数据，若为3则是三通道，每个像素点有3个数据
	//Mat m3 = Mat::ones(Size(8, 8), CV_8UC3);  //oens初始化，多通道时，只在第一个通道显示为1，其余默认为0，方便观察像素点个数和起始位置

	//二、给通道赋值
	//m3 = 127;
	m3 = Scalar(0, 0, 255);  //RGB三通道赋值，得到想要颜色的图像

	//获取图像的尺寸信息，图像的实际宽度是初始宽度*通道数
	std::cout << "width:" << m3.cols << std::endl;  //获取图像的宽度（单通道）
	std::cout << "height:" << m3.rows << std::endl;  //获取图像的高度
	std::cout << "channels:" << m3.channels()<< std::endl;  //获取图像的通道数
	std::cout << m3 << std::endl;

	//直接赋值
	//Mat m4 = m3;   //将m3赋给m4,当m4改变时，m3也改变
	//m4 = Scalar(0, 255, 255);
	//imshow("图像", m3);

	//克隆赋值
	//Mat m4 = m3.clone();   //将m3克隆给m4,当m4改变时，m3不会变
	//m4 = Scalar(0, 255, 255);
	//imshow("图像3", m3);
	//imshow("图像4", m4);

	//拷贝赋值
	Mat m4;    
	m3.copyTo(m4);  //将m3拷贝给m4,当m4改变时，m3不会变
	m4 = Scalar(0, 255, 255);
	imshow("图像3", m3);
	imshow("图像4", m4);
}

void QuickDemo::pixel_visit_demo(Mat &image) 
{
	int w = image.cols;
	int h = image.rows;
	int dims = image.channels();

	//数组方式读写
	/*
	for (int row = 0; row < h; row++)
	{
		for (int col = 0; col < w; col++) 
		{
			if (dims == 1) //单通道，灰度图像，每一个像素值是字节类型uchar
			{    
			int pv = image.at<uchar>(row, col);  //获取当前像素值，在0-255之间
				image.at<uchar>(row, col) = 255 - pv;  //改变当前的像素值（取反）
			}
			if (dims == 3)   //三通道，彩色图像
			{
				Vec3b bgr = image.at<Vec3b>(row, col);  //3通道则一个像素点有三个值，Vec3b可以一次性获取3个值
				image.at<Vec3b>(row, col)[0] = 255 - bgr[0];
				image.at<Vec3b>(row, col)[1] = 255 - bgr[1];
			image.at<Vec3b>(row, col)[2] = 255 - bgr[2];

			}
		}
	}
	*/
	//imshow("像素读写演示",image);

	//指针方式读写
	for (int row = 0; row < h; row++)
	{
		uchar*current_row = image.ptr<uchar>(row);  //ptr获取行指针的一个函数。row为1，则获取第一行所有值的地址？
		for (int col = 0; col < w; col++)
		{
			if (dims == 1) //单通道，灰度图像，每一个像素值是字节类型uchar
			{
				int pv = *current_row;  //获取该列当前这行的像素值
				*current_row++ = 255 - pv;  //改变当前这行的像素值（取反），然后当前这行的地址++
			}
			if (dims == 3)   //三通道，彩色图像
			{
				*current_row++ = 255 - *current_row;
				*current_row++ = 255 - *current_row;
				*current_row++ = 255 - *current_row;
			}
		}
	}
	imshow("像素读写演示", image);
}

void QuickDemo::operators_demo(Mat &image) 
{
	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type()); //创建一个大小和类型与图像image一致的空图像m
	m = Scalar(5, 5, 5);
	//multiply(image, m, dst);  //两个图像相乘的函数，第一个参数为输入图像，第二个相乘的图像，第三个输出图像
	//dst = image*2;  //也可以直接输入图像乘一个数，若超出255就截断为255，

	//加法运算
	/*int w = image.cols;
	int h = image.rows;
	int dims = image.channels();

	for (int row = 0; row < h; row++)
	{
		for (int col = 0; col < w; col++)
		{
			Vec3b p1 = image.at<Vec3b>(row, col);  //3通道则一个像素点有三个值，Vec3b可以一次性获取3个值
			Vec3b p2 = m.at<Vec3b>(row, col);
			dst.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(p1[0] + p2[0]); //saturate_cast函数防止溢出，运算结果为负，则转为0，结果超出255，则为255
			dst.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(p1[1] + p2[1]);
			dst.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(p1[2] + p2[2]);
		}
	}
	*/
	//直接调用api
	//add(image, m, dst);
	//subtract(image, m, dst);
	divide(image, m, dst);
	imshow("加法操作", dst);
}


static void on_lightness(int b, void* userdata) {
	Mat image = *((Mat*)userdata);  //强制类型转换，createTrackbar将&image（指针）传进userdata，其为任意类型，强制转换为Mat类型，解引用得到值image
	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type());
	//调对比度时不用这句m = Scalar(b, b, b);  //形参b由createTrackbar中的lightness引用传递，b即为lightness
	//subtract(image, m, dst);  //两张图相减，实现亮度调节
	addWeighted(image, 1.0, m, 0, b, dst);  //addWeighted主要公式为:dst = src1 * alpha + src2 * beta + gamma
	imshow("亮度与对比度调整", dst);

}

static void on_contrast(int b, void* userdata) {
	Mat image = *((Mat*)userdata);  //强制类型转换，createTrackbar将&image（指针）传进userdata，其为任意类型，强制转换为Mat类型，解引用得到值image
	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type());
	double contrast = b / 100.0;
	//addWeighted函数，可以调整两张图像的比例来输出一个混合的图像
	addWeighted(image, contrast, m, 0.0, 0, dst);  //这里输出dst=imagecontrast+0+0,即只调整对比度
	imshow("亮度与对比度调整", dst);

}

void QuickDemo::tracking_bar_demo(Mat &image)
{
	namedWindow("亮度与对比度调整", WINDOW_AUTOSIZE);  //图像不大的时候可以用自动大小
	int lightness = 50 ;  //当前亮度值
	int max_value = 100;  //最大亮度值
	int contrast_value = 100;
	createTrackbar("Value Bar:", "亮度与对比度调整", &lightness, max_value, on_lightness, &image);
	createTrackbar("Contrast Bar:", "亮度与对比度调整", &contrast_value, 200, on_contrast, &image);
	/*createTrackbar函数各参数为：1滚动条名称；2滚动条所在的窗口名称；3滑块初始值位置以及后面所在的位置；4改变的最大值（最小值不用写，默认为0）；
	5滚动条回调函数，拖动滚动条后，系统调用该函数来实时调整lightness的值，取地址故用&；6可以外带的任意类型的数据，也可以不用
	*/
}


void QuickDemo::key_demo(Mat &image)
{
	Mat dst = Mat::zeros(image.size(), image.type());
	while (true) {
		int c = waitKey(100);
		if (c == 27) {  //按Esc退出循环
			break;
		}
		if (c == 49) {  //key = 1
			std::cout << "you enter key # 1" << std::endl;
			cvtColor(image, dst, COLOR_BGR2GRAY);  //灰度转换
		
		}
		if (c == 50) {  //key = 2
			std::cout << "you enter key # 2" << std::endl;
			cvtColor(image, dst, COLOR_BGR2HSV);  //HSV转换

		}
		if (c == 51) {  //key = 3
			std::cout << "you enter key # 3"<< std::endl;
			dst = Scalar(50, 50, 50);  //调整亮度
			add(image, dst, dst);

		}
			imshow("键盘响应",dst);
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
		int c = waitKey(500);  //等2秒后用户还没有按键反应，则waitkey函数返回-1
		if (c == 27) {
			break;
		}
		applyColorMap(image, dst, colormap[index % 19]);  //将输入图像用colormap数组里的风格渲染后再输出，当输入图像为灰度图像时，也可以为灰度图像上色
		index++;
		imshow("颜色风格", dst);
		std::cout << "you enter key # " << c << std::endl;
	}
}

void QuickDemo::bitwise_demo(Mat &image)
{
	Mat m1 = Mat::zeros(Size(256, 256), CV_8UC3);
	Mat m2 = Mat::zeros(Size(256, 256), CV_8UC3);
	//rectangle函数参数：输入图像，图像位置大小，图像像素值，图像线条厚度（负数则为填充整个图像），抗锯齿强度，坐标点的小数点位数
	//Rect函数：（图像左上角x,y坐标，图像宽度，高度）
	rectangle(m1, Rect(100, 100, 80, 80), Scalar(255, 255, 0), -1, LINE_8, 0);
	rectangle(m2, Rect(150, 150, 80, 80), Scalar(0, 255,255), -1, LINE_8, 0);
	imshow("m1", m1);
	imshow("m2", m2);
	Mat dst;
	//像素与操作
	//bitwise_and(m1, m2, dst);  //像素逻辑与，求两图像的交集，图像颜色由Scalar也进行与操作，输出Scalar(0,255,0)
	
	//像素或操作
	//bitwise_or(m1, m2, dst);
	
	//像素非操作
	//bitwise_not(image,dst);

	//像素异或操作
	bitwise_xor(m1,m2,dst);

	imshow("像素位操作",dst);

	}

void QuickDemo::channels_demo(Mat &image)
{
	std::vector<Mat>mv;
	split(image, mv);  //分离通道,储存在容器mv中，按照B、G、R顺序分离
	imshow("蓝色", mv[0]);
	imshow("绿色", mv[1]);
	imshow("红色", mv[2]);
	
	Mat dst;
	mv[1] = 0;
	mv[2] = 0;
	merge(mv, dst);  //合并通道
	imshow("合并蓝色", dst);  //绿色和红色通道赋值0，则合并3个通道时只剩下蓝色

	int from_to[] = { 0,2,1,1,2,0 };  //输入图像的0号通道复制到输出图像的2号通道，1号到1号，2号到0号
	mixChannels(&image, 1, &dst, 1, from_to, 3);  
	//参数：输入图像或图像集（图像大小深度必须相同）；输入图像的个数；输出图像或图像集（图像大小深度必须与输入图像相同）；输出图像的个数；from_to设置输入矩阵的通道对应输出矩阵的通道；from_to中的索引对数）
	imshow("通道混合", dst);
}

void QuickDemo::inRange_demo(Mat &image) 
{
	Mat hsv;
	cvtColor(image, hsv, COLOR_BGR2HSV);
	Mat mask;  //mask也成为掩码图
	//二值化，inrange函数将阈值内的像素值设为白色255，阈值外像素值设为黑色0
	inRange(hsv, Scalar(35, 43, 46), Scalar(77, 255, 255), mask); //扣绿幕：输入图像；hsv表中绿色像素的下限；hsv表中绿色像素的上限；输出图像
	imshow("mask", mask);

	Mat redback = Mat::zeros(image.size(), image.type());
	redback = Scalar(40, 40, 200);  //创建一个纯红色图像作为背景
	bitwise_not(mask, mask);  //mask掩码图取反，保证背景为黑色0,
	imshow("mask", mask);
	image.copyTo(redback, mask);  //把输入图像image复制到redback上，并且输入图像对应掩码mask中像素值为0的点不会复制到redback上（mask图中背景为黑色，即原图背景不复制，仅复制人像）
	imshow("roi区域提取", redback);


}