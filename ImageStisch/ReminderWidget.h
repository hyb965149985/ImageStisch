#pragma once

#include <QWidget>
#include <QTimer>
#include "ui_ReminderWidget.h"

class ReminderWidget : public QWidget
{
	Q_OBJECT

public:
	ReminderWidget(QString text = "", QWidget *parent = Q_NULLPTR);
	

	~ReminderWidget(); 
private slots:
	void onTimeupDestroy();
private:
	Ui::ReminderWidget ui;
};