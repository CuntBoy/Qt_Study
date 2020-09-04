#include "widget.h"
#include "graphicsscene.h"
#include <QDebug>

GraphicsView::GraphicsView(QWidget *parent)
    :QGraphicsView(parent)
{

    scene_ = new GraphicsScene(this);
    this->setScene(scene_);
//    qDebug()<<"scen point to view map"<<this->mapFromScene(point)<<endl;
}

void GraphicsView::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    QPoint point(10,10);
    qDebug()<<"scen point to view map"<<this->mapFromScene(point)<<endl;
}

GraphicsView::~GraphicsView()
{
    delete scene_;
    scene_ = nullptr;
}



