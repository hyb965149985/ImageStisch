#include "Stitcher.h"
#include "ImageUtility.h"
#include "ImageFusion.h"
#include "ylog.h"
#include <mutex>
std::mutex mutex_instance;

/*
direction

# 1�� ��һ��ͼ�����ϣ��ڶ���ͼ�����£�   2�� ��һ��ͼ�����󣬵ڶ���ͼ�����ң�
# 3�� ��һ��ͼ�����£��ڶ���ͼ�����ϣ�   4�� ��һ��ͼ�����ң��ڶ���ͼ������

*/



//���캯��
Stitcher::Stitcher()
{

	//fuseMethod= NotFuse;
	this->fuseMethod = 1;


	this->roiRatio = 0.3; //�����뾶

	this->method = Free; //ƴ�ӷ���
	this->direction = directionList[Free];

	this->outputName = "../result/";
	this->outputfileExtension = "jpg";
	this->spm = new SplicingMethod(FAST);

	this->imf = new ImageFuse();

	time_t timep;
	time(&timep);
	char tmp[256];
	strftime(tmp, sizeof(tmp), "../logs/%Y%m%d.txt", localtime(&timep));
	clog = new YLog(YLog::INFO, tmp, YLog::ADD);

}
//���캯��
Stitcher::Stitcher(float roiRatio, string outputName, string outputfileExtension, 
	int method, int splicingmethod, int fuseMethod)
{
	
	//fuseMethod= NotFuse;
	this->fuseMethod = fuseMethod;


	this->roiRatio= roiRatio; //�����뾶

	this->method= method; //ƴ�ӷ���
	this->direction = directionList[method];

	this->outputName = outputName;
	this->outputfileExtension = outputfileExtension;

	this->spm = new SplicingMethod(splicingmethod);
	this->imf = new ImageFuse();

	time_t timep;
	time(&timep);
	char tmp[256];
	strftime(tmp, sizeof(tmp), "../logs/%Y%m%d.txt", localtime(&timep));
	clog = new YLog(YLog::INFO, tmp, YLog::ADD);

}

//���캯��
Stitcher::Stitcher(StitcherParam param)
{

	//fuseMethod= NotFuse;
	this->fuseMethod = param.fuseMethod;


	this->roiRatio = param.roiRatio; //�����뾶

	this->method = param.method; //ƴ�ӷ���
	this->direction = directionList[method];

	this->outputName = param.outputName;
	this->outputfileExtension = param.outputfileExtension;

	this->spm = new SplicingMethod(param.featureMethod);
	this->imf = new ImageFuse();

	
	time_t timep;
	time(&timep);
	char tmp[256];
	strftime(tmp, sizeof(tmp), "../logs/%Y%m%d.txt", localtime(&timep));
	clog = new YLog(YLog::INFO, tmp, YLog::ADD);

	cout << "######################" << endl;
	cout << "fuseMethod: " << fuseMethod << endl;;
	cout << "method: " << method<<endl;;
	cout << "roiRatio: " << roiRatio << endl;
	cout << "######################" << endl;
	assert(this->roiRatio > 0.01 && this->roiRatio < 1);
	//assert(this->roiRatio > 0.01);
}


//��������
Stitcher::~Stitcher()
{
	delete _instance;
	delete spm;
	delete imf;
	delete clog;
}

const Stitcher & Stitcher::operator=(const Stitcher &)
{
	//void* p;
	return *_instance;// *Stitcher::Instance(param);
	// TODO: �ڴ˴����� return ���
}
 
Stitcher* Stitcher::_instance = 0;
Stitcher* Stitcher::Instance()
{
	if (!_instance)
	{
		mutex_instance.lock();
		if (!_instance)
		{
			_instance = new Stitcher();
		}
		mutex_instance.unlock();
	}
	return _instance;
}



void Stitcher::GetValue(StitcherParam param)
{

	//fuseMethod= NotFuse;
	this->fuseMethod = param.fuseMethod;


	this->roiRatio = param.roiRatio; //�����뾶

	this->method = param.method; //ƴ�ӷ���
	this->direction = directionList[method];

	this->outputName = param.outputName;
	this->outputfileExtension = param.outputfileExtension;

	this->spm = new SplicingMethod(param.featureMethod);
	this->imf = new ImageFuse();
	

	cout << "######################" << endl;
	cout << "method: " << method << endl;;
	cout << "fuseMethod: " << fuseMethod << endl;;
	cout << "featureMethod: " << param.featureMethod << endl;;
	cout << "roiRatio: " << roiRatio << endl;
	cout << "######################" << endl;
	assert(this->roiRatio > 0.01 && this->roiRatio < 1);
	//assert(this->roiRatio > 0.01);
}




