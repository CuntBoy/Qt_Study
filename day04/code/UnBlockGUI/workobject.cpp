#include "workobject.h"
#include <QDebug>
#include <QThread>

WorkObject::WorkObject(QObject *parent) : QObject(parent)
{

}
void WorkObject::workSlot()
{
    qDebug()<<__FUNCTION__<<"start"<<endl;
    QThread::sleep(5);
    qDebug()<<__FUNCTION__<<"finish"<<endl;
}

void WorkObject::presswork()
{
    qDebug()<<__FUNCTION__<<"start"<<endl;
    QThread::sleep(5);
    qDebug()<<__FUNCTION__<<"finish"<<endl;
}



WorkObject::~WorkObject()
{

}


