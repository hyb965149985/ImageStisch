#pragma once

#include <string.h>
#include <vector>
#include <iostream>

#include "Stitcher.h"
//#include <opencv2/opencv.hpp>
//#include <opencv2/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/core/types_c.h>

using namespace std;
//特征点算子
enum FeatureMethod {  SIFT=0, SURF, FAST};

class _declspec(dllexport) SplicingMethod
{
public:

	SplicingMethod(int featureMethod);
	cv::Mat getROIRegion(cv::Mat image, int direction, string order, float searchRatio);

	void detectAndDescribe(cv::Mat roiImage, vector<cv::KeyPoint> &keyPoint, cv::Mat &imageDesc);
	vector<std::pair<int, int> > matchDescriptors(cv::Mat imageDescA, cv::Mat imageDescB);
	cv::Point2i getOffsetByMode(vector<cv::KeyPoint> keyPoint1, vector<cv::KeyPoint> keyPoint2, vector<std::pair<int, int> > matches, bool &status, int offsetEvaluate=10);
private:
	int featureMethod;//特征点提取方法

};