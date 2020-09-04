#include "widget.h"
#include <QDebug>
#include <QMouseEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //this->setMouseTracking(true);   //设置鼠标可跟踪 可以不按键跟踪鼠标
}
void Widget::wheelEvent(QWheelEvent * event)
{
    qDebug()<<__FUNCTION__<<event->angleDelta()<<endl;  // 滚动角度
}


void Widget::mouseMoveEvent(QMouseEvent * event)
{
    qDebug()<<__FUNCTION__<<event->pos()<<event->button()<<endl;
}


void Widget::mousePressEvent(QMouseEvent * event)
{
    //    qDebug()<<__FUNCTION__<<endl;
    switch(event->button())
    {
    case Qt::LeftButton:
        qDebug()<<__FUNCTION__<<"Qt::LeftButton"<<endl;
        break;
    case Qt::RightButton:
        qDebug()<<__FUNCTION__<<"Qt::RightButton"<<endl;
        break;
    case Qt::MiddleButton:
        qDebug()<<__FUNCTION__<<"Qt::MiddleButton"<<endl;
        break;
    default:
        break;
    }
}

void Widget::mouseReleaseEvent(QMouseEvent * event)
{
    //    qDebug()<<__FUNCTION__<<endl;
    switch(event->button())
    {
    case Qt::LeftButton:
        qDebug()<<__FUNCTION__<<"Qt::LeftButton"<<endl;
        break;
    case Qt::RightButton:
        qDebug()<<__FUNCTION__<<"Qt::RightButton"<<endl;
        break;
    case Qt::MiddleButton:
        qDebug()<<__FUNCTION__<<"Qt::MiddleButton"<<endl;
        break;
    default:
        break;
    }
}

Widget::~Widget()
{
}

