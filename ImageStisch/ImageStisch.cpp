#pragma execution_character_set("utf-8")
#include "ImageStisch.h"
volatile int g_isRunning = 0; //多线程运行标志位
ImageStisch::ImageStisch(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	Init();
}

void ImageStisch::Init()
{

	//保证所需文件夹都在
	if (QFileInfo("../result").isFile() == 0) QDir("../result").mkdir("../result");
	if (QFileInfo("../logs").isFile() == 0)   QDir("../logs").mkdir("../logs");
	//if (QFileInfo("../temp").isFile() == 0)   QDir("../temp").mkdir("../temp");

	// 软件图标
	//setWindowIcon(QIcon("logo.png"));
	
	setWindowTitle("显微图像拼接项目"); // 标题大小
	resize(1000, 600);
	//setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);    // 禁止最大化按钮
	//setFixedSize(this->width(), this->height());                     // 禁止拖动窗口大小
	QRect rect = QApplication::desktop()->screenGeometry(0); //获取第一个显示器的分辨率
	move((rect.width() - this->width()) / 2, (rect.height() - this->height()) / 2); //移动到中心
	this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏 

	connect(this, SIGNAL(StatusSignal(QString)), this, SLOT(StatusSlot(QString)));
	connect(this, SIGNAL(StitchFinishSignal(ImageData*)), this, SLOT(StitchFinishSlot(ImageData*)));

	connect(ui.title_btn_menu, SIGNAL(clicked()), this, SLOT(title_btn_menu_Clicked()));
	connect(ui.title_btn_min, SIGNAL(clicked()), this, SLOT(title_btn_min_Clicked()));
	connect(ui.title_btn_max, SIGNAL(clicked()), this, SLOT(title_btn_max_Clicked()));
	connect(ui.title_btn_close, SIGNAL(clicked()), this,  SLOT(title_btn_close_Clicked()));

	connect(ui.btnReadFile, SIGNAL(clicked()), this, SLOT(btnReadFile_Clicked()));
	connect(ui.btnSetup, SIGNAL(clicked()), this, SLOT(btnSetup_Clicked()));
	connect(ui.btnStart, SIGNAL(clicked()), this, SLOT(btnStart_running()));
	connect(ui.btnSave, SIGNAL(clicked()), this, SLOT(btnSave_Clicked()));
	
	connect(ui.ImageList, SIGNAL(clicked(const QModelIndex &)), this, SLOT(slotRowClicked(const QModelIndex &)));


	setupWidget = new SetupWidget(this);
	connect(setupWidget, SIGNAL(sendAlgValue(StitcherParam)), this, SLOT(getAlgValue(StitcherParam)));
	//初始化
	param.method = 0; //图像顺序
	param.GPU_enabled = 0;
	param.Enhance_enabled = 0;
	param.Bright_enabled = 0;
	param.featureMethod = 2;
	param.fuseMethod = 1;
	param.outputfileExtension = "jpg";
	param.outputName = "../result/";
	param.roiRatio = 0.15;
	//setupWidget->ui.btnConfirm->click();
	//setupWidget->show();
	//setupWidget->close();
	
}


void ImageStisch::Info(QString txt, QWidget *parent)
{
	//新建的时候注意不要设置父对象，否则它不会单独显示出来，而是显示在父对象中。
	ReminderWidget* p_widget = new ReminderWidget(txt, parent);
	//简单计算一下其显示的坐标
	int x, y;
	x = this->width() / 2 - p_widget->width() / 2; // 位于中央
	y = 40;   // 位于窗口下方40像素位置

	//cout << x << " " << y << endl;
	//设置控件显示的位置
	p_widget->setGeometry(x, y, p_widget->width(), p_widget->height());
	p_widget->show();
}

/* **************  slot 函数  *************************** */

void ImageStisch::title_btn_menu_Clicked()
{
	Info("该功能未开放", this);
}
void ImageStisch::title_btn_min_Clicked()
{
	this->showMinimized();
}
void ImageStisch::title_btn_max_Clicked()
{
	this->isMaximized() ? this->showNormal() : this->showMaximized();
}
void ImageStisch::title_btn_close_Clicked()
{
	this->close();
}

