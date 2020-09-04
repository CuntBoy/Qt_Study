#include <iostream>
#include "test.h"
#include <QCoreApplication>
using namespace std;

int main(int argc,char ** argv)
{
    QCoreApplication  app(argc,argv);
    Teacher tea;
    Student stu0(1001),stu1(1002),stu2(1003);

    // 一个信号和多个槽函数关联
//    QObject::connect(&tea,SIGNAL(mySig()),&stu0,SLOT(answerSlot()));
//    QObject::connect(&tea,SIGNAL(mySig()),&stu1,SLOT(answerSlot()));
    QObject::connect(&tea,SIGNAL(mySig(QString)),&stu0,SLOT(answerSlot()));
    QObject::connect(&tea,SIGNAL(mySig(QString)),&stu1,SLOT(answerSlot(QString)));
    //    QObject::connect(&stu,SIGNAL(myquestionSig()),&tea,SLOT(responseSig()));

    tea.tech();
    //    stu.subquestion();
    //=================================================================
    // 多个信号关联一个槽函数
    QObject::connect(&stu0,SIGNAL(myquestionSig()),&tea,SLOT(responseSig()));
    QObject::connect(&stu1,SIGNAL(myquestionSig()),&tea,SLOT(responseSig()));
    QObject::connect(&stu2,SIGNAL(myquestionSig()),&tea,SLOT(responseSig()));
//    stu0.subquestion();
//    stu1.subquestion();
//    stu2.subquestion();
    app.exec();
    return 0;
}
