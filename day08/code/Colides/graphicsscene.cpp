#include "graphicsscene.h"
#include <QGraphicsLineItem>
#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

GraphicsScene::GraphicsScene(QObject *parent)
    :QGraphicsScene(parent)
{
    rect_ = this->addRect(0,0,100,100,QPen(Qt::red));
    rect_->setFlags(QGraphicsItem::ItemIsMovable);  //QGraphicsItem::ItemIsSelectable|
    rect_->setPos(200,0);
    ellipse_ = this->addEllipse(0,0,100,100,QPen(Qt::red));
    ellipse_->setPos(0,100);
    ellipse_->setFlags(QGraphicsItem::ItemIsMovable);
//    this->addRect(0,0,100,100)->setPos(100,100);


}

void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug()<<__FUNCTION__<<" Scene "<<endl;

    qDebug()<<" Point rect_"<< event->scenePos() <<"was contains  Item "
           <<rect_->contains(rect_->mapFromScene(event->scenePos()))<<endl;

    qDebug()<<" Point ellipse_ "<< event->scenePos() <<"was contains  Item "
           <<ellipse_->contains(ellipse_->mapFromScene(event->scenePos()))<<endl;

    qDebug()<<" coll "<<rect_->collidesWithItem(ellipse_)<<endl;

    QGraphicsScene::mousePressEvent(event);
}

void GraphicsScene::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<__FUNCTION__<<" Scene "<<endl;
    QGraphicsScene::keyPressEvent(event);
}



GraphicsScene::~GraphicsScene()
{
    qDebug()<<__FUNCTION__<<endl;
}


