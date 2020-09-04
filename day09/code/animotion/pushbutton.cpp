#include "pushbutton.h"
#include <QPixmap>
#include <QList>
#include <QPainter>
#include <QPropertyAnimation>
#include <QDebug>

#define PIXMAP_COUNT 10
PushButton::PushButton(QWidget *parent)
    :QPushButton(parent),index_(0)
{
    QPixmap pixmap(":pic/pic/images/animotion.png");
    int width = pixmap.width() / PIXMAP_COUNT;
    int height = pixmap.height();
    this->setFixedSize(width,height);
    for(int i =0 ;i < PIXMAP_COUNT;i++)
    {
        list_.append(pixmap.copy(i*width,0,width,height));

    }
    animotion_ = new QPropertyAnimation(this,"");
    animotion_->setDuration(1000);   // 持续时间
    animotion_->setStartValue(0);
    animotion_->setEndValue(PIXMAP_COUNT - 1);

    connect(animotion_,SIGNAL(valueChanged(QVariant)),this,SLOT(valuechangeSlot(QVariant)));


}

void PushButton::enterEvent(QEvent *event)
{
    animotion_->setDirection(QAbstractAnimation::Forward);
    animotion_->start();
}

void PushButton::leaveEvent(QEvent *event)
{
    animotion_->setDirection(QAbstractAnimation::Backward);
    if(animotion_->state()!=QAbstractAnimation::Running)
        animotion_->start();
}

void PushButton::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.drawPixmap(0,0,list_[index_]);

    //    QPushButton::paintEvent(event);
}

void PushButton::valuechangeSlot(QVariant value)
{
    index_ = value.toInt();
    qDebug()<<value<<endl;
    update();
}
