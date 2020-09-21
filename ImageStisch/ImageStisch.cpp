#pragma execution_character_set("utf-8")
#include "ImageStisch.h"
volatile int g_isRunning = 0; //���߳����б�־λ
ImageStisch::ImageStisch(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	Init();
}

void ImageStisch::Init()
{

	//��֤�����ļ��ж���
	if (QFileInfo("../result").isFile() == 0) QDir("../result").mkdir("../result");
	if (QFileInfo("../logs").isFile() == 0)   QDir("../logs").mkdir("../logs");
	//if (QFileInfo("../temp").isFile() == 0)   QDir("../temp").mkdir("../temp");

	// ���ͼ��
	//setWindowIcon(QIcon("logo.png"));
	
	setWindowTitle("��΢ͼ��ƴ����Ŀ"); // �����С
	resize(1000, 600);
	//setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);    // ��ֹ��󻯰�ť
	//setFixedSize(this->width(), this->height());                     // ��ֹ�϶����ڴ�С
	QRect rect = QApplication::desktop()->screenGeometry(0); //��ȡ��һ����ʾ���ķֱ���
	move((rect.width() - this->width()) / 2, (rect.height() - this->height()) / 2); //�ƶ�������
	this->setWindowFlags(Qt::FramelessWindowHint);//ȥ�������� 

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
	//��ʼ��
	param.method = 0; //ͼ��˳��
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
	//�½���ʱ��ע�ⲻҪ���ø����󣬷��������ᵥ����ʾ������������ʾ�ڸ������С�
	ReminderWidget* p_widget = new ReminderWidget(txt, parent);
	//�򵥼���һ������ʾ������
	int x, y;
	x = this->width() / 2 - p_widget->width() / 2; // λ������
	y = 40;   // λ�ڴ����·�40����λ��

	//cout << x << " " << y << endl;
	//���ÿؼ���ʾ��λ��
	p_widget->setGeometry(x, y, p_widget->width(), p_widget->height());
	p_widget->show();
}

/* **************  slot ����  *************************** */

