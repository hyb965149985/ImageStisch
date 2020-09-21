#ifndef __GRAPHICSVIEW_h
#define __GRAPHICSVIEW_h

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QPointF>
#include <QGraphicsRectItem>
#include <QGraphicsSimpleTextItem>
#include <QVector>
#include <QScrollBar>
#include <qdebug.h>
class MyGraphicsPixmapItem : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT
public:
	MyGraphicsPixmapItem(QPixmap pixmap, int index = 0);
	~MyGraphicsPixmapItem();

signals:
	void mousePress(int index);
protected:
	/*******************************************
	������̳д˺�������GraphicsView_v2��scene()->mouseGrabberItem() ��ȡ�Ľ������ȷ
	******************************************/
	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
	virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

};


class GraphicsView : public QGraphicsView
{
	Q_OBJECT

public:
	GraphicsView(QWidget* view_parent = NULL);
	~GraphicsView();
	static GraphicsView *Instance();
private slots:
	void UpdateSlot(int value);
private:
	static GraphicsView *_instance;

	void zoomIn();
	void zoomOut();

	QGraphicsScene *m_scene;
	QVector<QGraphicsRectItem*> m_VecGraphicRectItem;
	QVector<QGraphicsLineItem*> m_VecGraphicLineItem;
	QVector<QGraphicsEllipseItem*> m_VecGraphicEllipseItem;
	QVector<QGraphicsTextItem*> m_VecGraphicTextItem;
	QVector<QGraphicsPixmapItem*> m_VecGraphicPixmapItem;

	bool m_drawMode;
	QPen m_curPen;

	bool m_isLeftDown;
	bool m_isRightDown;
	
	QPointF m_dragPosPre;
	QPointF m_dragPosCur;

	QPointF m_drawPosStart;
	QPointF m_drawPosEnd;

	QRect    m_rect;
	QRect    m_circle;
	QPointF  m_line_p1;
	QPointF  m_line_p2;
	QString  m_text;
	QImage   m_image;

	bool m_enableWheelEvent; //�Ƿ�����������ţ�
	float m_nCurScal;
	QScrollBar *hbar;
	QScrollBar *vbar;
public:
	void recover(); // �ָ�ԭʼ��С
	void ZoomFit(int width, int height); //����Ӧ���
	void SceneFitView();                //Scene����Ӧ

	void setImage(QImage img, int byIsZoomFit = 1, bool bClear = true);
	void setImage(QPixmap img, int byIsZoomFit = 1, bool bClear = false);
	
	void drawRect(QRect rect, int iWidth = 2); //���ƾ��κ���������һ��������С�ĺ�ɫ���Σ�����������������������ͼ��
	void drawRect(const QRectF &rectF, const QPen &pen = QPen(), const QBrush &brush = QBrush());
	void drawLine(const QPointF p1, QPointF p2, int iWidth = 2);
	void drawLine(const QPointF p1, QPointF p2, const QPen &pen = QPen());
	void drawCircle(QRect rect, int iWidth = 2);
	void drawCircle(const QRectF &rectF, const QPen &pen = QPen(), const QBrush &brush = QBrush());
	void drawText(const QString &text, const QPointF &textPos = QPointF(), const QFont &font = QFont(), const QColor&color = QColor());

	void hideRectRoi(int nIndex);
	void hideRectRoi(QGraphicsRectItem*);
	void hideRectAll();
	void hideLineRoi(int nIndex);
	void hideLineRoi(QGraphicsLineItem*);
	void hideLineAll();
	void hideCircleRoi(int nIndex);
	void hideCircleRoi(QGraphicsEllipseItem*);
	void hideCircleAll();
	void hideTextRoi(int nIndex);
	void hideTextRoi(QGraphicsTextItem*);
	void hideTextAll();
	void hideAllRoi();

	void showRectRoi(int nIndex);
	void showRectRoi(QGraphicsRectItem*);
	void showRectAll();
	void showLineRoi(int nIndex);
	void showLineRoi(QGraphicsLineItem*);
	void showLineAll();
	void showCircleRoi(int nIndex);
	void showCircleRoi(QGraphicsEllipseItem*);
	void showCircleAll();
	void showTextRoi(int nIndex);
	void showTextRoi(QGraphicsTextItem*);
	void showTextAll();
	void showAllRoi();

	void clearRectRoi(int nIndex);
	void clearRectRoi(QGraphicsRectItem*);
	void clearRectAll();
	void clearLineRoi(int nIndex);
	void clearLineRoi(QGraphicsLineItem*);
	void clearLineAll();
	void clearCircleRoi(int nIndex);
	void clearCircleRoi(QGraphicsEllipseItem*);
	void clearCircleAll();
	void clearTextRoi(int nIndex);
	void clearTextRoi(QGraphicsTextItem*);
	void clearTextAll();
	void clearAllRoi();

	void hideImage(int nIndex);
	void hideImage(QGraphicsPixmapItem*);
	void hideImageAll();
	void showImage(int nIndex);
	void showImage(QGraphicsPixmapItem*);
	void showImageAll();
	void clearImageRoi(int nIndex);
	void clearImageRoi(QGraphicsPixmapItem*);
	void clearImageAll();
	void clearAll();
	void clearScene();

	void setDrawMode(bool state);
	void setDrawPen(QPen pen = QPen(Qt::black, 7));
	void setWheelEnabled(bool enable);

	QRect GetDrawRect() { return m_rect; }
	QRect GetDrawCircle() { return m_circle; }
	QString GetDrawText() { return m_text; }
	QImage GetCurImage() { return m_image; }
	void GetDrawLine(QPointF &p1, QPointF &p2) { p1 = m_line_p1; p2 = m_line_p2; }
private:
	void wheelEvent(QWheelEvent *e);
	void mousePressEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);
	void mouseMoveEvent(QMouseEvent *e);
	void resizeEvent(QResizeEvent *event);
	void mouseDoubleClickEvent(QMouseEvent *event);
signals:
	void DrawRectSignal(QRect, QPen); //�������ź�
	void mousePositionSignal(QPointF);
	void PosChangeSignal(QString);
	void mouseClickSignal(QPointF);
	void mouseDblClickSignal(QPointF);
	void DrawOneSignal(); //����һ��ͼ�ε��ź�
public slots:
	void mousePositionSlot(QPointF);
	void DrawRectSlot(QRect, QPen);
};


#endif