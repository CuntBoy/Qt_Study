#include "widget.h"
#include "./graphicsscene.h"
#include <QDebug>
//#include <QPushButton>

#include <QTransform>
GraphicsView::GraphicsView(QWidget *parent)
    :QGraphicsView(parent)
{

    scene_ = new GraphicsScene(this);
    this->setScene(scene_);

//    QTransform transform;
//    transform.rotate(10);
//    transform.scale(0.5,0.5);
//    transform.shear(1,2);
//    this->setTransform(transform);
//    QPushButton * pb = new QPushButton(this);
//    pb->move(200,0);
}

void GraphicsView::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    QPoint point(10,10);

    qDebug()<<"scen point(10,10) map to view "<<this->mapFromScene(point)<<endl;
    qDebug()<<"view point(10,10) map to scene "<<this->mapToScene(point)<<endl;
}

GraphicsView::~GraphicsView()
{
    delete scene_;
    scene_ = nullptr;
}



