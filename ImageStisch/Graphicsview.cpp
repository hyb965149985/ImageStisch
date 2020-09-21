#include "graphicsview.h"
#include <mutex>
std::mutex mutex_instance;

MyGraphicsPixmapItem::MyGraphicsPixmapItem(QPixmap pixmap, int index) :QGraphicsPixmapItem(pixmap) {}
MyGraphicsPixmapItem::~MyGraphicsPixmapItem() {}
void MyGraphicsPixmapItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {}
void MyGraphicsPixmapItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) {}
GraphicsView::GraphicsView(QWidget* view_parent) : QGraphicsView(view_parent)
{
	m_scene = new QGraphicsScene(this);
	
	m_nCurScal = 1.0f;//记录放大倍数，用于将视图还原

	m_rect = QRect(0, 0, 0, 0);//正方形初始化
	m_circle = QRect(0, 0, 0, 0);//正方形初始化
	m_line_p1 = QPointF(0, 0);
	m_text = "";

	setScene(m_scene);//设置场景
	setDragMode(QGraphicsView::ScrollHandDrag);//设置拖拽模式
	setMouseTracking(true);//设置是否追踪鼠标

	m_enableWheelEvent = true;
	m_isLeftDown = false;
	m_isRightDown = false;

	m_dragPosPre = QPointF(0, 0);
	m_dragPosCur = QPointF(0, 0);
	m_drawPosStart = QPointF(0, 0);
	m_drawPosEnd = QPointF(0, 0);

	m_drawMode = false;
	m_curPen = QPen(Qt::black, 7);

	hbar = new QScrollBar(Qt::Horizontal);
	vbar = new QScrollBar(Qt::Vertical);
	vbar->setStyleSheet("QScrollBar:vertical{width:10px;background:rgba(225,225,226);margin:0px,0px,0px,0px;padding-top:0px;padding-bottom:0px;}"
		"QScrollBar::handle:vertical{background:rgba(225,225,226);border-radius:4px;min-height:20;}"
		"QScrollBar::handle:vertical:hover{background:rgba(0,0,0,0.2);}"
		"QScrollBar::add-line:vertical{height:0px;width:0px;subcontrol-position:bottom;}"
		"QScrollBar::sub-line:vertical{height:0px;width:0px;subcontrol-position:top;}");
	hbar->setStyleSheet("QScrollBar:horizontal{height:10px;background:rgba(225,225,226);margin:0px,0px,0px,0px;padding-left:0px;padding-right:0px;}"
		"QScrollBar::handle:horizontal{background:rgba(225,225,226);border-radius:4px;min-width:20;}"
		"QScrollBar::handle:horizontal:hover{background:rgba(0,0,0,0.2);}"
		"QScrollBar::add-line:horizontal{height:0px;width:0px;subcontrol-position:left;}"
		"QScrollBar::sub-line:horizontal{height:0px;width:0px;subcontrol-position:right;}");
	
	connect(hbar, SIGNAL(valueChanged (int)), this, SLOT(UpdateSlot(int)));
	connect(vbar, SIGNAL(valueChanged (int)), this, SLOT(UpdateSlot(int)));

	this->setHorizontalScrollBar(hbar);
	this->setVerticalScrollBar(vbar);
	this->setStyleSheet("border:2px solid #e1e1e2;");
	this->setBackgroundBrush(QBrush(Qt::black));
}
GraphicsView *GraphicsView::_instance = 0;

GraphicsView *GraphicsView::Instance()
{
	if (!_instance)
	{
		mutex_instance.lock();
		if (!_instance)
		{
			_instance = new GraphicsView;
		}
		mutex_instance.unlock();
	}
	return _instance;
}
GraphicsView::~GraphicsView() {}

void GraphicsView::UpdateSlot(int value){this->viewport()->update();}

