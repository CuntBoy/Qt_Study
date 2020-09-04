#include "widget.h"
#include <QPushButton>
#include <QLayout>      //布局管理器
#include <QHBoxLayout>  //水平布局管理器
#include <QVBoxLayout>  // 垂直方向布局管理器
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
#if 0
    QHBoxLayout * hbox = new QHBoxLayout(this);
    this->setLayout(hbox);   //赋予布局权限

    QPushButton * pb0 = new QPushButton("pb0");
    QPushButton * pb1 = new QPushButton("pb1");
    QPushButton * pb2 = new QPushButton("pb2");

    pb0->setMinimumWidth(10);  //设置最小缩放值
    pb0->setMaximumWidth(200);

    hbox->addWidget(pb0,1);   // 默认托管内存  默认伸缩因素是0
    hbox->addWidget(pb1,1);
    hbox->addSpacing(50);     // 添加间隙
    hbox->addWidget(pb2,1);
    hbox->addStretch(1);     //添加伸缩因素



    hbox->setMargin(0);      // 修改边框
    hbox->setSpacing(0);     // 控件之间的间隙
//    this->resize(200,100);
//    this->size()   不推荐在此位置使用  show() 之后使用更有意义 默认是 600 * 480

    qDebug() << this->sizeHint()<<endl;   // 此函数只能在使用布局管理器后使用

# endif
    QVBoxLayout * vbox = new QVBoxLayout(this);
    this->setLayout(vbox);   //赋予布局权限

    QPushButton * pb0 = new QPushButton("pb0");
    QPushButton * pb1 = new QPushButton("pb1");
    QPushButton * pb2 = new QPushButton("pb2");

//    pb0->setMinimumWidth(10);  //设置最宽缩放值
//    pb0->setMaximumWidth(200);

    pb0->setMinimumHeight(10);
    pb0->setMaximumHeight(200);

    vbox->addWidget(pb0,1);   // 默认托管内存  默认伸缩因素是0
    vbox->addWidget(pb1,1);
//    vbox->addSpacing(50);     // 添加间隙
    vbox->addWidget(pb2,1);
//    vbox->addStretch(1);     //添加伸缩因素



    vbox->setMargin(0);      // 修改边框
    vbox->setSpacing(0);     // 控件之间的间隙
//    this->resize(200,100);
//    this->size()   不推荐在此位置使用  show() 之后使用更有意义 默认是 600 * 480

    qDebug() << this->sizeHint()<<endl;   // 此函数只能在使用布局管理器后使用



}

Widget::~Widget()
{
}

