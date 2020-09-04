#include "widget.h"
#include <QPushButton>
#include "pushbutton.h"


//父子窗口是对象之间的组合关系  父子类继承关系
Widget::Widget(QWidget *parent) : QWidget(parent)
{
//    QPushButton * pb = new QPushButton;
//    pb->setParent(this);
//    pb->setText("按钮");

//    new QPushButton("按钮", this);
    PushButton * pb =  new PushButton("button", this);
    pb->deleteLater();
}

//Qt 有自己的内存管理机制 只要是继承至QObject的对象都可以通过指定一个QObjetct的父对象来托管他的内存
//Widget::~Widget(){}