//对图像进行放大
void GraphicsView::zoomIn(){m_nCurScal = m_nCurScal / 0.9f;	scale(1 / 0.9, 1 / 0.9);}
//对图像进行缩小
void GraphicsView::zoomOut(){m_nCurScal = m_nCurScal*0.9f;	scale(0.9, 0.9);}
//恢复图像原始大小
void GraphicsView::recover(){scale(m_nCurScal, m_nCurScal);	m_nCurScal = 1.0f;}
void GraphicsView::ZoomFit(int width, int height)
{
	if (width == 0 || height == 0)
	{
		return;
	}

	QTransform transform;
	double realFactor;

	int b = this->height() - 3;
	int a = width*b / height;

	if (a > this->width())
	{
		a = this->width() - 4;
		b = a*height / width;
	}

	double widthFactor = (double)a / width;
	double heightFactor = (double)b / height;

	if (heightFactor > widthFactor)
	{
		realFactor = widthFactor;
	}
	else
	{
		realFactor = heightFactor;
	}

	if (realFactor > 1)
	{
		realFactor = 1;
	}
	transform.scale(widthFactor, heightFactor);
	setTransform(transform);
}
void GraphicsView::SceneFitView()
{
	m_nCurScal = 1;
	int width = scene()->width();
	int height = scene()->height();
	ZoomFit(width, height);
}


//绘制矩形函数，绘制一个给定大小的红色矩形，不给定参数，无条件绘制图像
void GraphicsView::drawRect(QRect rect, int iWidth)
{
	QGraphicsRectItem* pItem = scene()->addRect(rect, QPen(Qt::red, iWidth));
	if (pItem != NULL)
		m_VecGraphicRectItem.push_back(pItem);//入栈
}
void GraphicsView::drawRect(const QRectF &rectF, const QPen &pen, const QBrush &brush)
{
	QGraphicsRectItem* pItem = scene()->addRect(rectF, pen, brush);
	if (pItem != NULL)
		m_VecGraphicRectItem.push_back(pItem);//入栈
}
void GraphicsView::drawLine(const QPointF p1, QPointF p2, int iWidth)
{
	QGraphicsLineItem* pItem = scene()->addLine(p1.x(), p1.y(), p2.x(), p2.y(), QPen(Qt::red, iWidth));
	if (pItem != NULL)
		m_VecGraphicLineItem.push_back(pItem);//入栈
}
void GraphicsView::drawLine(const QPointF p1, QPointF p2, const QPen &pen)
{
	QGraphicsLineItem* pItem = scene()->addLine(p1.x(), p1.y(), p2.x(), p2.y(), pen);
	if (pItem != NULL)
		m_VecGraphicLineItem.push_back(pItem);//入栈
}
void GraphicsView::drawCircle(QRect rect, int iWidth)
{
	QGraphicsEllipseItem* pItem = scene()->addEllipse(rect, QPen(Qt::red, iWidth));
	if (pItem != NULL)
		m_VecGraphicEllipseItem.push_back(pItem);//入栈
}
void GraphicsView::drawCircle(const QRectF &rectF, const QPen &pen, const QBrush &brush)
{
	QGraphicsEllipseItem* pItem = scene()->addEllipse(rectF, pen, brush);
	if (pItem != NULL)
		m_VecGraphicEllipseItem.push_back(pItem);//入栈
}
void GraphicsView::drawText(const QString &text, const QPointF &textPos, const QFont &font, const QColor &color)
{
	QGraphicsTextItem* pItem = new QGraphicsTextItem(text);
	pItem->setPos(textPos);
	pItem->setDefaultTextColor(color);
	pItem->setFont(font);
	pItem->update();
	scene()->addItem(pItem);
	m_VecGraphicTextItem.push_back(pItem);//入栈
}

