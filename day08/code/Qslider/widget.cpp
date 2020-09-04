#include "widget.h"
#include <QHBoxLayout>
#include <QSlider>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout *hbox = new QHBoxLayout(this);
    QSlider *slider = new QSlider;
    slider->setOrientation(Qt::Horizontal);
    slider->setMaximum(0);
    slider->setMaximum(100);
    slider->setValue(50);

//    connect(slider,SIGNAL(valueChanged(int)),this,SLOT(valueChangeSlot(int)));

    // error
    connect(slider,QSlider::sliderReleased,[&](){qDebug()<<"slider release "<<slider->value()<<endl;});
    hbox->addWidget(slider);

}

Widget::~Widget()
{
}

void Widget::valueChangeSlot(int num)
{
    qDebug()<<__FUNCTION__<<num<<endl;
}

