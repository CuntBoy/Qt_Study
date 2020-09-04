#include "widget.h"
#include <QColor>  // rgba argb
#include <QPalette>  // 调色板
#include <QDebug>
#include <QLabel>
#include <QColorDialog>
#include <QVBoxLayout>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
#if 0
    QPalette palette = this->palette();
    qDebug()<<palette.color(QPalette::WindowText)<<endl;  //获取调色板的颜色
//    QLabel * label = new QLabel("helloworld",this);
//    qDebug()<<palette.color(QPalette::WindowText)<<endl;  //获取调色板的颜色

    palette.setColor(QPalette::WindowText,QColor(255,0,0));
//    palette.setColor(QPalette::Background,QColor("#00ff00"));
    this->setPalette(palette);
#endif

    QVBoxLayout * vbox = new QVBoxLayout(this);
    QLabel *mylabel = new QLabel("ColorDialog");
    QPushButton * pb = new QPushButton("showColorDialog");
    vbox->addWidget(mylabel);
    vbox->addWidget(pb);

    connect(pb,SIGNAL(clicked()),this,SLOT(showColorDialog()));

}

void Widget::showColorDialog()
{
    QColor color = QColorDialog::getColor(QColor("#00FF00"),this,"color");
    if(color.isValid())
    {
        QPalette palette = this->palette();
//        qDebug()<<palette.color(QPalette::WindowText)<<endl;  //获取调色板的颜色
        QLabel * label = new QLabel("helloworld",this);
    //    qDebug()<<palette.color(QPalette::WindowText)<<endl;  //获取调色板的颜色

        palette.setColor(QPalette::Background,color);
    //    palette.setColor(QPalette::Background,QColor("#00ff00"));
        this->setPalette(palette);
    }

}


Widget::~Widget()
{
}