//打开文件夹
void ImageStisch::btnReadFile_Clicked()
{
	if (g_isRunning == 1)
	{
		Info("算法运行中", this);
		return;
	}

	QString OriginPath(FilePath);
	if (FilePath.size()>0)  FilePath = QFileDialog::getExistingDirectory(0, QString("打开目录"), FilePath);
	else FilePath = QFileDialog::getExistingDirectory(0, QString("打开目录"), QDir::currentPath());

		
	if (FilePath.size() == 0)
	{
		Info("打开文件夹失败", this);
		return;
	}
	QDir dir(FilePath);//当前打开路径 作为目录路径 

	Q_ASSERT(dir.exists());
	
	QStringList imagesList;//找到的文件存入此队列

	//dir.setFilter(QDir::Files | QDir::NoSymLinks);
	QStringList filters;
	filters << "*.bmp" << "*.jpg"<<"*.png"<< "*.tiff"<<"*.jpeg"; //过滤条件，可以添加多个选项，可以匹配文件后缀等。
	dir.setNameFilters(filters); //添加过滤器
	imagesList = dir.entryList();
	if (imagesList.size() <= 1)
	{
		FilePath = OriginPath;
		Info("该文件夹下没有或只有一张图片！", this);
		//QMessageBox::information(this, "Information", "该文件夹下没有或只有一张图片！");
		return;
	}

	//判断路径是否存在中文，存在的话 将图片拷贝到 temp内
	//bool isChinese = FilePath.contains(QRegExp("[\\x4e00-\\x9fa5]+"));


	//清空
	this->imgList.clear();
	this->imgList.reserve(imagesList.size());
	
	//ui.ImageList->cl

	QStandardItemModel* model = new QStandardItemModel(ui.ImageList);
	model->setColumnCount(1);
	ui.ImageList->setEditTriggers(QAbstractItemView::NoEditTriggers); //不可编辑
	ui.ImageList->verticalHeader()->hide(); //隐藏行头
	ui.ImageList->horizontalHeader()->hide(); //隐藏列头
	for (int i = 0; i < imagesList.size(); i++)
	{
		string imageFile = FilePath.toStdString() + "/" +imagesList[i].toStdString();
		this->imgList.push_back(imageFile);

		//列表也按照顺序显示图片文件
		
		model->setItem(i, 0, new QStandardItem(imagesList[i]));
		model->item(i, 0)->setTextAlignment(Qt::AlignCenter);

		
	}
	
	ui.ImageList->setModel(model);
	ui.ImageList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//所有列都扩展自适应宽度，填充充满整个屏幕宽度
	ui.ImageList->setSelectionBehavior(QAbstractItemView::SelectRows); //整行选中


	qDebug() << FilePath <<endl;
}

//参数设置
void ImageStisch::btnSetup_Clicked()
{
	if (g_isRunning == 1)
	{
		Info("算法运行中", this);
		return;
	}


	setupWidget->setGeometry((this->width()- setupWidget->width())/2, (this->height() - setupWidget->height()) / 2,
		setupWidget->width(), setupWidget->height());
	setupWidget->show();
	//Info("该功能未开放");

	//delete p_widget;
}


//算法执行按钮
void ImageStisch::btnStart_running()
{
	if (imgList.size() < 2)
	{
		Info("请打开文件夹", this);
		return;
	}
	else if (g_isRunning == 1)
	{
		Info("算法运行中", this);
		return;
	}
	AlgorithmStr* AlgStr = new AlgorithmStr;
	AlgStr->m = this;
	AlgStr->imgList = imgList;
	AlgStr->param = param;
	AlgStr->stitcher = Stitcher::Instance();
	//AlgStr->stitcher = new Stitcher();

	Q_ASSERT(AlgStr->imgList.size()>=2);
	//void* p;
	_beginthreadex(0, 0, AlgorProcess, AlgStr, 0, 0);
	//delete AlgStr;
}