void GraphicsView::hideRectRoi(int nIndex) {if (nIndex >= 0 && nIndex < m_VecGraphicRectItem.size())	m_VecGraphicRectItem[nIndex]->hide();} 
void GraphicsView::hideRectRoi(QGraphicsRectItem *pItem)
{
	for (int i = 0; i < m_VecGraphicRectItem.size(); i++)
	{
		if (m_VecGraphicRectItem[i] == pItem)
		{
			m_VecGraphicRectItem[i]->hide();
			break;
		}
	}
}
void GraphicsView::hideRectAll() { for (int i = 0; i < m_VecGraphicRectItem.size(); i++) m_VecGraphicRectItem[i]->hide();}
void GraphicsView::hideLineRoi(int nIndex) { if (nIndex >= 0 && nIndex < m_VecGraphicLineItem.size())	m_VecGraphicLineItem[nIndex]->hide(); }
void GraphicsView::hideLineRoi(QGraphicsLineItem *pItem)
{
	for (int i = 0; i < m_VecGraphicLineItem.size(); i++)
	{
		if (m_VecGraphicLineItem[i] == pItem)
		{
			m_VecGraphicLineItem[i]->hide();
			break;
		}
	}
}
void GraphicsView::hideLineAll() { for (int i = 0; i < m_VecGraphicLineItem.size(); i++) m_VecGraphicLineItem[i]->hide(); }
void GraphicsView::hideCircleRoi(int nIndex) { if (nIndex >= 0 && nIndex < m_VecGraphicEllipseItem.size())	m_VecGraphicEllipseItem[nIndex]->hide(); }
void GraphicsView::hideCircleRoi(QGraphicsEllipseItem *pItem)
{
	for (int i = 0; i < m_VecGraphicEllipseItem.size(); i++)
	{
		if (m_VecGraphicEllipseItem[i] == pItem)
		{
			m_VecGraphicEllipseItem[i]->hide();
			break;
		}
	}
}
void GraphicsView::hideCircleAll() { for (int i = 0; i < m_VecGraphicEllipseItem.size(); i++) m_VecGraphicEllipseItem[i]->hide(); }
void GraphicsView::hideTextRoi(int nIndex) { if (nIndex >= 0 && nIndex < m_VecGraphicTextItem.size())	m_VecGraphicTextItem[nIndex]->hide(); }
void GraphicsView::hideTextRoi(QGraphicsTextItem*pItem)
{
	for (int i = 0; i < m_VecGraphicTextItem.size(); i++)
	{
		if (m_VecGraphicTextItem[i] == pItem)
		{
			m_VecGraphicTextItem[i]->hide();
			break;
		}
	}
}
void GraphicsView::hideTextAll() { for (int i = 0; i < m_VecGraphicTextItem.size(); i++) m_VecGraphicTextItem[i]->hide(); }
void GraphicsView::hideAllRoi() { hideRectAll(); hideCircleAll(); hideLineAll(); hideTextAll(); }

void GraphicsView::showRectRoi(int nIndex) { if (nIndex >= 0 && nIndex < m_VecGraphicRectItem.size())	m_VecGraphicRectItem[nIndex]->show(); }
void GraphicsView::showRectRoi(QGraphicsRectItem *pItem)
{
	for (int i = 0; i < m_VecGraphicRectItem.size(); i++)
	{
		if (m_VecGraphicRectItem[i] == pItem)
		{
			m_VecGraphicRectItem[i]->show();
			break;
		}
	}
}
void GraphicsView::showRectAll() { for (int i = 0; i < m_VecGraphicRectItem.size(); i++) m_VecGraphicRectItem[i]->show(); }
void GraphicsView::showLineRoi(int nIndex) { if (nIndex >= 0 && nIndex < m_VecGraphicLineItem.size())	m_VecGraphicLineItem[nIndex]->show(); }
void GraphicsView::showLineRoi(QGraphicsLineItem *pItem)
{
	for (int i = 0; i < m_VecGraphicLineItem.size(); i++)
	{
		if (m_VecGraphicLineItem[i] == pItem)
		{
			m_VecGraphicLineItem[i]->show();
			break;
		}
	}
}
void GraphicsView::showLineAll() { for (int i = 0; i < m_VecGraphicLineItem.size(); i++) m_VecGraphicLineItem[i]->show(); }
void GraphicsView::showCircleRoi(int nIndex) { if (nIndex >= 0 && nIndex < m_VecGraphicEllipseItem.size())	m_VecGraphicEllipseItem[nIndex]->show(); }
void GraphicsView::showCircleRoi(QGraphicsEllipseItem *pItem)
{
	for (int i = 0; i < m_VecGraphicEllipseItem.size(); i++)
	{
		if (m_VecGraphicEllipseItem[i] == pItem)
		{
			m_VecGraphicEllipseItem[i]->show();
			break;
		}
	}
}
void GraphicsView::showCircleAll() { for (int i = 0; i < m_VecGraphicEllipseItem.size(); i++) m_VecGraphicEllipseItem[i]->show(); }
void GraphicsView::showTextRoi(int nIndex) { if (nIndex >= 0 && nIndex < m_VecGraphicTextItem.size())	m_VecGraphicTextItem[nIndex]->show(); }
void GraphicsView::showTextRoi(QGraphicsTextItem*pItem)
{
	for (int i = 0; i < m_VecGraphicTextItem.size(); i++)
	{
		if (m_VecGraphicTextItem[i] == pItem)
		{
			m_VecGraphicTextItem[i]->show();
			break;
		}
	}
}
void GraphicsView::showTextAll() { for (int i = 0; i < m_VecGraphicTextItem.size(); i++) m_VecGraphicTextItem[i]->show(); }
void GraphicsView::showAllRoi() { showRectAll(); showCircleAll(); showLineAll(); showTextAll(); }

