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

	QString FilePath;  //�ļ���·��
	vector<string> imgList;  //ͼƬ·���б�
	QImage ResImg;  //ƴ�Ӵ�ͼ

	void Init();            //������ʼ��
	void Info(QString txt, QWidget *parent);
	static unsigned int _stdcall AlgorProcess(void *p);  //�㷨�߳�
	void AlgorProcessSlot();
	//AlgorithmStr *AlgStr;
	//ImageData *imgdata;
	SetupWidget *setupWidget;

	StitcherParam param;
	//��������¼�
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	QPoint m_start;//��ʼ��
	QPoint m_end;//������
	bool m_leftButtonPressed;//���������±��
signals:
	void StatusSignal(QString); //״̬��¼�ź� ���Ǳ��룩
	void StitchFinishSignal(ImageData*);  //�㷨���� �����ź�
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