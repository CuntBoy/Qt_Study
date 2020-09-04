#include "widget.h"
#include <QLabel>       // 标签
#include <QLineEdit>    // 行编辑器
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("Hello");

    QLabel * label = new QLabel(this);
    label->setText("HelloWorld");

    edit = new QLineEdit("hello world",this);
    edit->move(100,0);

    QPushButton * pb = new QPushButton("type",this);
    pb->move(0,100);

    connect(pb,SIGNAL(clicked()),this,SLOT(printSlot()));

}

void Widget::printSlot()
{
    qDebug()<<edit->text()<<endl;
}


Widget::~Widget()
{
}

