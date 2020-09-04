#include "work.h"
#include <QDebug>
#include <QThread>

Work::Work(QSemaphore *semaphore, QMutex *mutex, int *value, QObject *parent)
    : QObject(parent),value_(value),mutex_(mutex),semaphore_(semaphore)
{

}

void Work::workingSlot()
{
    QMutexLocker locker(mutex_);
    //    mutex_->lock();
    for(int i = 0;i < 5000000;i++)
    {
        int temp = * value_;
        temp ++;
        *value_ = temp;
    }
    //    mutex_->unlock();
    qDebug()<<"value"<<*value_<<this->objectName()<<endl;
}

void Work::working2Slot()
{

    qDebug()<<"start lock"<<this->objectName()<<endl;
    while(!mutex_->tryLock(0))
    {
        QThread::sleep(1);
        qDebug()<<"tryLock "<<this->objectName()<<endl;
    }
    (*value_)++;
    qDebug()<<this->objectName()<<" get lock "<<"value: "<<*value_<<endl;
    QThread::sleep(4);

    mutex_->unlock();

    qDebug()<<"unlock"<<this->objectName()<<endl;

}

int Work::working3Slot()
{
    QMutexLocker locker(mutex_);
    return (*value_)++;
}

int Work::working4Slot()
{

    qDebug()<<"start lock"<<this->objectName()<<endl;
    semaphore_->acquire(1);
    (*value_)++;
    QThread::sleep(3);
    qDebug()<<this->objectName()<<" acquire sem "<<*value_<<endl;
    semaphore_->release(1);

    qDebug()<<"acquire release "<<this->objectName()<<endl;

}


