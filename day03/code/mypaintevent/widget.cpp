#include "widget.h"
#include <QPainter>
#include <QDialog>
#include <QPushButton>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent),background_(Qt::red)
{
    QDialog * ctrldia = new QDialog(this);
    QHBoxLayout * hbox = new QHBoxLayout(ctrldia);

    QPushButton * pb = new QPushButton("blue");
    hbox->addWidget(pb);

    QPushButton * pb1 = new QPushButton("update blue");
    hbox->addWidget(pb1);

    QPushButton * pb2 = new QPushButton("repaint yellow");
    hbox->addWidget(pb2);

    connect(pb,SIGNAL(clicked()),this,SLOT(setBlueSlot()));
    connect(pb1,SIGNAL(clicked()),this,SLOT(UpdateBlueSlot()));
    connect(pb2,SIGNAL(clicked()),this,SLOT(repaintSlot()));
    ctrldia->show();
}
void Widget::repaintSlot()
{
    background_ = Qt::yellow;
    this->repaint(0,0,100,100);
}

void Widget::setBlueSlot()
{
    background_ = Qt::blue;

}
void Widget::UpdateBlueSlot()
{
    background_ = Qt::blue;
    this->update();
}


void Widget::paintEvent(QPaintEvent * pevent)
{
    QPainter painter;
    painter.begin(this);
//    painter.setPen(background_);
    painter.setBrush(background_);
//    painter.drawRect(100,100,200,200);
    painter.drawRect(this->rect());

    painter.end();

}


Widget::~Widget()
{
}

