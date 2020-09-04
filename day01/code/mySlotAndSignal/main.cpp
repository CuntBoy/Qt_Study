#include <iostream>
#include "test.h"
#include <QCoreApplication>
using namespace std;

int main(int argc,char ** argv)
{
    QCoreApplication  app(argc,argv);
    Teacher tea;
    Student stu;

    QObject::connect(&tea,SIGNAL(mySig()),&stu,SLOT(answerSlot()));
    QObject::connect(&stu,SIGNAL(myquestionSig()),&tea,SLOT(responseSig()));

//    tea.tech();
    stu.subquestion();

    app.exec();
    return 0;
}
