#include "widget.h"
#include <QDebug>
#include <QPainter>
#include <QImage>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(680,480);
    image_ = new QImage(this->size(),QImage::Format_ARGB32_Premultiplied);
//    image_->fill(QColor(Qt::red));
    QPushButton * pb = new QPushButton("pb",this);
    connect(pb,SIGNAL(clicked()),this,SLOT(drawImageSlot()));


}

void Widget::paintEvent(QPaintEvent * event)
{
    qDebug()<<__FUNCTION__<<endl;
    QPainter painter;
    painter.begin(this);
    painter.drawImage(0,0,*image_);
    painter.end();

}

void Widget::drawImageSlot()
{
    QPainter painter;
    painter.begin(image_);
    painter.setPen(Qt::red);
    painter.setBrush(Qt::green);
    painter.drawLine(0,0,100,100);
    painter.drawRect(100,100,100,100);
    painter.drawImage(200,200,QImage("E:/Study/My_C++/Qt_study/day04/source/L.jpg").scaled(100,100,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    painter.end();
    this->update();
}


Widget::~Widget()
{
}

