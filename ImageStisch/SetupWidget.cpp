#pragma execution_character_set("utf-8")
#include "SetupWidget.h"
#include "qdebug.h"

SetupWidget::SetupWidget(QWidget *parent)
	: QDialog(parent)
{
	//QDialog::setAttribute(Qt::WA_TranslucentBackground, true); //设置窗口透明
	this->setWindowFlags(Qt::FramelessWindowHint); //设置去掉窗口边框
	ui.setupUi(this);

	Init();

	ui.btnConfirm->click();
}

SetupWidget::~SetupWidget()
{
	delete bg1, bg2, bg3, bg4, bg5;
}


void SetupWidget::Init()
{

	bg1 = new QButtonGroup(this);
	bg1->addButton(ui.rbtn1z1, 0);//一个值为0
	bg1->addButton(ui.rbtn1z2, 1);//一个值为1
	bg1->addButton(ui.rbtn1z3, 2);//一个值为2
	ui.rbtn1z1->setChecked(true); //默认选中

	bg2 = new QButtonGroup(this);
	bg2->addButton(ui.rbtn5Yes, 1);//一个值为1
	bg2->addButton(ui.rbtn5No, 0);//一个值为0
	ui.rbtn5No->setChecked(true); //默认选中

	bg3 = new QButtonGroup(this);
	bg3->addButton(ui.rbtn6Yes, 1);//一个值为1
	bg3->addButton(ui.rbtn6No, 0);//一个值为0
	ui.rbtn6No->setChecked(true); //默认选中
	

	bg4 = new QButtonGroup(this);
	bg4->addButton(ui.rbtn7Yes, 1);//一个值为1
	bg4->addButton(ui.rbtn7No, 0);//一个值为0
	ui.rbtn7No->setChecked(true); //默认选中

	bg5 = new QButtonGroup(this);
	bg5->addButton(ui.rbtn8z1, 0);//一个值为1
	bg5->addButton(ui.rbtn8z2, 1);//一个值为2
	bg5->addButton(ui.rbtn8z3, 2);//一个值为3
	ui.rbtn8z1->setChecked(true); //默认选中

	ui.sboxRegion->setRange(5, 90);  // 范围
	ui.sboxRegion->setSingleStep(5); // 步长
	ui.sboxRegion->setValue(15);  // 当前值
	//ui.sboxRegion->setPrefix("$ ");  // 前缀
	ui.sboxRegion->setSuffix(" %");  // 后缀
	ui.sboxRegion->setWrapping(true);  // 开启循环
	//ui.sboxRegion->setReadOnly(true);

	connect(ui.btnConfirm, SIGNAL(clicked()), this, SLOT(btnConfirm_Clicked()));
	connect(ui.btnCancel, SIGNAL(clicked()), this, SLOT(btnCancel_Clicked()));

	//未开发
	ui.rbtn5Yes->setDisabled(true);
	ui.rbtn6Yes->setDisabled(true);
	ui.rbtn7Yes->setDisabled(true);
}

void SetupWidget::GetValue()
{
	param.method = bg1->checkedId(); //图像顺序

	param.GPU_enabled = bg2->checkedId();
	param.Enhance_enabled = bg3->checkedId();
	param.Bright_enabled = bg4->checkedId();

	param.featureMethod = ui.cboxFeature->currentIndex();
	param.fuseMethod = ui.cboxFuse->currentIndex();
	
	//QString ss;
	//ss.split()
	//string temp_s= ui.sboxRegion->text().toStdString();
	//string temp_s
	//QString temp_c = QString::fromStdString(temp_s);

	param.roiRatio = ui.sboxRegion->text().left(2).toFloat()/100;

	vector<string> temp{".jpg",".png",".bmp"};
	param.outputfileExtension = temp[bg5->checkedId()];
	param.outputName = ui.label->text().toStdString();
}

void SetupWidget::btnConfirm_Clicked()
{
	GetValue();
	emit sendAlgValue(param);
	this->hide();

}
void SetupWidget::btnCancel_Clicked()
{
	this->hide();
}
void SetupWidget::mousePressEvent(QMouseEvent *event)
{
	
	// 鼠标左键按下事件
	if (event->button() == Qt::LeftButton)
	{
		// 记录鼠标左键状态
		m_leftButtonPressed = true;
		//记录鼠标在屏幕中的位置
		m_start = event->globalPos();

	}
	event->ignore();
}

void SetupWidget::mouseMoveEvent(QMouseEvent *event)
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

void SetupWidget::mouseReleaseEvent(QMouseEvent *event)
{
	// 鼠标左键释放
	if (event->button() == Qt::LeftButton)
	{
		// 记录鼠标状态
		m_leftButtonPressed = false;
	}
}