void GraphicsView::clearRectRoi(int nIndex) 
{
	if (nIndex >= 0 && nIndex < m_VecGraphicRectItem.size())
	{
		scene()->removeItem(m_VecGraphicRectItem[nIndex]);
		delete m_VecGraphicRectItem[nIndex];
		m_VecGraphicRectItem.removeAt(nIndex);
	}
	update();
}
void GraphicsView::clearRectRoi(QGraphicsRectItem *pItem)
{
	for (int i = 0; i < m_VecGraphicRectItem.size(); i++)
	{
		if (m_VecGraphicRectItem[i] == pItem)
		{
			scene()->removeItem(m_VecGraphicRectItem[i]);
			delete m_VecGraphicRectItem[i];
			m_VecGraphicRectItem.removeAt(i);
			break;
		}
	}
	update();
}
void GraphicsView::clearRectAll() 
{
	while (m_VecGraphicRectItem.size() > 0)
	{
		scene()->removeItem(m_VecGraphicRectItem[0]);
		delete m_VecGraphicRectItem[0];
		m_VecGraphicRectItem.removeAt(0);
	}
	update();
}
void GraphicsView::clearLineRoi(int nIndex)
{
	if (nIndex >= 0 && nIndex < m_VecGraphicLineItem.size())
	{
		scene()->removeItem(m_VecGraphicLineItem[nIndex]);
		delete m_VecGraphicLineItem[nIndex];
		m_VecGraphicLineItem.removeAt(nIndex);
	}
	update();
}
void GraphicsView::clearLineRoi(QGraphicsLineItem *pItem)
{
	for (int i = 0; i < m_VecGraphicLineItem.size(); i++)
	{
		if (m_VecGraphicLineItem[i] == pItem)
		{
			scene()->removeItem(m_VecGraphicLineItem[i]);
			delete m_VecGraphicLineItem[i];
			m_VecGraphicLineItem.removeAt(i);
			break;
		}
	}
	update();
}
void GraphicsView::clearLineAll()
{
	while (m_VecGraphicLineItem.size() > 0)
	{
		scene()->removeItem(m_VecGraphicLineItem[0]);
		delete m_VecGraphicLineItem[0];
		m_VecGraphicLineItem.removeAt(0);
	}
	update();
}
void GraphicsView::clearCircleRoi(int nIndex) 
{
	if (nIndex >= 0 && nIndex < m_VecGraphicEllipseItem.size())
	{
		scene()->removeItem(m_VecGraphicEllipseItem[nIndex]);
		delete m_VecGraphicEllipseItem[nIndex];
		m_VecGraphicEllipseItem.removeAt(nIndex);
	}
	update();
}
void GraphicsView::clearCircleRoi(QGraphicsEllipseItem *pItem)

{
	for (int i = 0; i < m_VecGraphicEllipseItem.size(); i++)
	{
		if (m_VecGraphicEllipseItem[i] == pItem)
		{
			scene()->removeItem(m_VecGraphicEllipseItem[i]);
			delete m_VecGraphicEllipseItem[i];
			m_VecGraphicEllipseItem.removeAt(i);
			break;
		}
	}
	update();
}
void GraphicsView::clearCircleAll()
{
	while (m_VecGraphicEllipseItem.size() > 0)
	{
		scene()->removeItem(m_VecGraphicEllipseItem[0]);
		delete m_VecGraphicEllipseItem[0];
		m_VecGraphicEllipseItem.removeAt(0);
	}
	update();
}
void GraphicsView::clearTextRoi(int nIndex)
{
	if (nIndex >= 0 && nIndex < m_VecGraphicTextItem.size())
	{
		scene()->removeItem(m_VecGraphicTextItem[nIndex]);
		delete m_VecGraphicTextItem[nIndex];
		m_VecGraphicTextItem.removeAt(nIndex);
	}
	update();
}
void GraphicsView::clearTextRoi(QGraphicsTextItem*pItem)
{
	for (int i = 0; i < m_VecGraphicTextItem.size(); i++)
	{
		if (m_VecGraphicTextItem[i] == pItem)
		{
			scene()->removeItem(m_VecGraphicTextItem[i]);
			delete m_VecGraphicTextItem[i];
			m_VecGraphicTextItem.removeAt(i);
			break;
		}
	}
	update();
}
void GraphicsView::clearTextAll()
{
	while (m_VecGraphicTextItem.size() > 0)
	{
		scene()->removeItem(m_VecGraphicTextItem[0]);
		delete m_VecGraphicTextItem[0];
		m_VecGraphicTextItem.removeAt(0);
	}
	update();
}
void GraphicsView::clearAllRoi() { clearRectAll(); clearCircleAll(); clearLineAll(); clearTextAll(); }

