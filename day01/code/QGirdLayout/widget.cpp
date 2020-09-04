#include "widget.h"
#include <QGridLayout>
#include <QPushButton>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QGridLayout *grid = new QGridLayout(this); // 默认指定它为布局管理器   可以不做设置
    //    this->setLayout(grid);

    QPushButton * pb0 = new QPushButton("pb0");
    QPushButton * pb1 = new QPushButton("pb1");
    QPushButton * pb2 = new QPushButton("pb2");
    QPushButton * pb3 = new QPushButton("pb3");
    QPushButton * pb4 = new QPushButton("pb4");

    // 布局在多少行 多少列 占多少行 多少列
    grid->setRowStretch(0,1);
    grid->setRowStretch(3,1);
    grid->setColumnStretch(0,1);
    grid->setColumnStretch(4,1);

    grid->addWidget(pb0,1,1,1,1);
    grid->addWidget(pb1,1,2,1,1);
    grid->addWidget(pb2,1,3,1,1);
    grid->addWidget(pb3,2,1,1,1);
    grid->addWidget(pb4,2,2,1,2);




//    QPushButton * pb1 = new QPushButton("pb1");
//    QPushButton * pb2 = new QPushButton("pb2");
}

Widget::~Widget()
{
}

