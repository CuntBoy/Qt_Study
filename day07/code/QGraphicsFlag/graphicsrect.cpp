#include "graphicsrect.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>
#include <QPen>
#include <QPointF>
#include <QKeyEvent>

GraphicsRect::GraphicsRect(QGraphicsItem *parent)
    :QGraphicsRectItem(parent)
{
    this->setRect(-50,-50,100,100);
    this->setBrush(QBrush(Qt::yellow));
    this->setPen(QPen(Qt::red));
    this->setPos(100,0);

    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
}

GraphicsRect::~GraphicsRect()
{
    qDebug()<<__FUNCTION__<<endl;
}

void GraphicsRect::keyPressEvent(QKeyEvent *ev)
{
    qDebug()<<__FUNCTION__<<endl;
    switch (ev->key()) {
    case Qt::Key_A:
        qDebug()<<__FUNCTION__<<"Key A"<<endl;
        break;
    case Qt::Key_B:
        qDebug()<<__FUNCTION__<<"Key B"<<endl;
        break;
    case Qt::Key_C:
        qDebug()<<__FUNCTION__<<"Key C"<<endl;
        break;
    case Qt::Key_D:
        qDebug()<<__FUNCTION__<<"Key D"<<endl;
        break;
    default:
        break;
    }
}


void GraphicsRect::keyReleaseEvent(QKeyEvent *ev)
{
    qDebug()<<__FUNCTION__<<endl;
}

