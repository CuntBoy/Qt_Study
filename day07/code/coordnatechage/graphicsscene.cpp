#include "graphicsscene.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>
#include <QTransform>

GraphicsScene::GraphicsScene(QObject *parent)
    :QGraphicsScene(parent)
{
    this->addLine(-500,0,500,0,QPen(Qt::red));
    this->addLine(0,-500,0,500,QPen(Qt::red));
    this->addSimpleText("O(0,0)");
    this->addSimpleText("X")->setPos(400,0);
    this->addSimpleText("y")->setPos(0,400);

    QGraphicsRectItem * rect = this->addRect(0,0,100,100,QPen(Qt::yellow,3));
    rect->setPos(100,100);
    QGraphicsLineItem * line_1 = new QGraphicsLineItem(-100,0,100,0,rect);
    QGraphicsLineItem * line_2 = new QGraphicsLineItem(0,-100,0,100,rect);

    QTransform transform;
    transform.rotate(10);
    rect->setTransform(transform);




}
GraphicsScene::~GraphicsScene()
{

}
