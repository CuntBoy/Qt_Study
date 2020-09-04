#include "widget.h"
#include "graphicsscene.h"

GraphicsView::GraphicsView(QWidget *parent)
    : QGraphicsView(parent)
{
    this->setScene(new GraphicsScene);
}

GraphicsView::~GraphicsView()
{
}

