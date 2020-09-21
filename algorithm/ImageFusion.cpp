#include "ImageFusion.h"
#include "omp.h"
//ͼ���ں��㷨
ImageFuse::ImageFuse()
{
}

/*
	���ܣ�ֱ�Ӹ����ں�
	:param  ResultMat : ����ͼ���С 
			imgList�� ����δƴ��ͼ��
			FinalOffset��ÿ��ͼ����ڽ��ͼ���ƫ����
	:return : �ںϺ��ͼ��
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

	//����ÿ�����ص� ������ԭʼͼƬ�ص�
	cv::Mat NumsMat(ResultMat.rows, ResultMat.cols, CV_8UC1, cv::Scalar(0));
	for (size_t k = 0; k < imgList.size(); k++)
	{
		cv::Rect roi_rect = cv::Rect(FinalOffset[2 * k + 1], FinalOffset[2 * k], imgList[k].cols, imgList[k].rows);

		cv::Mat tempMat(imgList[k].rows, imgList[k].cols, CV_8UC1, cv::Scalar(1));
		NumsMat(roi_rect)+= tempMat;
	}
	cv::merge(vector<cv::Mat>{NumsMat, NumsMat, NumsMat}, NumsMat);
	
	//��� final=sum��ones/nums��
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




