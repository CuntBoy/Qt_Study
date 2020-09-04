#include "widget.h"

#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator tran;
    tran.load("E:/Study/My_C++/Qt_study/day09/code/tranlater/Test.qm");
    a.installTranslator(&tran);

    Widget w;
    w.show();
    return a.exec();
}
