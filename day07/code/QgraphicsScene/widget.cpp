#include "widget.h"
#include "graphicsscene.h"
#include <QDebug>

GraphicsView::GraphicsView(QWidget *parent)
    : QGraphicsView(parent)
{
    GraphicsScene * scene = new GraphicsScene(this);
    this->setScene(scene);
}

GraphicsView::~GraphicsView()
{
    qDebug()<<__FUNCTION__<<endl;
}

