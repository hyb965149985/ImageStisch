#include "ImageFusion.h"
#include "ImageUtility.h"
#include "Stitcher.h"

#include "time.h"
// https://zhuanlan.zhihu.com/p/71777362
int main()
{
	StitcherParam param;
	Stitcher *stitcher = Stitcher::Instance();
	vector<string> imgList;
	imgList.push_back("F:\\project\\image-cpu\\demoImages\\asd\\1\\9.1.bmp");
	imgList.push_back("F:\\project\\image-cpu\\demoImages\\asd\\1\\9.2.bmp");
	/*imgList.push_back("F:\\project\\image-cpu\\demoImages\\asd\\1\\9.3.bmp");
	imgList.push_back("F:\\project\\image-cpu\\demoImages\\asd\\1\\9.4.bmp");
	imgList.push_back("F:\\project\\image-cpu\\demoImages\\asd\\1\\9.5.bmp");
	imgList.push_back("F:\\project\\image-cpu\\demoImages\\asd\\1\\9.6.bmp");
	imgList.push_back("F:\\project\\image-cpu\\demoImages\\asd\\1\\9.7.bmp");
	imgList.push_back("F:\\project\\image-cpu\\demoImages\\asd\\1\\9.8.bmp");
	imgList.push_back("F:\\project\\image-cpu\\demoImages\\asd\\1\\9.9.bmp");*/


	//vector<cv::Mat> imgs;
	//imgs.push_back(cv::imread(imgList[0]));
	//imgs.push_back(cv::imread(imgList[1]));
	//imgs.push_back(cv::imread(imgList[2]));
	//cv::Mat pano;
	//cv::Stitcher ssstitcher = cv::Stitcher::createDefault(false);
	//cv::Stitcher::Status status = ssstitcher.stitch(imgs, pano);//拼接  
	//if (status != cv::Stitcher::OK) //判断拼接是否成功  
	//{
	//	cout << "Can't stitch images, error code = " << int(status) << endl;
	//	return -1;
	//}
	//cv::namedWindow("全景拼接", 0);
	//cv::imshow("全景拼接", pano);
	clock_t start, finish;
	start = clock();
	stitcher->flowStitch(param,imgList, "xxx");
	finish = clock();
	printf("time= %f \n", (double)(finish - start)/ CLOCKS_PER_SEC);
	system("pause");
	return 0;
}