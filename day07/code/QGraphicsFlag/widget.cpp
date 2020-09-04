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


GraphicsView::~GraphicsView()
{
    delete scene_;
    scene_ = nullptr;
}



