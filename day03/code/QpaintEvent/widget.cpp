#include "widget.h"
#include <QDebug>
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}

void Widget::paintEvent(QPaintEvent * pev)
{
    static int i = 0;
    qDebug()<<i++<<__FUNCTION__<<endl;
    QPainter painter;
    painter.begin(this);
    //线条
//    painter.setPen(QPen(Qt::blue,5,Qt::DashDotLine));
//    painter.drawLine(0,0,200,100);
    // 长方形
//    painter.setPen(QPen(Qt::red,6));
//    painter.setBrush(QBrush(Qt::blue,Qt::Dense1Pattern));
//    painter.setBrush(QBrush(Qt::blue));
//    painter.drawRect(100,100,100,200);
    // 圆
//    painter.drawEllipse(200,100,100,200);

//    painter.drawText(100,100,"Helloworld");


//    painter.end();
    painter.setPen(QPen(Qt::red,1));
    painter.setBrush(Qt::red);
    painter.drawRect(100,100,100,100);
//    painter.rotate(10);      // 旋转
//    painter.scale(0.5,0.5);  //缩放
//    painter.translate(100,0);   // 改变原点
//    painter.setPen(QPen(Qt::blue,5));
//    painter.drawRect(100,100,100,100);

    painter.save();
    painter.setPen(Qt::blue);
    painter.setBrush(Qt::blue);
    painter.drawRect(200,100,100,100);
    painter.restore();




    painter.end();

}

Widget::~Widget()
{
}

