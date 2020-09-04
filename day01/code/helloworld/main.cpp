#include <QApplication>
#include <QDebug>
#include <QWidget>
#include <QPushButton>
#include <QObject>

int main(int argc,char ** agrv)
{

    QApplication app(argc,agrv) ;
    QWidget widget;
    QPushButton pb;

    widget.move(100,300);
    widget.resize(600,400);

    pb.setParent(&widget);
    pb.setText("关闭");

    QObject::connect(&pb, SIGNAL(clicked()), &widget, SLOT(close()));

    pb.show();
    widget.show();
    qDebug()<<pb.pos()<<pb.size()<<endl;
    return app.exec();


}
