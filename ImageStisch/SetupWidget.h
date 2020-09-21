#pragma once
#include <QWidget>
#include <QTimer>
#include <qevent.h>
#include <QButtonGroup>
#include <string>
#include "ui_SetupDialog.h"
#include "Stitcher.h"

using namespace std;
class SetupWidget : public QDialog
{
	Q_OBJECT

public:
	SetupWidget(QWidget *parent = Q_NULLPTR);


	~SetupWidget();

	void Init();

	void GetValue();

	StitcherParam param;
signals:
	void sendAlgValue(StitcherParam);

private slots:
	void btnConfirm_Clicked();
	void btnCancel_Clicked();
	//void onTimeup;Destroy();
private:
	Ui::SetupDialog ui;

	QButtonGroup *bg1, *bg2, *bg3, *bg4, *bg5;

	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	QPoint m_start;//起始点
	QPoint m_end;//结束点
	bool m_leftButtonPressed;//鼠标左键按下标记
};