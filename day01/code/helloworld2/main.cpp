#include <QApplication>
#include "widget.h"

int main(int argc,char ** agrv)
{
    QApplication app(argc,agrv) ;
    Widget widget;
    widget.show();

    return app.exec();
}
