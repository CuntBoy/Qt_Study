#include "widget.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QDebug>
#include <QThread>
#include "workobject.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton * pb = new QPushButton("working");
    QHBoxLayout *hbox = new QHBoxLayout(this);
    hbox->addWidget(pb);

    work_ = new WorkObject;
    thread_ = new QThread(this);
    work_->moveToThread(thread_);

    connect(pb,SIGNAL(clicked()),work_,SLOT(workSlot()));
    connect(thread_,SIGNAL(finished()),work_,SLOT(deleteLater()));
    connect(this,SIGNAL(startworking()),work_,SLOT(presswork()));

    thread_->start();

}

void Widget::workSlot()
{
    qDebug()<<__FUNCTION__<<"start"<<endl;
    QThread::sleep(5);
    qDebug()<<__FUNCTION__<<"finish"<<endl;
}


void Widget::mousePressEvent(QMouseEvent * ev)
{
//    qDebug()<<__FUNCTION__<<"start"<<endl;
//    QThread::sleep(5);
//    qDebug()<<__FUNCTION__<<"finish"<<endl;
    emit startworking();
}
Widget::~Widget()
{
    thread_->quit();
    thread_->wait();

}