void ImageStisch::title_btn_menu_Clicked()
{
	Info("�ù���δ����", this);
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

//���ļ���
void ImageStisch::btnReadFile_Clicked()
{
	if (g_isRunning == 1)
	{
		Info("�㷨������", this);
		return;
	}

	QString OriginPath(FilePath);
	if (FilePath.size()>0)  FilePath = QFileDialog::getExistingDirectory(0, QString("��Ŀ¼"), FilePath);
	else FilePath = QFileDialog::getExistingDirectory(0, QString("��Ŀ¼"), QDir::currentPath());

		
	if (FilePath.size() == 0)
	{
		Info("���ļ���ʧ��", this);
		return;
	}
	QDir dir(FilePath);//��ǰ��·�� ��ΪĿ¼·�� 

	Q_ASSERT(dir.exists());
	
	QStringList imagesList;//�ҵ����ļ�����˶���

	//dir.setFilter(QDir::Files | QDir::NoSymLinks);
	QStringList filters;
	filters << "*.bmp" << "*.jpg"<<"*.png"<< "*.tiff"<<"*.jpeg"; //����������������Ӷ��ѡ�����ƥ���ļ���׺�ȡ�
	dir.setNameFilters(filters); //��ӹ�����
	imagesList = dir.entryList();
	if (imagesList.size() <= 1)
	{
		FilePath = OriginPath;
		Info("���ļ�����û�л�ֻ��һ��ͼƬ��", this);
		//QMessageBox::information(this, "Information", "���ļ�����û�л�ֻ��һ��ͼƬ��");
		return;
	}

	//�ж�·���Ƿ�������ģ����ڵĻ� ��ͼƬ������ temp��
	//bool isChinese = FilePath.contains(QRegExp("[\\x4e00-\\x9fa5]+"));


	//���
	this->imgList.clear();
	this->imgList.reserve(imagesList.size());
	
	//ui.ImageList->cl

	QStandardItemModel* model = new QStandardItemModel(ui.ImageList);
	model->setColumnCount(1);
	ui.ImageList->setEditTriggers(QAbstractItemView::NoEditTriggers); //���ɱ༭
	ui.ImageList->verticalHeader()->hide(); //������ͷ
	ui.ImageList->horizontalHeader()->hide(); //������ͷ
	for (int i = 0; i < imagesList.size(); i++)
	{
		string imageFile = FilePath.toStdString() + "/" +imagesList[i].toStdString();
		this->imgList.push_back(imageFile);

		//�б�Ҳ����˳����ʾͼƬ�ļ�
		
		model->setItem(i, 0, new QStandardItem(imagesList[i]));
		model->item(i, 0)->setTextAlignment(Qt::AlignCenter);

		
	}
	
	ui.ImageList->setModel(model);
	ui.ImageList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//�����ж���չ����Ӧ��ȣ�������������Ļ���
	ui.ImageList->setSelectionBehavior(QAbstractItemView::SelectRows); //����ѡ��


	qDebug() << FilePath <<endl;
}

//��������
void ImageStisch::btnSetup_Clicked()
{
	if (g_isRunning == 1)
	{
		Info("�㷨������", this);
		return;
	}


	setupWidget->setGeometry((this->width()- setupWidget->width())/2, (this->height() - setupWidget->height()) / 2,
		setupWidget->width(), setupWidget->height());
	setupWidget->show();
	//Info("�ù���δ����");

	//delete p_widget;
}


//�㷨ִ�а�ť
void ImageStisch::btnStart_running()
{
	if (imgList.size() < 2)
	{
		Info("����ļ���", this);
		return;
	}
	else if (g_isRunning == 1)
	{
		Info("�㷨������", this);
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

//һ��ûʲô�õı����ļ���ť
void ImageStisch::btnSave_Clicked()
{
	if (g_isRunning == 1)
	{
		Info("�㷨������", this);
		return;
	}

	Info("�ѱ�����result�ļ�����", this);
	ui.m_Vectorview->setImage(ResImg);

	
}

//�ļ��б� ������ չʾͼ��
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

//״̬��ʾ
void ImageStisch::StatusSlot(QString str)
{
	ui.lblRes->setText(str);
	if(str=="ʧ��" )  QMessageBox::information(this, "Information", "ʧ�ܣ�\n��ı��������");
}

//�㷨��� ͼ����ʾ
void ImageStisch::StitchFinishSlot(ImageData* imgdata)
{
	ResImg = QImage(imgdata->Timg.data, imgdata->Timg.cols, imgdata->Timg.rows, imgdata->Timg.step, QImage::Format_RGB888);
	//ResImg.save("./a.jpg", "jpg");
	while(g_isRunning==0)Info("�Զ�������result�ļ�����", this); //�㷨�̻߳�û�����꣬��仰��ʧ��  QT ָ��������ĳ���߳�???
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




/* �㷨�߳� */
unsigned int _stdcall ImageStisch::AlgorProcess(void *p) {

	AlgorithmStr* o = (AlgorithmStr*)p;
	g_isRunning = 1;

	

	//״̬�ź�
	emit o->m->StatusSignal(("����ƴ��"));

	clock_t start, finish;
	start = clock();

	//�����㷨
	ImageData* imgdata = o->stitcher->flowStitch(o->param, o->imgList, "xxx");

	finish = clock();
	printf("time= %f \n", (double)(finish - start) / CLOCKS_PER_SEC);

	//״̬�ź�
	if(imgdata->status) emit o->m->StatusSignal(("����"));
	else emit o->m->StatusSignal(("ʧ��"));
	// �����ź�
	emit o->m->StitchFinishSlot(imgdata);

	

	g_isRunning = 0;
	delete o;
	return 0;
}




void ImageStisch::mousePressEvent(QMouseEvent *event)
{
	// �����������¼�
	if (event->button() == Qt::LeftButton && event->pos().y()<=35)
	{
		// ��¼������״̬
		m_leftButtonPressed = true;
		//��¼�������Ļ�е�λ��
		m_start = event->globalPos();

	}
	event->ignore();
}

void ImageStisch::mouseMoveEvent(QMouseEvent *event)
{
	// ������ס������Ӧ�¼�
	if (m_leftButtonPressed)
	{
		//���������ƶ���������ԭ����λ�ü�������ƶ���λ�ã�event->globalPos()-m_start
		this->move(this->pos() + event->globalPos() - m_start);
		//���������Ļ�е�λ���滻Ϊ�µ�λ��
		m_start = event->globalPos();

	}
}

void ImageStisch::mouseReleaseEvent(QMouseEvent *event)
{
	// �������ͷ�
	if (event->button() == Qt::LeftButton)
	{
		// ��¼���״̬
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