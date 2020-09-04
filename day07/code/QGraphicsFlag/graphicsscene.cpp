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
    rect->setFlag(QGraphicsItem::ItemIsMovable);

    this->addRect(0,0,100,100)->setFlag(QGraphicsItem::ItemIsMovable);

}
GraphicsScene::~GraphicsScene()
{

}

