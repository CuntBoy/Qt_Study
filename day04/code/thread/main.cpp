#include <QApplication>
#include <QThread>
#include <QString>
#include <QDebug>
#include "test.h"
#include <QObject>

class Work{
public:
    Work(const QString &test)
        :objectname_(test){}
    void working()
    {
        for(int i = 0;i < 10;i++)
        {
            qDebug()<<"working"<<objectname_<<QThread::currentThreadId()<<endl;
            QThread::sleep(1);
        }

    }
private:
    QString objectname_;
};



int main(int argc,char *argv[])
{

    QApplication app(argc, argv);
    Work w0("w0");
    WorkTHread2 w1("w1");

    QThread thread;

    // 移动到子线程去
    w1.moveToThread(&thread);
    QObject::connect(&thread,SIGNAL(started()),&w1,SLOT(working()));
    thread.start();

//    w1.working();
    w0.working();

    return app.exec();

}
