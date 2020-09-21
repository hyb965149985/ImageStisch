#pragma execution_character_set("utf-8")
#include "ReminderWidget.h"

ReminderWidget::ReminderWidget(QString text, QWidget *parent)
	: QWidget(parent)
{
	setAttribute(Qt::WA_TranslucentBackground, true); //设置窗口透明
	ui.setupUi(this);
	
	//设置去掉窗口边框
	this->setWindowFlags(Qt::FramelessWindowHint);
	//text为要显示的信息
	ui.label->setText(text);
	//设置定时器，到时自我销毁
	QTimer* timer = new QTimer(this);
	timer->start(1500);//时间1.5秒
	timer->setSingleShot(true);//仅触发一次
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