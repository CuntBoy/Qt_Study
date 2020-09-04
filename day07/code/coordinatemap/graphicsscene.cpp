#include "graphicsscene.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>

GraphicsScene::GraphicsScene(QObject *parent)
    :QGraphicsScene(parent)
{
    this->addLine(-500,0,500,0,QPen(Qt::red));
    this->addLine(0,-500,0,500,QPen(Qt::red));
    this->addSimpleText("O(0,0)");
    this->addSimpleText("X")->setPos(400,0);
    this->addSimpleText("y")->setPos(0,400);
//    QGraphicsRectItem * rect1 = this->addRect(0,0,100,100,QPen(Qt::red));
    QGraphicsRectItem * rect = this->addRect(0,0,100,100,QPen(Qt::blue));
    QPoint point(10,10);

    rect->setPos(100,100);
    rect->mapToScene(point);
    qDebug()<<"scen point from item  to scene"<<rect->mapFromScene(point)<<endl;
}
GraphicsScene::~GraphicsScene()
{

}
