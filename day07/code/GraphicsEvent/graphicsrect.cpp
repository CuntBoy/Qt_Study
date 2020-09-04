#include "graphicsrect.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>
#include <QPen>
#include <QPointF>

GraphicsRect::GraphicsRect(QGraphicsItem *parent)
    :QGraphicsRectItem(parent),isPress_(false)
{
    this->setRect(-50,-50,100,100);
    this->setBrush(QBrush(Qt::yellow));
    this->setPen(QPen(Qt::red));
    this->setPos(100,0);
    this->setAcceptHoverEvents(true);
}

GraphicsRect::~GraphicsRect()
{
    qDebug()<<__FUNCTION__<<endl;
}

void GraphicsRect::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    point_ = event->pos();
    isPress_ = true;

//    QGraphicsRectItem::mousePressEvent(event);
    qDebug()<<__FUNCTION__<<" item press "<<event->pos()<<endl;
}

void GraphicsRect::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    isPress_ = false;
//    qDebug()<<__FUNCTION__<<" Item release "<<event->pos()<<endl;
    QGraphicsRectItem::mouseReleaseEvent(event);
}



void GraphicsRect::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug()<<__FUNCTION__<<" Item release "<<event->pos()<<endl;
    if(isPress_)
    {
        this->setPos(this->pos()+ (event->pos() - point_));
        qDebug()<<__FUNCTION__<<event->pos()<<endl;
    }

}

void GraphicsRect::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    isPress_ = false;
    qDebug()<<__FUNCTION__<<" Item Double Click"<<event->scenePos()<<endl;
    QGraphicsRectItem::mouseDoubleClickEvent(event);
}

void GraphicsRect::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    qDebug()<<__FUNCTION__<<" Item Wheel"<<event->delta()<<endl;
}

void GraphicsRect::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    qDebug()<<__FUNCTION__<<"come in"<<endl;
}

void GraphicsRect::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    isPress_ = false;
    qDebug()<<__FUNCTION__<<"go out"<<endl;
}

void GraphicsRect::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
    qDebug()<<__FUNCTION__<<event->pos()<<endl;

}