void GraphicsView::hideImage(int nIndex)
{
	if (nIndex >= 0 && nIndex < m_VecGraphicPixmapItem.size())
		m_VecGraphicPixmapItem[nIndex]->hide();
}
void GraphicsView::hideImage(QGraphicsPixmapItem*pItem)
{
	for (int i = 0; i < m_VecGraphicPixmapItem.size(); i++)
	{
		if (m_VecGraphicPixmapItem[i] == pItem)
		{
			m_VecGraphicPixmapItem[i]->hide();
			break;
		}
	}
}
void GraphicsView::hideImageAll()
{
	for (int i = 0; i < m_VecGraphicPixmapItem.size(); i++) 
		m_VecGraphicPixmapItem[i]->hide();
}
void GraphicsView::showImage(int nIndex) 
{
	if (nIndex >= 0 && nIndex < m_VecGraphicPixmapItem.size())
		m_VecGraphicPixmapItem[nIndex]->show();
}
void GraphicsView::showImage(QGraphicsPixmapItem *pItem)
{
	for (int i = 0; i < m_VecGraphicPixmapItem.size(); i++)
	{
		if (m_VecGraphicPixmapItem[i] == pItem)
		{
			m_VecGraphicPixmapItem[i]->show();
			break;
		}
	}
}
void GraphicsView::showImageAll() 
{
	for (int i = 0; i < m_VecGraphicPixmapItem.size(); i++) 
		m_VecGraphicPixmapItem[i]->show();
}
void GraphicsView::clearImageRoi(int nIndex)
{
	if (nIndex >= 0 && nIndex < m_VecGraphicPixmapItem.size())
	{
		scene()->removeItem(m_VecGraphicPixmapItem[nIndex]);
		delete m_VecGraphicPixmapItem[nIndex];
		m_VecGraphicPixmapItem.removeAt(nIndex);
	}
	update();
}
void GraphicsView::clearImageRoi(QGraphicsPixmapItem*pItem)
{
	for (int i = 0; i < m_VecGraphicPixmapItem.size(); i++)
	{
		if (m_VecGraphicPixmapItem[i] == pItem)
		{
			scene()->removeItem(m_VecGraphicPixmapItem[i]);
			delete m_VecGraphicPixmapItem[i];
			m_VecGraphicPixmapItem.removeAt(i);
			break;
		}
	}
	update();
}
void GraphicsView::clearImageAll()
{
	m_rect = QRect(0, 0, 0, 0);
	while (m_VecGraphicPixmapItem.size() > 0)
	{
		scene()->removeItem(m_VecGraphicPixmapItem[0]);
		delete m_VecGraphicPixmapItem[0];
		m_VecGraphicPixmapItem.removeAt(0);
	}
	emit PosChangeSignal("");
	update();
}

void GraphicsView::clearAll()
{
	clearAllRoi();
	clearImageAll();
}
void GraphicsView::clearScene()
{
	clearAllRoi();
	clearImageAll();
	m_scene->clear();
}

