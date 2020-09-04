#include <QApplication>
#include <QDebug>
#include <QThread>

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

class WorkThrea:public QThread{
public:
    WorkThrea(const QString &test, QObject * parent = Q_NULLPTR):QThread(parent),objectname_(test){}
    void working()
    {
        for(int i = 0;i < 10;i++)
        {
            qDebug()<<"working"<<objectname_<<QThread::currentThreadId()<<endl;
//            qDebug()<<"thread is running "<<w3.isRunning()<<endl;
            QThread::usleep(1000);
        }

    }
    void run()
    {
        working();
        this->exec();
    }
private:
    QString objectname_;
};



int main(int argc,char ** argv)
{
    QApplication app(argc,argv);
    Work w0("w0"),w1("w1");
    WorkThrea w3("w3");
    w3.start();
    qDebug()<<"thread is running "<<w3.isRunning()<<endl;
    w0.working();
    qDebug()<<"thread is running "<<w3.isRunning()<<endl;
//    w3.wait(5000);
    w3.quit();
    qDebug()<<"thread is finished"<<w3.wait(5000)<<endl;

//    w1.working();

    return app.exec();
}
