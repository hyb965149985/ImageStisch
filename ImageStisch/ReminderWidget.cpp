#pragma execution_character_set("utf-8")
#include "ReminderWidget.h"

ReminderWidget::ReminderWidget(QString text, QWidget *parent)
	: QWidget(parent)
{
	setAttribute(Qt::WA_TranslucentBackground, true); //���ô���͸��
	ui.setupUi(this);
	
	//����ȥ�����ڱ߿�
	this->setWindowFlags(Qt::FramelessWindowHint);
	//textΪҪ��ʾ����Ϣ
	ui.label->setText(text);
	//���ö�ʱ������ʱ��������
	QTimer* timer = new QTimer(this);
	timer->start(1500);//ʱ��1.5��
	timer->setSingleShot(true);//������һ��
	connect(timer, SIGNAL(timeout()), this, SLOT(onTimeupDestroy()));

	//Init();
}

ReminderWidget::~ReminderWidget()
{
}


void ReminderWidget::onTimeupDestroy()
{
	delete this;
}