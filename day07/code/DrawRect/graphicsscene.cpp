#include "graphicsscene.h"
#include <QGraphicsItem>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>

GraphicsScene::GraphicsScene(QObject *parent)
    :QGraphicsScene(parent),isLeftPress_(false)
{

}

GraphicsScene::~GraphicsScene()
{
    qDebug()<<__FUNCTION__<<endl;
}

void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        isLeftPress_ = true;
    }
    QGraphicsScene::mousePressEvent(event);
}

void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        this->addRect(QRectF(event->buttonDownScenePos(Qt::LeftButton),event->scenePos()))->setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable);
        isLeftPress_ = false;
    }
    else if(event->button() == Qt::RightButton)
    {
        QList<QGraphicsItem *> items  = this->selectedItems();
        foreach (QGraphicsItem * item, items)
        {
            this->removeItem(item);
        }
    }
    QGraphicsScene::mouseReleaseEvent(event);
}

void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
//    event->buttonDownPos(Qt::LeftButton);
    qDebug()<<__FUNCTION__<<event->buttonDownScenePos(Qt::LeftButton)<<event->button()<<endl;
    QGraphicsScene::mouseMoveEvent(event);
}
