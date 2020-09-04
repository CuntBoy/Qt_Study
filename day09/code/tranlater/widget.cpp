#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug()<<QApplication::translate("Widget","tea",0)<<endl;  // 可以使用 tr

}

Widget::~Widget()
{
    delete ui;
}