/*
	���ܣ��ı�ƴ����������ͨ��direction��method����
	:param direction : ��ǰ�ķ���
	:param method�� ��ǰƴ������
	:return : ���ظ��º�ķ���
*/
int Stitcher::directionIncrease(int direction, int method)
{
	switch (method)
	{
		//����ƴ�� ��4�������п���
		case 0:
			direction == 4 ? direction = 1 : direction++;
			break;

		//����ƴ�� ��ֻ�� direction=1 ����
		case 1:
			direction = 1;
			break;

		//����ƴ�� ��ֻ�� direction=2 ����
		case 2:
			direction = 2;
			break;
	default:
		log = "Stitcher::directionIncrease error";
		clog->W(__FILE__, __LINE__, YLog::INFO, log);
		
		break;
	}

	return direction;
}

/*

���ܣ�����ƴ�ӣ���list�ĵ�һ��ƴ�ӵ����һ�ţ��м���ܳ���ƴ��ʧ�ܣ��ʸı����

	:param fileList: ͼ���ַ����
	:param caculateOffsetMethod:����ƫ��������
	:return: ((status, endfileIndex), stitchImage),����ƴ��״̬�� ��ֹ�ļ��������� ƴ�ӽ����

*/
ImageData* Stitcher::flowStitch(StitcherParam param, vector<string> fileList, string caculateOffsetMethod)
{
	GetValue(param);

	log = "starting ImageStitch";
	clog->W(__FILE__, __LINE__, YLog::INFO, log);

	assert(fileList.size() >= 2);
	int fileNum = fileList.size();


	vector<int> offsetList;// (fileNum, -1);

	//��һ��ͼƬ��ƫ����Ϊ(0,0) 
	offsetList.push_back(0);
	offsetList.push_back(0);

	//���� ��i+1��ͼƬ���ڵ�i��ͼƬ��ƫ����
	cv::Mat imageA, imageB;
	for (int fileIndex = 0; fileIndex < fileNum-1; fileIndex++)
	{
		
		string temp = "stitching " + (fileList[fileIndex]) + " and " + (fileList[fileIndex + 1]);
		log = temp;
		clog->W(__FILE__, __LINE__, YLog::INFO, log);
	
		
		if (fileIndex == 0)
		{
			imageA = cv::imread(fileList[fileIndex], cv::IMREAD_GRAYSCALE);
			imageB = cv::imread(fileList[fileIndex + 1], cv::IMREAD_GRAYSCALE);
		}
		else
		{
			imageA = imageB.clone();
			imageB = cv::imread(fileList[fileIndex + 1], cv::IMREAD_GRAYSCALE);
		}
		

		//B��A�����ƫ����
		int* offset =new int[2];

		//״̬ A B�Ƿ�ƴ�� false-ƴ��ʧ��  true-ƴ�ӳɹ�
		bool staus = 0;

		calculateOffsetForFeatureSearchIncre(imageA, imageB, offset, staus);
		
		if (staus == 0)
		{
			char* c = new char[256];
			sprintf(c,"The NO.%d and NO.%d pictures failed to be stitched together", fileIndex+1, fileIndex + 2);
			log = c;
			clog->W(__FILE__, __LINE__, YLog::INFO, log);
			//sprintf("ƴ�ӵ���XXX�� ƴ��ʧ��");
			break;

		}
		else
		{
			offsetList.push_back(offset[0]);
			offsetList.push_back(offset[1]);
		}
		delete[] offset;
	}

	cv::Mat stitchImage = getStitchByOffset(fileList, offsetList);
	//Mat RGBImage;
	cv::cvtColor(stitchImage, stitchImage, CV_BGR2RGB);     //��ͼ��ת��ΪBGR

	ImageData *imgdata = new ImageData;
	imgdata->Timg = stitchImage;
	
	/*char* c = new char[256];
	sprintf(c, "fileList.size() = %d and fileNum= %d ", fileList.size(), fileNum);
	log = c;
	clog->W(__FILE__, __LINE__, YLog::INFO, log);*/


	imgdata->status = fileNum == offsetList.size() / 2;
	//imgdata->data = new uchar[3* stitchImage.cols*stitchImage.rows];
	//memcpy(imgdata->data , stitchImage.data, 3 * stitchImage.cols*stitchImage.rows*sizeof(uchar));
	//imgdata->width = stitchImage.cols;
	//imgdata->height = stitchImage.rows;
	//imgdata->step = (cv::MatStep)stitchImage.step;

	return imgdata;
}

