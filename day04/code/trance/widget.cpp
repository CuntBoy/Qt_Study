#include "widget.h"
#include "work.h"
#include <QThread>
#include <QMutex>
#include <QSemaphore>

Widget::Widget(QWidget *parent)
    : QWidget(parent),value_(0)
{
    mutex_ = new QMutex;
    semaphore_ = new QSemaphore(1);
    w0 = new Work(semaphore_,mutex_,&value_);
    w1 = new Work(semaphore_,mutex_,&value_);

    w0->setObjectName("w0");
    w1->setObjectName("w1");


    thread0_ = new QThread(this);
    thread1_ = new QThread(this);

    w0->moveToThread(thread0_);
    w1->moveToThread(thread1_);

    connect(thread0_,SIGNAL(started()), w0,SLOT(working4Slot()));
    connect(thread1_,SIGNAL(started()), w1,SLOT(working4Slot()));
    connect(thread0_,SIGNAL(finished()),w0,SLOT(deleteLater()));
    connect(thread1_,SIGNAL(finished()),w1,SLOT(deleteLater()));

    thread0_->start();
    thread1_->start();

}

Widget::~Widget()
{
    thread0_->quit();
    thread0_->wait();
    thread1_->quit();
    thread1_->wait();
    delete mutex_;
}


