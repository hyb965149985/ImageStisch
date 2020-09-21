#include "ImageUtility.h"
#include "omp.h"
#include <mutex>

//���캯��
SplicingMethod::SplicingMethod(int featureMethod)
{
	this->featureMethod =  featureMethod;
}

//�õ�ROI����
cv::Mat SplicingMethod::getROIRegion(cv::Mat image, int direction, string order, float searchRatio=0.2)
{
	/*
		���ܣ����������������������ݱ����������������
		:param image : ԭʼͼ��
		:param direction : ��������
		:param order : ��first��or'second'�ж����ڵڼ���ͼ��
		:param searchRatio : �ü���������ı�����Ĭ�����������ϵĳ��ȵ�0.2
		:return : ��������roiͼ��
	
	*/
	int row = image.rows;
	int col = image.cols;

	cv::Mat roiRegion;

	
	if (direction == 1)
	{
		int searchLength = (int)row * searchRatio;
		if (order.compare("first") == 0)
		{
			roiRegion = image(cv::Rect(0, row - searchLength , col, searchLength));
		}
		else if(order.compare("second") == 0)
		{
			roiRegion = image(cv::Rect(0, 0, col, searchLength));
		}

	}

	if (direction == 2)
	{
		int searchLength = (int)col * searchRatio;
		if (order.compare("first") == 0)
		{
			roiRegion = image(cv::Rect(col - searchLength, 0, searchLength, row));
		}
		else if (order.compare("second") == 0)
		{
			roiRegion = image(cv::Rect(0, 0, searchLength, row));
		}

	}


	if (direction == 3)
	{
		int searchLength = (int)row * searchRatio;
		if (order.compare("first") == 0)
		{
			roiRegion = image(cv::Rect(0, 0, col, searchLength));
		}
		else if (order.compare("second") == 0)
		{
			roiRegion = image(cv::Rect(0, row - searchLength, col, searchLength));
		}

	}


	if (direction == 4)
	{
		int searchLength = (int)col * searchRatio;
		if (order.compare("first") == 0)
		{
			roiRegion = image(cv::Rect(0, 0, searchLength, row));
		}
		else if (order.compare("second") == 0)
		{
			roiRegion = image(cv::Rect(col - searchLength, 0, searchLength, row));	
		}

	}
	return roiRegion;
}


void SplicingMethod::detectAndDescribe(cv::Mat roiImage, vector<cv::KeyPoint>& keyPoint, cv::Mat & imageDesc)
{
	if (featureMethod == FAST)
	{
		// ���� GPU - ORB ������
		int orbNfeatures = 5000;
		float orbScaleFactor = 1.2;
		int orbNlevels = 8;
		int orbEdgeThreshold = 31;
		int orbFirstLevel = 0;
		int orbWTA_K = 2;
		int orbPatchSize = 31;
		int orbFastThreshold = 20;
		bool orbBlurForDescriptor = false;
		int orbMaxDistance = 30;
		cv::Ptr<cv::ORB> orb;
		orb = cv::ORB::create(orbNfeatures, orbScaleFactor, orbNlevels, orbEdgeThreshold, orbFirstLevel, orbWTA_K, orbPatchSize, orbFastThreshold);
		orb->detectAndCompute(roiImage, cv::Mat(), keyPoint, imageDesc);
		return;
	}

	if (featureMethod == SURF)
	{
		cv::Ptr<cv::Feature2D> surf = cv::xfeatures2d::SURF::create();
		surf->detectAndCompute(roiImage, cv::Mat(), keyPoint, imageDesc);
		return;
	}

	if (featureMethod == SIFT)
	{
		// δ֪ BUG 

		/*cv::Ptr<cv::Feature2D> featureDetector = cv::xfeatures2d::SIFT::create();
		featureDetector->detectAndCompute(roiImage,cv::Mat(), keyPoint, imageDesc);*/
		

		return;
	}
}