void Stitcher::calculateOffsetForFeatureSearchIncre(cv::Mat imageA, cv::Mat imageB, int* offset, bool& stauts)
{
	/*
	    ���ܣ�����������������ƫ����+����������������
        :param images: [imageA, imageB]
        :return:(status, offset)
	
	*/

	offset[0] = 0;
	offset[1] = 0;

	stauts = 0;

	int iniDirection = direction;
	int localDirection = iniDirection;

	float searchRatio = roiRatio;
	for (int k = 0; searchRatio < 1; k++)
	{
		if(k>0)searchRatio *= 2; //ÿ������ʧ�� �� ������������
		if (searchRatio > 1.0) break;
		//��������Ҫ����
		while (true)
		{
			char* c = new char[256];
			sprintf(c, "localDirection is %d, searchRatio is %0.4f", localDirection, searchRatio);
			log = c;
			clog->W(__FILE__, __LINE__, YLog::INFO, log);


			cv::Mat roiImageA = spm->getROIRegion(imageA, localDirection, "first", searchRatio);
			cv::Mat roiImageB = spm->getROIRegion(imageB, localDirection, "second", searchRatio);
			
			//ͼ����ǿ??
			//xxxx
			
			//��������ȡ

			//��������������Ϊ�±ߵ�������ƥ����׼��    
			cv::Mat imageDescA, imageDescB;
			vector<cv::KeyPoint> keyPoint1, keyPoint2;
			
			spm->detectAndDescribe(roiImageA, keyPoint1, imageDescA);
			spm->detectAndDescribe(roiImageB, keyPoint2, imageDescB);

			if (imageDescA.empty() || imageDescB.empty())
			{
				stauts = 0;
				localDirection = directionIncrease(localDirection, method);
				if (localDirection == iniDirection)
				{
					break;
				}
				continue;
			}
			assert(!imageDescA.empty() && !imageDescB.empty());
			//����ƥ��


			vector<std::pair<int, int> > matches = spm->matchDescriptors(imageDescA, imageDescB);
			//����ƫ����
			cv::Point2i offer = spm->getOffsetByMode(keyPoint1,keyPoint2, matches, stauts);
			 

			offset[0] = offer.x;
			offset[1] = offer.y;


			if (stauts == 1)
			{
				break;
			}
			else
			{
				localDirection = directionIncrease(localDirection, method);
			}

			if (localDirection == iniDirection)
			{
				break;
			}	
		}
		

		if (stauts == 1)
		{
			//���ڻ�е�˶��̶����ȣ���ƴ�ӳɹ����´����������Ҳһ���ɹ�
			//this->roiRatio = searchRatio; 

			// ƫ����У�� ����Ϊ������������
			if (localDirection == 1)
			{
				
				offset[0] = offset[0] + imageA.rows - int(searchRatio * imageA.rows);
			}
			else if (localDirection == 2)
			{ 
				
				offset[1] = offset[1] + imageA.cols - int(searchRatio * imageA.cols);
			}
			else if (localDirection == 3)
			{
				offset[0] = offset[0] - (imageB.rows - int(searchRatio * imageB.rows));

			}
			else if (localDirection == 4)
			{
				offset[1] = offset[1] - (imageB.cols - int(searchRatio * imageB.cols));

			}
			direction = localDirection;

			//cout <<"offset: " <<offset[0] << " " << offset[1] << endl;
			break;
		}


	}

	//if (stauts == 0)
	//{
	//	log = "Stitcher::calculateOffsetForFeatureSearchIncre error";
	//	clog->W(__FILE__, __LINE__, YLog::INFO, log);
	//}


}


