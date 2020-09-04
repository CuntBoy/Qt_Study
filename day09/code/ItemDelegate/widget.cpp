#include "widget.h"
#include <QStandardItemModel>
#include <QDebug>
#include <QHeaderView>
#include <QTableView>
#include "itemdelegate.h"

Widget::Widget(QWidget *parent)
    : QTableView(parent)
{
    QStandardItemModel * model = new QStandardItemModel(this);
    ItemDelegate * delegate = new ItemDelegate(this);
    this->resize(600,400);

    this->setModel(model);
    this->setItemDelegate(delegate);

    model->setColumnCount(3);
    model->setHeaderData(0,Qt::Horizontal,"Name");
    model->setHeaderData(1,Qt::Horizontal,"Age");
    model->setHeaderData(2,Qt::Horizontal,"Birthday");

    model->setRowCount(2);
    model->setHeaderData(0,Qt::Vertical,"记录一");
    model->setHeaderData(1,Qt::Vertical,"记录二");

    model->setItem(0,0,new QStandardItem("张三"));
    model->setItem(0,1,new QStandardItem("20"));
    model->setItem(0,2,new QStandardItem("2010-12-01"));
    model->setItem(1,0,new QStandardItem("王五"));
    model->setItem(1,1,new QStandardItem("20"));
    model->setItem(1,2,new QStandardItem("2010-12-01"));

    this->verticalHeader()->hide();
}

Widget::~Widget()
{
}