vector<std::pair<int, int>> SplicingMethod::matchDescriptors(cv::Mat imageDescA, cv::Mat imageDescB)
{

	vector<cv::DMatch> GoodMatchePoints;//ƥ��������GoodMatchePoints����
	if (featureMethod == FAST)
	{
		cv::Ptr<cv::DescriptorMatcher> matcher = cv::DescriptorMatcher::create("BruteForce-Hamming");
		matcher->match(imageDescA, imageDescB, GoodMatchePoints,cv::Mat());
	}
	else if (featureMethod == SURF || featureMethod == SIFT)
	{
		cv::Ptr<cv::DescriptorMatcher> matcher = cv::DescriptorMatcher::create("FlannBased");		
		matcher->match(imageDescA, imageDescB,  GoodMatchePoints,cv::Mat());
		//matcher->knnMatch(imageDescA, imageDescB, GoodMatchePoints, 2, cv::Mat(),0);
	}
	//���� ƥ��� ���    Ҳ����ʹ�� cv::Point2i ��ʾ
	vector<std::pair<int, int> > matches(GoodMatchePoints.size());
	//vector<int> queryIdxs(GoodMatchePoints.size()), trainIdxs(GoodMatchePoints.size());

	for (int i = 0; i < GoodMatchePoints.size(); i++)
	{
		matches[i].first = GoodMatchePoints[i].queryIdx;//ȡ��AͼƬ��ƥ��ĵ�Ե�������id�ţ�
		matches[i].second = GoodMatchePoints[i].trainIdx;//ȡ��BͼƬ��ƥ��ĵ�Ե�������id�ţ�
	}
	return matches;

	
}

/*
���ܣ�ͨ���������ķ������ƫ����
:param keyPoint1 : ��һ��ͼ�������
:param keyPoint2 : �ڶ���ͼ�������
:param matches : ��׼�б�
:param offsetEvaluate : ��������ĸ������ڱ���ֵ������׼��ȷ��Ĭ��Ϊ10
:return : ����(status, [dx, dy]), status �Ƿ���ȷ��[dx, dy]Ĭ��[0, 0]
*/
cv::Point2i SplicingMethod::getOffsetByMode(vector<cv::KeyPoint> keyPoint1, vector<cv::KeyPoint> keyPoint2, vector<std::pair<int, int>> matches, bool &status, int offsetEvaluate)
{
	status = true;
	if (matches.size() == 0)
	{
		status = false;
		return cv::Point2i(0, 0);
	}
	vector<int> dxList, dyList;

	for (int i = 0; i < matches.size(); i++)
	{
		cv::Point2f ptA(keyPoint1[matches[i].first].pt.y, keyPoint1[matches[i].first].pt.x);
		cv::Point2f ptB(keyPoint2[matches[i].second].pt.y, keyPoint2[matches[i].second].pt.x);
		if (int(ptA.x - ptB.x) == 0 && int(ptA.y - ptB.y) == 0)
		{
			continue;
		}
		dxList.push_back(int(ptA.x - ptB.x));
		dyList.push_back(int(ptA.y - ptB.y));
	}
	if (dxList.size() == 0)
	{
		dxList.push_back(0);
		dyList.push_back(0);
	}

	// ���� ���� ���� ������
	pair<int,int> FinalPoint(0, 0);
	int MaxNum = 0;

	map<pair<int, int>, int> nums;
	for (size_t i = 0; i < dxList.size(); i++)
	{
		pair<int, int> temp = pair<int, int>(dxList[i], dyList[i]);
		if (!nums.count(temp))
		{
			nums[temp] = 1;
		}
		else
		{
			nums[temp]++;
		}

		if (nums[temp] > MaxNum)
		{
			MaxNum = nums[temp];
			FinalPoint = temp;
		}
		if (MaxNum > offsetEvaluate * 2)
		{
			break;
		}
	}

	if (MaxNum < offsetEvaluate)
	{
		status = false;
		return cv::Point2i(0, 0);

	}


	return cv::Point2i(FinalPoint.first,FinalPoint.second);
}


