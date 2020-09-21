#pragma once


#include "ImageUtility.h"

#include <string.h>
#include <vector>
#include <iostream>

//#include <opencv2/opencv.hpp>
//#include <opencv2/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/core/types_c.h>

using namespace std;

class _declspec(dllexport) ImageFuse
{
public:
	ImageFuse();

	cv::Mat fuseByNotFuse(cv::Mat ResultMat, vector<cv::Mat> imgList, vector<int> FinalOffset);
	cv::Mat fuseByAverage(cv::Mat ResultMat, vector<cv::Mat> imgList, vector<int> FinalOffset);
	cv::Mat fuseByMaximum(cv::Mat ResultMat, vector<cv::Mat> imgList, vector<int> FinalOffset);
	cv::Mat fuseByMinimum(cv::Mat ResultMat, vector<cv::Mat> imgList, vector<int> FinalOffset);
	cv::Mat fuseByFadeInAndFadeOut(cv::Mat ResultMat, vector<cv::Mat> imgList, vector<int> FinalOffset);


	


};