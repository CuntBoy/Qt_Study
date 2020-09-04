#include "widget.h"
#include <QStandardItemModel>
#include <QDebug>
#include <QHeaderView>
#include <QModelIndex>
#include <QMenu>

Widget::Widget(QWidget *parent)
    : QTableView(parent)
{
    QStandardItemModel * model = new QStandardItemModel(this);
    this->resize(600,400);
    this->setModel(model);
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

    connect(model,SIGNAL(dataChanged(QModelIndex,QModelIndex,QVector<int>)),
            this,SLOT(dataChangedSlot(QModelIndex,QModelIndex,QVector<int>)));

    connect(this,SIGNAL(clicked(QModelIndex)),this,SLOT(clickedSlot(QModelIndex)));

    this->verticalHeader()->hide();
    this->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->setEditTriggers(QAbstractItemView::NoEditTriggers);


}

// 右键菜单
void Widget::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu;
    menu.addAction("close",this,SLOT(close()));
    menu.exec(this->cursor().pos());   // 阻塞显示
}

Widget::~Widget()
{
}

void Widget::dataChangedSlot(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles)
{
    qDebug()<<__FUNCTION__<<topLeft.column()<<topLeft.row()<<endl;
    qDebug()<<this->model()->data(topLeft)<<endl;


}

void Widget::clickedSlot(QModelIndex  index)
{
    qDebug()<<__FUNCTION__<<endl;
    this->selectedIndexes();
}

