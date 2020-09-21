#include "Stitcher.h"
#include "ImageUtility.h"
#include "ImageFusion.h"
#include "ylog.h"
#include <mutex>
std::mutex mutex_instance;

/*
direction

# 1： 第一张图像在上，第二张图像在下；   2： 第一张图像在左，第二张图像在右；
# 3： 第一张图像在下，第二张图像在上；   4： 第一张图像在右，第二张图像在左；

*/



//构造函数
Stitcher::Stitcher()
{

	//fuseMethod= NotFuse;
	this->fuseMethod = 1;


	this->roiRatio = 0.3; //增长半径

	this->method = Free; //拼接方法
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
//构造函数
Stitcher::Stitcher(float roiRatio, string outputName, string outputfileExtension, 
	int method, int splicingmethod, int fuseMethod)
{
	
	//fuseMethod= NotFuse;
	this->fuseMethod = fuseMethod;


	this->roiRatio= roiRatio; //增长半径

	this->method= method; //拼接方法
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

//构造函数
Stitcher::Stitcher(StitcherParam param)
{

	//fuseMethod= NotFuse;
	this->fuseMethod = param.fuseMethod;


	this->roiRatio = param.roiRatio; //增长半径

	this->method = param.method; //拼接方法
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


//析构函数
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
	// TODO: 在此处插入 return 语句
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


	this->roiRatio = param.roiRatio; //增长半径

	this->method = param.method; //拼接方法
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
	功能：改变拼接搜索方向，通过direction和method控制
	:param direction : 当前的方向
	:param method： 当前拼接类型
	:return : 返回更新后的方向
*/
int Stitcher::directionIncrease(int direction, int method)
{
	switch (method)
	{
		//自由拼接 则4个方向都有可能
		case 0:
			direction == 4 ? direction = 1 : direction++;
			break;

		//上下拼接 则只有 direction=1 方向
		case 1:
			direction = 1;
			break;

		//左右拼接 则只有 direction=2 方向
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

功能：序列拼接，从list的第一张拼接到最后一张，中间可能出现拼接失败，故改变参数

	:param fileList: 图像地址序列
	:param caculateOffsetMethod:计算偏移量方法
	:return: ((status, endfileIndex), stitchImage),（（拼接状态， 截止文件索引）， 拼接结果）

*/
ImageData* Stitcher::flowStitch(StitcherParam param, vector<string> fileList, string caculateOffsetMethod)
{
	GetValue(param);

	log = "starting ImageStitch";
	clog->W(__FILE__, __LINE__, YLog::INFO, log);

	assert(fileList.size() >= 2);
	int fileNum = fileList.size();


	vector<int> offsetList;// (fileNum, -1);

	//第一张图片的偏移量为(0,0) 
	offsetList.push_back(0);
	offsetList.push_back(0);

	//计算 第i+1张图片对于第i张图片的偏移量
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
		

		//B对A的相对偏移量
		int* offset =new int[2];

		//状态 A B是否拼接 false-拼接失败  true-拼接成功
		bool staus = 0;

		calculateOffsetForFeatureSearchIncre(imageA, imageB, offset, staus);
		
		if (staus == 0)
		{
			char* c = new char[256];
			sprintf(c,"The NO.%d and NO.%d pictures failed to be stitched together", fileIndex+1, fileIndex + 2);
			log = c;
			clog->W(__FILE__, __LINE__, YLog::INFO, log);
			//sprintf("拼接到第XXX张 拼接失败");
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
	cv::cvtColor(stitchImage, stitchImage, CV_BGR2RGB);     //将图像转换为BGR

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
	    功能：采用特征搜索计算偏移量+考虑增长搜索区域
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
		if(k>0)searchRatio *= 2; //每个方向都失败 则 增加搜索区域
		if (searchRatio > 1.0) break;
		//各个方向都要尝试
		while (true)
		{
			char* c = new char[256];
			sprintf(c, "localDirection is %d, searchRatio is %0.4f", localDirection, searchRatio);
			log = c;
			clog->W(__FILE__, __LINE__, YLog::INFO, log);


			cv::Mat roiImageA = spm->getROIRegion(imageA, localDirection, "first", searchRatio);
			cv::Mat roiImageB = spm->getROIRegion(imageB, localDirection, "second", searchRatio);
			
			//图像增强??
			//xxxx
			
			//特征点提取

			//特征点描述符，为下边的特征点匹配做准备    
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
			//特征匹配


			vector<std::pair<int, int> > matches = spm->matchDescriptors(imageDescA, imageDescB);
			//计算偏移量
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
			//由于机械运动固定长度，当拼接成功后，下次以这个长度也一定成功
			//this->roiRatio = searchRatio; 

			// 偏移量校正 （因为做了增长区域）
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
	功能：通过偏移量列表和文件列表得到最终的拼接结果
	:param fileList : 图像列表
	:param offsetList : 偏移量列表
	:return : Mat : 图像
*/
cv::Mat Stitcher::getStitchByOffset(vector<string> fileList, vector<int> offsetList)
{
	// 不细心千万不要动这段代码 千万！！！
	// 一杯小破茶 一调一下午  ！！！！

	log = "starting ImageFusion";
	clog->W(__FILE__, __LINE__, YLog::INFO, log);

	int dxSum = 0;
	int dySum = 0;

	cv::Mat imgInitial = cv::imread(fileList[0]);
	
	vector<cv::Mat> imgList;
	imgList.push_back(imgInitial);

	int resultRow = imgInitial.rows;        // # 拼接最终结果的横轴长度, 先赋值第一个图像的横轴
	int	resultCol = imgInitial.cols;        // # 拼接最终结果的纵轴长度, 先赋值第一个图像的纵轴

	//能够拼接的图片只有 offsetList.size() / 2 张

	//计算 每张图片 相对于 最终图片的偏移量
	vector<int> FinalOffset( offsetList);
	for (int i = 1; i < offsetList.size() / 2; i++)
	{
		//放入内存   用空间换时间 
		imgInitial = cv::imread(fileList[i]);
		imgList.push_back(imgInitial);

		dxSum += FinalOffset[i * 2];
		dySum += FinalOffset[i * 2 + 1];

		//
		if (dxSum <= 0)
		{
			//不能出现负数，整体后移   以此图片为x坐标零点
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
			//不能出现负数，整体后移   以此图片为x坐标零点
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

// 如上算出各个图像相对于原点偏移量，并最终计算出输出图像大小，并构造矩阵，如下开始赋值
void Stitcher::StitchResult(cv::Mat &ResultMat, vector<cv::Mat> imgList, vector<int> FinalOffset)
{
	//后期改成 工厂模式
	switch (fuseMethod)
	{
	case 0:
		//覆盖融合
		ResultMat = imf->fuseByNotFuse(ResultMat, imgList, FinalOffset);
		break;
	case 1:
		//均值融合
		ResultMat = imf->fuseByAverage(ResultMat, imgList, FinalOffset);
		break;
	case 2:
		//最大值融合
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