//滚轮事件，用于控制图像的放大缩小
void GraphicsView::wheelEvent(QWheelEvent *e)
{
	if (!m_enableWheelEvent)	return;
	if (e->delta() > 0)		zoomIn();
	else	zoomOut();
}
void GraphicsView::mousePressEvent(QMouseEvent *e)
{
	QGraphicsView::mousePressEvent(e);
	if (e->button() == Qt::LeftButton)
	{
		m_dragPosPre.setX(e->x());
		m_dragPosPre.setY(e->y());
		m_isLeftDown = true;
	}
	else if (e->button() == Qt::RightButton)
	{
		if (m_drawMode)
			m_drawPosStart = mapToScene(e->pos());
		if (m_VecGraphicPixmapItem.size() == 0)
		{
			return;
		}
		int width = m_VecGraphicPixmapItem[0]->pixmap().width();
		int height = m_VecGraphicPixmapItem[0]->pixmap().height();
		if (m_drawPosStart.x() < 0) m_drawPosStart.setX(0);
		if (m_drawPosStart.y() < 0) m_drawPosStart.setY(0);
		if (m_drawPosStart.x() > width - 1) m_drawPosStart.setX(width - 1);
		if (m_drawPosStart.y() > height - 1) m_drawPosStart.setY(height - 1);

		m_isRightDown = true;
	}		
}
void GraphicsView::mouseMoveEvent(QMouseEvent *e)
{
	QGraphicsView::mouseMoveEvent(e);
	if (!(e->buttons() & Qt::RightButton))
		emit mousePositionSignal(mapToScene(e->pos())); //小图位置

	if (m_drawMode && m_isRightDown)
	{
		m_drawPosEnd = mapToScene(e->pos());
		int width = m_VecGraphicPixmapItem[0]->pixmap().width();
		int height = m_VecGraphicPixmapItem[0]->pixmap().height();
		if (m_drawPosEnd.x() < 0) m_drawPosEnd.setX(0);
		if (m_drawPosEnd.y() < 0) m_drawPosEnd.setY(0);
		if (m_drawPosEnd.x() > width - 1) m_drawPosEnd.setX(width - 1);
		if (m_drawPosEnd.y() > height - 1) m_drawPosEnd.setY(height - 1);
		m_rect.setX(m_drawPosStart.x() < m_drawPosEnd.x() ? m_drawPosStart.x() : m_drawPosEnd.x());
		m_rect.setY(m_drawPosStart.y() < m_drawPosEnd.y() ? m_drawPosStart.y() : m_drawPosEnd.y());
		m_rect.setWidth(abs(m_drawPosStart.x() - m_drawPosEnd.x()) + 1);
		m_rect.setHeight(abs(m_drawPosStart.y() - m_drawPosEnd.y()) + 1);
		emit DrawRectSignal(m_rect, m_curPen); //画矩形的信息传递回去 小图实时更新位置
		clearAllRoi();
		drawRect(m_rect, m_curPen);
	}
	else if (m_isLeftDown)
	{
		m_dragPosCur.setX(e->x());
		m_dragPosCur.setY(e->y());
		int dx = m_dragPosCur.x() - m_dragPosPre.x();
		int dy = m_dragPosCur.y() - m_dragPosPre.y();
		dx = double(dx) / (m_nCurScal);
		dy = double(dy) / (m_nCurScal);
		this->horizontalScrollBar()->setValue(horizontalScrollBar()->value() - dx);
		this->verticalScrollBar()->setValue(verticalScrollBar()->value() - dy);
		m_dragPosPre = m_dragPosCur;
	}

	QGraphicsPixmapItem  *itme = (QGraphicsPixmapItem *)scene()->mouseGrabberItem();
	if (itme != NULL) itme->setZValue(50);

	//更新状态栏pos信息 杜晓辉
	{
		QPointF pointNow = mapToScene(e->pos());
		QString pos = QString("(%1, %2)").arg(int(pointNow.x())).arg(int(pointNow.y()));
		if (m_VecGraphicPixmapItem.size() <= 0 || pointNow.x() < 0 || pointNow.y() < 0 ||
			pointNow.x() > m_VecGraphicPixmapItem[0]->pixmap().width() ||
			pointNow.y() > m_VecGraphicPixmapItem[0]->pixmap().height())
		{
			return;
		}			
		if (m_VecGraphicPixmapItem.size() == 0) return;
		QImage pix = m_VecGraphicPixmapItem[0]->pixmap().toImage();
		if (pix.isNull()) return;
		QRgb rgb = pix.pixel(pointNow.x(), pointNow.y());
		pos = pos + QString(" (%1, %2, %3)").arg(QColor(rgb).red()).arg(QColor(rgb).green()).arg(QColor(rgb).blue());
		emit PosChangeSignal(pos);
	}
}
void GraphicsView::mouseReleaseEvent(QMouseEvent *e)
{
	QGraphicsView::mouseReleaseEvent(e);
	QPointF imagePoint = mapToScene(e->pos());
	if (m_drawMode && m_isRightDown)
	{
		clearAllRoi();
		int width = m_VecGraphicPixmapItem[0]->pixmap().width();
		int height = m_VecGraphicPixmapItem[0]->pixmap().height();
		if (m_drawPosEnd.x() < 0) m_drawPosEnd.setX(0);
		if (m_drawPosEnd.y() < 0) m_drawPosEnd.setY(0);
		if (m_drawPosEnd.x() > width - 1) m_drawPosEnd.setX(width - 1);
		if (m_drawPosEnd.y() > height - 1) m_drawPosEnd.setY(height - 1);
		m_rect.setX(m_drawPosStart.x() < m_drawPosEnd.x() ? m_drawPosStart.x() : m_drawPosEnd.x());
		m_rect.setY(m_drawPosStart.y() < m_drawPosEnd.y() ? m_drawPosStart.y() : m_drawPosEnd.y());
		m_rect.setWidth(abs(m_drawPosStart.x() - m_drawPosEnd.x()) + 1);
		m_rect.setHeight(abs(m_drawPosStart.y() - m_drawPosEnd.y()) + 1);
		emit DrawRectSignal(m_rect, m_curPen); //画矩形的信息传递回去 小图实时更新位置
		drawRect(m_rect, m_curPen);
		m_isRightDown = false;
		emit DrawOneSignal();		
	}
	if (m_isLeftDown)
	{
		emit mouseClickSignal(imagePoint);
		m_isLeftDown = false;
	}
}
void GraphicsView::resizeEvent(QResizeEvent *event)
{
	if (m_nCurScal > 1)	return;
	SceneFitView();
}
void GraphicsView::mouseDoubleClickEvent(QMouseEvent *e)
{
	emit mouseDblClickSignal(mapToScene(e->pos()));
}

