#include "widget.h"
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>  //水平

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QGridLayout *grid = new QGridLayout(this); // 默认指定它为布局管理器   可以不做设置
    //    this->setLayout(grid);
    QHBoxLayout *hbox = new QHBoxLayout;

    QPushButton * pb0 = new QPushButton("pb0");
    QPushButton * pb1 = new QPushButton("pb1");
    QPushButton * pb2 = new QPushButton("pb2");
    QPushButton * pb3 = new QPushButton("pb3");
    QPushButton * pb4 = new QPushButton("pb4");

    // 布局在多少行 多少列 占多少行 多少列
//    grid->setRowStretch(0,1);
//    grid->setRowStretch(3,1);
//    grid->setColumnStretch(0,1);
//    grid->setColumnStretch(4,1);


    grid->addWidget(pb0,0,0,1,1);
    grid->addWidget(pb1,0,1,1,1);
    grid->addWidget(pb2,0,2,1,1);
    grid->addLayout(hbox,1,0,1,3);
    hbox->addWidget(pb3);
    hbox->addWidget(pb4);

//    grid->addWidget(pb3,1,0,1,1);
//    grid->addWidget(pb4,1,1,1,2);
}

Widget::~Widget()
{
}

