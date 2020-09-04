#include "widget.h"
#include <QDebug>
#include <QEvent>
#include "pushbutton.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    new PushButton("button",this);
}

bool Widget::event(QEvent * event)
{
    static int i = 0;
//    qDebug()<<__FUNCTION__<<endl;
    if(event->type() == QEvent::MouseButtonPress |QEvent::MouseButtonDblClick)
    {
        qDebug()<<i++<<"Widget ==> QEvent::MouseButtonPress"<<endl;
        //return true;    // 处理这个事件
    }
    return QWidget::event(event);
}

void Widget::mousePressEvent(QMouseEvent * event)
{
    static int i = 0;
    qDebug()<<i++<<__FUNCTION__<<endl;
}

Widget::~Widget()
{
}

