#pragma execution_character_set("utf-8")
#include "SetupWidget.h"
#include "qdebug.h"

SetupWidget::SetupWidget(QWidget *parent)
	: QDialog(parent)
{
	//QDialog::setAttribute(Qt::WA_TranslucentBackground, true); //���ô���͸��
	this->setWindowFlags(Qt::FramelessWindowHint); //����ȥ�����ڱ߿�
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
	bg1->addButton(ui.rbtn1z1, 0);//һ��ֵΪ0
	bg1->addButton(ui.rbtn1z2, 1);//һ��ֵΪ1
	bg1->addButton(ui.rbtn1z3, 2);//һ��ֵΪ2
	ui.rbtn1z1->setChecked(true); //Ĭ��ѡ��

	bg2 = new QButtonGroup(this);
	bg2->addButton(ui.rbtn5Yes, 1);//һ��ֵΪ1
	bg2->addButton(ui.rbtn5No, 0);//һ��ֵΪ0
	ui.rbtn5No->setChecked(true); //Ĭ��ѡ��

	bg3 = new QButtonGroup(this);
	bg3->addButton(ui.rbtn6Yes, 1);//һ��ֵΪ1
	bg3->addButton(ui.rbtn6No, 0);//һ��ֵΪ0
	ui.rbtn6No->setChecked(true); //Ĭ��ѡ��
	

	bg4 = new QButtonGroup(this);
	bg4->addButton(ui.rbtn7Yes, 1);//һ��ֵΪ1
	bg4->addButton(ui.rbtn7No, 0);//һ��ֵΪ0
	ui.rbtn7No->setChecked(true); //Ĭ��ѡ��

	bg5 = new QButtonGroup(this);
	bg5->addButton(ui.rbtn8z1, 0);//һ��ֵΪ1
	bg5->addButton(ui.rbtn8z2, 1);//һ��ֵΪ2
	bg5->addButton(ui.rbtn8z3, 2);//һ��ֵΪ3
	ui.rbtn8z1->setChecked(true); //Ĭ��ѡ��

	ui.sboxRegion->setRange(5, 90);  // ��Χ
	ui.sboxRegion->setSingleStep(5); // ����
	ui.sboxRegion->setValue(15);  // ��ǰֵ
	//ui.sboxRegion->setPrefix("$ ");  // ǰ׺
	ui.sboxRegion->setSuffix(" %");  // ��׺
	ui.sboxRegion->setWrapping(true);  // ����ѭ��
	//ui.sboxRegion->setReadOnly(true);

	connect(ui.btnConfirm, SIGNAL(clicked()), this, SLOT(btnConfirm_Clicked()));
	connect(ui.btnCancel, SIGNAL(clicked()), this, SLOT(btnCancel_Clicked()));

	//δ����
	ui.rbtn5Yes->setDisabled(true);
	ui.rbtn6Yes->setDisabled(true);
	ui.rbtn7Yes->setDisabled(true);
}

void SetupWidget::GetValue()
{
	param.method = bg1->checkedId(); //ͼ��˳��

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
	
	// �����������¼�
	if (event->button() == Qt::LeftButton)
	{
		// ��¼������״̬
		m_leftButtonPressed = true;
		//��¼�������Ļ�е�λ��
		m_start = event->globalPos();

	}
	event->ignore();
}

void SetupWidget::mouseMoveEvent(QMouseEvent *event)
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

void SetupWidget::mouseReleaseEvent(QMouseEvent *event)
{
	// �������ͷ�
	if (event->button() == Qt::LeftButton)
	{
		// ��¼���״̬
		m_leftButtonPressed = false;
	}
}