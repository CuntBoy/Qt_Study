#include "widget.h"
#include "graphicsscene.h"
#include <QDebug>
#include <QMouseEvent>
#include <QGraphicsView>

GraphicsView::GraphicsView(QWidget *parent)
    :QGraphicsView(parent)
{
    scene_ = new GraphicsScene(this);
    this->setScene(scene_);
}

void GraphicsView::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<__FUNCTION__<<" View "<<event->pos()<<endl;
    QGraphicsView::mousePressEvent(event);
}

GraphicsView::~GraphicsView()
{
    delete scene_;
    scene_ = nullptr;
}



