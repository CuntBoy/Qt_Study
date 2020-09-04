#include "widget.h"
#include <QPainter>
#include <QPixmap>
#include <QMouseEvent>
#include <QDebug>
#include <QMenu>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    menu_ = new QMenu(this);
    menu_->addAction("close",this,SLOT(close()));


}

void Widget::mousePressEvent(QMouseEvent * ev)
{
    if(ev->button() == Qt::LeftButton)
        //    qDebug()<<ev->pos()<<endl;
        pos_press = ev->pos();
    else if(ev->button() == Qt::RightButton)
    {
//        menu_->move(this->cursor().pos());
//        menu_->show();
        menu_->exec(QCursor::pos());

    }
}

void Widget::mouseMoveEvent(QMouseEvent * ev)
{
    //    if(ev->button() == Qt::LeftButton)
    this->move(this->pos()+(ev->pos()-pos_press));
    //    qDebug()<<ev->pos()<<endl;
}

void Widget::paintEvent(QPaintEvent * event)
{
    QPainter painter;
    painter.begin(this);
    painter.drawPixmap(0,0,QPixmap("E:/Study/My_C++/Qt_study/day04/source/wallet.jpg"));
    painter.end();

}

Widget::~Widget()
{
}

