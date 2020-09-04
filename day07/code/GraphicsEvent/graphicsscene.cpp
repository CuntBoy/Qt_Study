#include "graphicsscene.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include "graphicsrect.h"

GraphicsScene::GraphicsScene(QObject *parent)
    :QGraphicsScene(parent)
{
    this->addLine(-500,0,500,0,QPen(Qt::red));
    this->addLine(0,-500,0,500,QPen(Qt::red));
    this->addSimpleText("O(0,0)");
    this->addSimpleText("X")->setPos(400,0);
    this->addSimpleText("y")->setPos(0,400);


    GraphicsRect * rect = new GraphicsRect;
    this->addItem(rect);

}
GraphicsScene::~GraphicsScene()
{

}

void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug()<<__FUNCTION__<<" Scene "<<event->pos()<<event->scenePos()<<endl;
    QGraphicsScene::mousePressEvent(event);
}

void GraphicsScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug()<<__FUNCTION__<<" Scene Double Click"<<event->pos()<<event->scenePos()<<endl;
    QGraphicsScene::mouseDoubleClickEvent(event);
}

void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug()<<__FUNCTION__<<" scene  release "<<event->pos()<<endl;
    QGraphicsScene::mouseReleaseEvent(event);

}
