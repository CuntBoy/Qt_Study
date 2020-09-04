#include "widget.h"
#include <QGraphicsView>
#include "graphicsscene.h"

GraphicsView::GraphicsView(QWidget *parent)
    : QGraphicsView(parent)
{
    GraphicsScene * scene_ = new GraphicsScene;
    this->setScene(scene_);
}

GraphicsView::~GraphicsView()
{
}

