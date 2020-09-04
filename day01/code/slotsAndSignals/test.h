#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>

class Teacher:public QObject    //1， 继承QObject
{
    // 2，启用宏
    Q_OBJECT
public:
    Teacher(){}
    void tech()
    {
        qDebug()<<"Teacher teaching a question:"<<endl;
        emit mySig("what is Qt ?");
        qDebug()<<"end class"<<endl;
    }

    //声明信号
signals:
    void mySig();   //只需要声明不需要实现
    void mySig(QString str);
public slots:
    void responseSig()
    {
        qDebug()<<__FUNCTION__<<endl;
    }

};

class Student: public QObject
{
    Q_OBJECT
public:
    Student(int no):No_(no){}
    void subquestion()
    {
        qDebug()<<"Student: " <<No_<<" I have a question"<<endl;
        qDebug()<<__FUNCTION__<<endl;
        emit myquestionSig();
    }
signals:
    void myquestionSig();
public slots:
    void answerSlot(){qDebug()<<"Student:"<<No_<<__FUNCTION__<<endl;}
    void answerSlot(const QString str )
    {
        qDebug()<<str<<" ";
        qDebug()<<"Student:"<<No_<<__FUNCTION__<<endl;
    }
private:
    int No_;

};


#endif // TEST_H
