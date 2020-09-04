#ifndef TEST_H
#define TEST_H
#include <QDebug>
#include <QThread>

class WorkTHread2:public QObject
{
    Q_OBJECT
public:
    WorkTHread2(const QString & test)
        :objectname_(test){}

public slots:
    void working()
    {
        for(int i = 0;i <10;i++)
        {
            qDebug()<<"working"<<objectname_<<i
                   <<QThread::currentThreadId()<<endl;
            QThread::sleep(1);
        }
    }
private:
    QString objectname_;

};
#endif // TEST_H