/*
	���ܣ�ͨ��ƫ�����б���ļ��б�õ����յ�ƴ�ӽ��
	:param fileList : ͼ���б�
	:param offsetList : ƫ�����б�
	:return : Mat : ͼ��
*/
cv::Mat Stitcher::getStitchByOffset(vector<string> fileList, vector<int> offsetList)
{
	// ��ϸ��ǧ��Ҫ����δ��� ǧ�򣡣���
	// һ��С�Ʋ� һ��һ����  ��������

	log = "starting ImageFusion";
	clog->W(__FILE__, __LINE__, YLog::INFO, log);

	int dxSum = 0;
	int dySum = 0;

	cv::Mat imgInitial = cv::imread(fileList[0]);
	
	vector<cv::Mat> imgList;
	imgList.push_back(imgInitial);

	int resultRow = imgInitial.rows;        // # ƴ�����ս���ĺ��᳤��, �ȸ�ֵ��һ��ͼ��ĺ���
	int	resultCol = imgInitial.cols;        // # ƴ�����ս�������᳤��, �ȸ�ֵ��һ��ͼ�������

	//�ܹ�ƴ�ӵ�ͼƬֻ�� offsetList.size() / 2 ��

	//���� ÿ��ͼƬ ����� ����ͼƬ��ƫ����
	vector<int> FinalOffset( offsetList);
	for (int i = 1; i < offsetList.size() / 2; i++)
	{
		//�����ڴ�   �ÿռ任ʱ�� 
		imgInitial = cv::imread(fileList[i]);
		imgList.push_back(imgInitial);

		dxSum += FinalOffset[i * 2];
		dySum += FinalOffset[i * 2 + 1];

		//
		if (dxSum <= 0)
		{
			//���ܳ��ָ������������   �Դ�ͼƬΪx�������
			for (int j = 0; j < i; j++)
			{
				FinalOffset[2 * j] += (-dxSum);
			}
			resultRow = max(resultRow - dxSum, imgInitial.rows);

			FinalOffset[2 * i] = 0;
			dxSum = 0;
		}
		else
		{
			FinalOffset[2 * i] = dxSum;
			resultRow = max(resultRow, imgInitial.rows + dxSum);
		}

		//
		if (dySum <= 0)
		{
			//���ܳ��ָ������������   �Դ�ͼƬΪx�������
			for (int j = 0; j < i; j++)
			{
				FinalOffset[2 * j+1] += (-dySum);
			}
			resultCol = max(resultCol - dySum, imgInitial.cols);

			FinalOffset[2 * i + 1] = 0;
			dySum = 0;
		}
		else
		{
			FinalOffset[2 * i + 1] = dySum;
			resultCol = max(resultCol, imgInitial.cols + dySum);
		}
	}

	int* initData = new int[resultRow*resultCol*3];
	memset(initData, 0, resultRow*resultCol*3);
	cv::Mat ResultMat(resultRow, resultCol,  CV_8UC3, initData);


	StitchResult(ResultMat, imgList, FinalOffset);


	return ResultMat;
}

// �����������ͼ�������ԭ��ƫ�����������ռ�������ͼ���С��������������¿�ʼ��ֵ
void Stitcher::StitchResult(cv::Mat &ResultMat, vector<cv::Mat> imgList, vector<int> FinalOffset)
{
	//���ڸĳ� ����ģʽ
	switch (fuseMethod)
	{
	case 0:
		//�����ں�
		ResultMat = imf->fuseByNotFuse(ResultMat, imgList, FinalOffset);
		break;
	case 1:
		//��ֵ�ں�
		ResultMat = imf->fuseByAverage(ResultMat, imgList, FinalOffset);
		break;
	case 2:
		//���ֵ�ں�
		ResultMat = imf->fuseByMaximum(ResultMat, imgList, FinalOffset);
		break;
	case 3:
		ResultMat = imf->fuseByMinimum(ResultMat, imgList, FinalOffset);
		break;
	case 4:
		ResultMat = imf->fuseByFadeInAndFadeOut(ResultMat, imgList, FinalOffset);
		break;
	default:
		break;
	}
	

	time_t timep;
	time(&timep);
	char tmp[256];
	strftime(tmp, sizeof(tmp), "%Y%m%d_%H%M%S", localtime(&timep));
	//cout << tmp << endl;


	outputName += tmp;
	outputName += ".";
	outputName += outputfileExtension;
	cv::imwrite(outputName, ResultMat.clone());
	
	log = "images saved in " + outputName;
	clog->W(__FILE__, __LINE__, YLog::INFO, log);
	//cv::imshow("ResultMat",ResultMat);
}


