#include "widget.h"
#include <QDebug>
#include <QPalette>
#include <QCloseEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}
void Widget::enterEvent(QEvent * ev)
{
    qDebug()<<__FUNCTION__<<endl;
    QPalette pal = this->palette();
    pal.setColor(QPalette::Background,Qt::red);
    this->setPalette(pal);

}
void Widget::leaveEvent(QEvent * ev)
{
    QPalette pal = this->palette();
    pal.setColor(QPalette::Background,Qt::white);
    this->setPalette(pal);
    qDebug()<<__FUNCTION__<<endl;
}
void Widget::closeEvent(QCloseEvent * ev)
{
    qDebug()<<__FUNCTION__<<endl;
//    ev->ignore();
    ev->accept();
}


Widget::~Widget()
{
}

