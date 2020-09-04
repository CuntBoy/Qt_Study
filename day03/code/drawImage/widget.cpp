#include "widget.h"
#include <QPainter>
#include <QImage>   // 加载图片
#include <QPixmap>  // 加载图片

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    pixmap_ = new QPixmap("E:/Study/My_C++/Qt_study/day03/source/L.jpg");    // 会根据硬件设备优化
    image_ = new QImage("E:/Study/My_C++/Qt_study/day03/source/L.jpg");      // 提供像素级别的图像  消耗大 效率低
}


void Widget::paintEvent(QPaintEvent * pevent)
{
    QPainter painter;
    painter.begin(this);
//    *pixmap_ =  pixmap_->scaled(this->width(),this->height(),
//                                Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation);
//    painter.drawPixmap(0,0,pixmap_->scaled(this->width(),this->height(),
//                                           Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation));

    painter.drawImage(0,0,image_->scaled(this->width(),this->height(),Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation));



    painter.end();

}

Widget::~Widget()
{
    delete pixmap_;
}