//一个没什么用的保存文件按钮
void ImageStisch::btnSave_Clicked()
{
	if (g_isRunning == 1)
	{
		Info("算法运行中", this);
		return;
	}

	Info("已保存在result文件夹下", this);
	ui.m_Vectorview->setImage(ResImg);

	
}

//文件列表 左键点击 展示图像
void ImageStisch::slotRowClicked(const QModelIndex &index)
{
	if (index.isValid())
		{
		    QString cellText = FilePath + "/" + index.data().toString();
			QImage img(cellText);
			if (img.isNull()) return;
			//ipCameraLabel->setPixmap(QPixmap::fromImage(img));
			ui.m_Vectorview->setImage(img);
			qDebug() << cellText;
		}
}

void ImageStisch::AlgorProcessSlot()
{

}

//状态显示
void ImageStisch::StatusSlot(QString str)
{
	ui.lblRes->setText(str);
	if(str=="失败" )  QMessageBox::information(this, "Information", "失败！\n请改变参数重试");
}

//算法完成 图像显示
void ImageStisch::StitchFinishSlot(ImageData* imgdata)
{
	ResImg = QImage(imgdata->Timg.data, imgdata->Timg.cols, imgdata->Timg.rows, imgdata->Timg.step, QImage::Format_RGB888);
	//ResImg.save("./a.jpg", "jpg");
	while(g_isRunning==0)Info("自动保存在result文件夹下", this); //算法线程还没运行完，这句话会失败  QT 指定运行在某个线程???
	ui.btnSave->click();
}

void ImageStisch::getAlgValue(StitcherParam param)
{
	this->param.Bright_enabled = param.Bright_enabled;
	this->param.Enhance_enabled = param.Enhance_enabled;
	this->param.featureMethod = param.featureMethod;
	this->param.fuseMethod = param.fuseMethod;
	this->param.GPU_enabled = param.GPU_enabled;
	this->param.method = param.method;
	this->param.outputfileExtension = param.outputfileExtension;
	this->param.outputName = param.outputName;
	this->param.roiRatio = param.roiRatio;
}




/* 算法线程 */
unsigned int _stdcall ImageStisch::AlgorProcess(void *p) {

	AlgorithmStr* o = (AlgorithmStr*)p;
	g_isRunning = 1;

	

	//状态信号
	emit o->m->StatusSignal(("正在拼接"));

	clock_t start, finish;
	start = clock();

	//核心算法
	ImageData* imgdata = o->stitcher->flowStitch(o->param, o->imgList, "xxx");

	finish = clock();
	printf("time= %f \n", (double)(finish - start) / CLOCKS_PER_SEC);

	//状态信号
	if(imgdata->status) emit o->m->StatusSignal(("就绪"));
	else emit o->m->StatusSignal(("失败"));
	// 结束信号
	emit o->m->StitchFinishSlot(imgdata);

	

	g_isRunning = 0;
	delete o;
	return 0;
}




void ImageStisch::mousePressEvent(QMouseEvent *event)
{
	// 鼠标左键按下事件
	if (event->button() == Qt::LeftButton && event->pos().y()<=35)
	{
		// 记录鼠标左键状态
		m_leftButtonPressed = true;
		//记录鼠标在屏幕中的位置
		m_start = event->globalPos();

	}
	event->ignore();
}

void ImageStisch::mouseMoveEvent(QMouseEvent *event)
{
	// 持续按住才做对应事件
	if (m_leftButtonPressed)
	{
		//将父窗体移动到父窗体原来的位置加上鼠标移动的位置：event->globalPos()-m_start
		this->move(this->pos() + event->globalPos() - m_start);
		//将鼠标在屏幕中的位置替换为新的位置
		m_start = event->globalPos();

	}
}

void ImageStisch::mouseReleaseEvent(QMouseEvent *event)
{
	// 鼠标左键释放
	if (event->button() == Qt::LeftButton)
	{
		// 记录鼠标状态
		m_leftButtonPressed = false;
	}
}

void ImageStisch::mouseDoubleClickEvent(QMouseEvent *event)
{
	if (event->pos().y() <= 35)
	{
		ui.title_btn_max->click();
	}
}