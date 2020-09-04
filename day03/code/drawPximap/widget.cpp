#include "widget.h"
#include <QPainter>
#include <QImage>   // 加载图片
#include <QPixmap>  // 加载图片
#include <QPushButton>
#include <QDialog>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    pixmap_ = new QPixmap(this->size()); // "E:/Study/My_C++/Qt_study/day03/source/L.jpg"
    pixmap_->fill(QColor("#00000000"));
    QDialog * ctrldia = new QDialog(this);
    QHBoxLayout * hbox = new QHBoxLayout(ctrldia);
    QPushButton * pb = new QPushButton("drawpixmap",ctrldia);
    hbox->addWidget(pb);
    connect(pb,SIGNAL(clicked()),this,SLOT(drawpixmapslot()));
    ctrldia->show();
}


void Widget::paintEvent(QPaintEvent * pevent)
{
    QPainter painter;
    painter.begin(this);
    painter.drawPixmap(0,0,*pixmap_);
    painter.end();

}

void Widget::drawpixmapslot()
{
    QPainter painter;
    painter.begin(pixmap_);
    painter.setPen(QPen(Qt::red,6));
    painter.setBrush(QBrush(Qt::blue));
    painter.drawLine(0,0,200,100);
    painter.drawRect(100,100,100,200);
    painter.drawEllipse(200,100,100,200);
    painter.drawText(100,100,"Helloworld");
    painter.end();
    pixmap_->save("E:/Study/My_C++/Qt_study/day03/source/text.jpg");
    this->update();
}

Widget::~Widget()
{
    delete pixmap_;
}