void GraphicsView::setDrawMode(bool state)
{
	m_drawMode = state; 
}
void GraphicsView::setDrawPen(QPen pen)
{
	m_curPen = pen;
}

void GraphicsView::setWheelEnabled(bool enable)
{
	m_enableWheelEvent = enable;
	m_nCurScal = m_nCurScal / 0.7f;
	scale(1 / 0.7, 1 / 0.7);//scale是连续缩放的
}

void GraphicsView::mousePositionSlot(QPointF m_CurrentPosition)
{
	int width = this->width() * 0.7;
	int height = this->height() * 0.7;
	QRectF rectScene;
	float x = m_CurrentPosition.x() ;
	float y = m_CurrentPosition.y();
	rectScene.setLeft(x - width / 2 < 0 ? 0 : x - width / 2);
	rectScene.setTop(y - height / 2 < 0 ? 0 : y - height / 2);
	rectScene.setWidth(width);
	rectScene.setHeight(height);
	this->setSceneRect(rectScene);
}
void GraphicsView::DrawRectSlot(QRect rect, QPen pen) { clearAllRoi(); drawRect(rect, pen); }

void GraphicsView::setImage(QImage img, int byIsZoomFit, bool bClear)
{
	if (img.isNull()) return;

	if (bClear) clearScene();

	QPixmap map = QPixmap::fromImage(img);
	clearAll();
	QGraphicsPixmapItem *pItem = m_scene->addPixmap(map);	
	m_VecGraphicPixmapItem.push_back(pItem);
	m_scene->setSceneRect(0, 0, img.width(), img.height());
	if (byIsZoomFit == 1) ZoomFit(img.width(), img.height());

	m_image = img;
	//m_VecGraphicPixmapItem[0]->show();
	//qDebug() << m_VecGraphicPixmapItem.size();
	//update();
}
void GraphicsView::setImage(QPixmap img, int byIsZoomFit, bool bClear)
{
	if (img.isNull()) return;

	if (bClear) clearScene();

	QPixmap map = img;
	clearAll();
	QGraphicsPixmapItem *pItem = m_scene->addPixmap(map);
	m_VecGraphicPixmapItem.push_back(pItem);
	m_scene->setSceneRect(0, 0, img.width(), img.height());
	if (byIsZoomFit == 1) ZoomFit(img.width(), img.height());

	m_image = map.toImage();
}


