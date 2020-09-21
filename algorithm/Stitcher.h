#pragma once




#include <string.h>
#include <vector>
#include <iostream>
#include <time.h>


#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/types_c.h>

#include "opencv2/stitching/detail/autocalib.hpp"
#include "opencv2/stitching/detail/blenders.hpp"
#include "opencv2/stitching/detail/timelapsers.hpp"
#include "opencv2/stitching/detail/camera.hpp"
#include "opencv2/stitching/detail/exposure_compensate.hpp"
#include "opencv2/stitching/detail/matchers.hpp"
#include "opencv2/stitching/detail/motion_estimators.hpp"
#include "opencv2/stitching/detail/seam_finders.hpp"
#include "opencv2/stitching/detail/warpers.hpp"
#include "opencv2/stitching/warpers.hpp"

#include "opencv2/core.hpp"  
#include "opencv2/core/utility.hpp"  
#include "opencv2/core/ocl.hpp"  
#include "opencv2/imgcodecs.hpp"  
#include "opencv2/highgui.hpp"  
#include "opencv2/features2d.hpp"  
#include "opencv2/calib3d.hpp"  
#include "opencv2/imgproc.hpp"   
#include "opencv2/ml.hpp"

#include "opencv2/xfeatures2d.hpp"

class SplicingMethod;
class ImageFuse;
class YLog;
//#include "opencv2/xfeatures2d.hpp"

using namespace std;
//using namespace cv;

struct ImageData {
	cv::Mat Timg;
	bool status;
	//uchar* data;
	//cv::MatStep step;
	//int width;
	//int height;
};

struct StitcherParam
{
	int method, GPU_enabled, Enhance_enabled, Bright_enabled, featureMethod, fuseMethod;
	float roiRatio;
	string outputfileExtension, outputName;
};

//拼接顺序
enum Method1 { Free = 0, UpDown, LeftRignt };
//融合方法
enum FusionMethod { NotFuse = 0,  Minmux, Maxmux, Average, FadeInAndFadeOut};


class __declspec(dllexport) Stitcher
{
public:

	static Stitcher * Instance();
	ImageData* flowStitch(StitcherParam param, vector<string> fileList, string caculateOffsetMethod);

private:
	explicit Stitcher();
	explicit Stitcher(float roiRatio, string outputName, string outputfileExtension, int method, int splicingmethod, int fuseMethod);
	explicit Stitcher(StitcherParam param);
	~Stitcher();
	// 禁止外部拷贝和赋值操作
	Stitcher(const Stitcher &);
	const Stitcher &operator=(const Stitcher &);


	int directionIncrease(int direction, int method);

	void GetValue(StitcherParam param);

	void calculateOffsetForFeatureSearchIncre(cv::Mat imageA, cv::Mat imageB, int* offset, bool& staus);

	cv::Mat getStitchByOffset(vector<string> fileList, vector<int> offsetList);

	void StitchResult(cv::Mat &ResultMat, vector<cv::Mat> imgList, vector<int> FinalOffset);

	int direction;
	//int fuseMethod;

	float roiRatio; //增长半径
	int method;   //拼接顺序
	int fuseMethod; //融合方法
	//int featureMethod;  //特征点提取方法

	string outputName; //输出图片路径
	
	string outputfileExtension; //输出图片格式

	SplicingMethod *spm;

	ImageFuse *imf;

	string log;
	YLog *clog; 

	


	int directionList[3] = {2,1,2};


	static Stitcher *_instance;

};