#include "widget.h"
#include <pushbutton.h>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    PushButton * pb = new PushButton("pb",this);
}

bool Widget::event(QEvent * event)
{
    qDebug()<<__FUNCTION__<<endl;
}

Widget::~Widget()
{
}

