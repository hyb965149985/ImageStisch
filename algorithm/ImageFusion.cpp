#include "ImageFusion.h"
#include "omp.h"
//图像融合算法
ImageFuse::ImageFuse()
{
}

/*
	功能：直接覆盖融合
	:param  ResultMat : 最终图像大小 
			imgList： 各个未拼接图像
			FinalOffset：每个图像对于结果图像的偏移量
	:return : 融合后的图像
*/
cv::Mat ImageFuse::fuseByNotFuse(cv::Mat ResultMat, vector<cv::Mat> imgList, vector<int> FinalOffset)
{
	for (size_t i = 0; i < imgList.size(); i++)
	{
		cv::Rect roi_rect = cv::Rect(FinalOffset[2 * i + 1], FinalOffset[2 * i], imgList[i].cols, imgList[i].rows);
		imgList[i].copyTo(ResultMat(roi_rect));
	}
	return ResultMat;
}

cv::Mat ImageFuse::fuseByAverage(cv::Mat ResultMat, vector<cv::Mat> imgList, vector<int> FinalOffset)
{

	//计算每个像素点 被几个原始图片重叠
	cv::Mat NumsMat(ResultMat.rows, ResultMat.cols, CV_8UC1, cv::Scalar(0));
	for (size_t k = 0; k < imgList.size(); k++)
	{
		cv::Rect roi_rect = cv::Rect(FinalOffset[2 * k + 1], FinalOffset[2 * k], imgList[k].cols, imgList[k].rows);

		cv::Mat tempMat(imgList[k].rows, imgList[k].cols, CV_8UC1, cv::Scalar(1));
		NumsMat(roi_rect)+= tempMat;
	}
	cv::merge(vector<cv::Mat>{NumsMat, NumsMat, NumsMat}, NumsMat);
	
	//相加 final=sum（ones/nums）
	for (size_t k = 0; k < imgList.size(); k++)
	{
		cv::Rect roi_rect = cv::Rect(FinalOffset[2 * k + 1], FinalOffset[2 * k], imgList[k].cols, imgList[k].rows);
		cv::Mat tempMat = imgList[k] / NumsMat(roi_rect);
		ResultMat(roi_rect) += tempMat;
	}
	return ResultMat;
}

cv::Mat ImageFuse::fuseByMaximum(cv::Mat ResultMat, vector<cv::Mat> imgList, vector<int> FinalOffset)
{

	for (size_t k = 0; k < imgList.size(); k++)
	{
		cv::Rect roi_rect = cv::Rect(FinalOffset[2 * k + 1], FinalOffset[2 * k], imgList[k].cols, imgList[k].rows);

		cv::Mat initMat= ResultMat(roi_rect);

		omp_set_num_threads(4);
#pragma omp parallel for
		for (int i = 0; i < initMat.rows; i++)
		{
			for (int j = 0; j < initMat.cols; j++)
			{
				if (ResultMat.dims == 1)
				{
					initMat.at<cv::Vec3b>(i, j)[0] = max(initMat.at<cv::Vec3b>(i, j)[0], imgList[k].at<uchar>(i, j));
					initMat.at<cv::Vec3b>(i, j)[1] = max(initMat.at<cv::Vec3b>(i, j)[1], imgList[k].at<uchar>(i, j));
					initMat.at<cv::Vec3b>(i, j)[2] = max(initMat.at<cv::Vec3b>(i, j)[2], imgList[k].at<uchar>(i, j));
				}
				else
				{
					/*int a = initMat.at<cv::Vec3b>(i, j)[0];
					int b = imgList[k].at<cv::Vec3b>(i, j)[0];*/

					initMat.at<cv::Vec3b>(i, j)[0] = max(initMat.at<cv::Vec3b>(i, j)[0], imgList[k].at<cv::Vec3b>(i, j)[0]);
					initMat.at<cv::Vec3b>(i, j)[1] = max(initMat.at<cv::Vec3b>(i, j)[1], imgList[k].at<cv::Vec3b>(i, j)[1]);
					initMat.at<cv::Vec3b>(i, j)[2] = max(initMat.at<cv::Vec3b>(i, j)[2], imgList[k].at<cv::Vec3b>(i, j)[2]);
				}
			}
		}
		initMat.copyTo(ResultMat(roi_rect));
	}
	return ResultMat; 
}

cv::Mat ImageFuse::fuseByMinimum(cv::Mat ResultMat, vector<cv::Mat> imgList, vector<int> FinalOffset)
{
	return ResultMat;
}

cv::Mat ImageFuse::fuseByFadeInAndFadeOut(cv::Mat ResultMat, vector<cv::Mat> imgList, vector<int> FinalOffset)
{
	return cv::Mat();
}




