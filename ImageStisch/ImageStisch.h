#pragma once
#include <QtWidgets/QMainWindow>
#include <QtGui>
#include <QtWidgets>
#include <QMenuBar>
#include <qdebug.h>
#include <qdialog.h>
#include "string.h"
#include <process.h>
#include "ui_ImageStisch.h"

#include "SetupWidget.h"
#include "ReminderWidget.h"
#include "Stitcher.h"
using namespace std;



struct AlgorithmStr;
//struct ImageData;
class ImageStisch : public QMainWindow
{
    Q_OBJECT

public:
    ImageStisch(QWidget *parent = Q_NULLPTR);

	

private:
    Ui::ImageStischClass ui;

	QString FilePath;  //文件夹路径
	vector<string> imgList;  //图片路径列表
	QImage ResImg;  //拼接大图

	void Init();            //变量初始化
	void Info(QString txt, QWidget *parent);
	static unsigned int _stdcall AlgorProcess(void *p);  //算法线程
	void AlgorProcessSlot();
	//AlgorithmStr *AlgStr;
	//ImageData *imgdata;
	SetupWidget *setupWidget;

	StitcherParam param;
	//各种鼠标事件
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	QPoint m_start;//起始点
	QPoint m_end;//结束点
	bool m_leftButtonPressed;//鼠标左键按下标记
signals:
	void StatusSignal(QString); //状态记录信号 （非必须）
	void StitchFinishSignal(ImageData*);  //算法结束 传参信号
	void AlgorProcessSignal(QString a);

private slots:
	void StatusSlot(QString);
	void StitchFinishSlot(ImageData*);

	void getAlgValue(StitcherParam);

	void title_btn_menu_Clicked();
	void title_btn_min_Clicked();
	void title_btn_max_Clicked();
	void title_btn_close_Clicked();
	void btnReadFile_Clicked();
	void btnSave_Clicked();
	void btnSetup_Clicked();
	void btnStart_running();
	void slotRowClicked(const QModelIndex &);
};

struct AlgorithmStr {
	ImageStisch* m;
	vector<string> imgList;
	Stitcher *stitcher;
	StitcherParam param;

	
};

//struct ImageData {
//	uchar* data;
//	int width;
//	int height;
//};