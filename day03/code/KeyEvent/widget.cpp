#include "widget.h"
#include <QDebug>
#include <QKeyEvent>
#include "pushbutton.h"
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout * hbox = new QHBoxLayout(this);
    PushButton *pb = new PushButton("test",this);
    PushButton *pb1 = new PushButton("test1",this);
    hbox->addWidget(pb);
    hbox->addWidget(pb1);
    this->setFocus(Qt::OtherFocusReason);  // 设置焦点窗口
}

void Widget::keyPressEvent(QKeyEvent * keyevent)
{
//    qDebug()<<__FUNCTION__<<endl;
//    qDebug()<<keyevent->text()<<endl;
    if(keyevent->modifiers() & Qt::ControlModifier)  // 判断修饰键
            qDebug()<<"ControlModifier press"<<endl;
    if(keyevent->modifiers() & Qt::ShiftModifier)  // 判断修饰键
            qDebug()<<"ShiftModifier press"<<endl;
    if(keyevent->modifiers() & Qt::AltModifier)  // 判断修饰键
            qDebug()<<"AltModifier press"<<endl;
//    qDebug()<<keyevent->key()<<endl;
    switch (keyevent->key())
    {
    case Qt::Key_A:
        qDebug()<<"key A press"<<endl;
        break;
    case Qt::Key_B:
        qDebug()<<"key B press"<<endl;
        break;
    default:
        break;
    }



}

void Widget::keyReleaseEvent(QKeyEvent *keyevent)
{
//    qDebug()<<__FUNCTION__<<endl;
//    qDebug()<<keyevent->text()<<endl;  // 输出获取的按键的值
    switch (keyevent->key())
    {
    case Qt::Key_A:
        qDebug()<<"Key A release"<<endl;
        break;
    case Qt::Key_B:
        qDebug()<<"Key B release"<<endl;
        break;
    default:
        break;
    }
}

Widget::~Widget()
{
}

