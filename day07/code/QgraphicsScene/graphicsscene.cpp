#include "graphicsscene.h"
#include <QGraphicsLineItem>
#include <QDebug>

GraphicsScene::GraphicsScene(QObject *parent)
    :QGraphicsScene(parent)
{
    // 场景坐标系
    this->addLine(-500,0,500,0,QPen(Qt::red));
    this->addLine(0,-500,0,500,QPen(Qt::red));
    this->addSimpleText("O(0,0)");
    this->addSimpleText("X")->setPos(400,0);
    this->addSimpleText("Y")->setPos(0,400);
    //绘制矩形
    QGraphicsRectItem * rect =  this->addRect(-50,-50,100,100);

    rect->setPos(100,0);

}

GraphicsScene::~GraphicsScene()
{
    qDebug()<<__FUNCTION__<<endl;
}
