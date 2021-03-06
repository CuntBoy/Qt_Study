#include "graphicsscene.h"
#include <QGraphicsLineItem>
#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QPixmap>
#include <QPainter>


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

    printScene();


}

void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug()<<__FUNCTION__<<" Scene "<<endl;

//    qDebug()<<" Point rect_"<< event->scenePos() <<"was contains  Item "
//           <<rect_->contains(rect_->mapFromScene(event->scenePos()))<<endl;

//    qDebug()<<" Point ellipse_ "<< event->scenePos() <<"was contains  Item "
//           <<ellipse_->contains(ellipse_->mapFromScene(event->scenePos()))<<endl;

//    qDebug()<<" coll "<<rect_->collidesWithItem(ellipse_)<<endl;

    QGraphicsScene::mousePressEvent(event);
}

void GraphicsScene::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<__FUNCTION__<<" Scene "<<endl;
    QGraphicsScene::keyPressEvent(event);

}

// 输出场景
void GraphicsScene::printScene()
{
    QPixmap pixmap_(this->itemsBoundingRect().size().toSize());//,Qt::IgnoreAspectRatio,Qt::SmoothTransformation
//    pixmap_.scaled((this->itemsBoundingRect().size()).toSize(),
//                   Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    pixmap_.fill("#00000000");
    QPainter painter;
    painter.begin(&pixmap_);
    this->render(&painter);
    pixmap_.save("E:/Study/My_C++/Qt_study/day08/source/a.png");

    painter.end();
}




GraphicsScene::~GraphicsScene()
{
    qDebug()<<__FUNCTION__<<endl;
}


