#include "widget.h"
#include <QPushButton>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton * pb1 = new QPushButton("warning");
    QPushButton * pb2 = new QPushButton("infomation");
    QPushButton * pb3 = new QPushButton("question");
    QHBoxLayout * hbox = new QHBoxLayout(this);

    hbox->addWidget(pb1);
    hbox->addWidget(pb2);
    hbox->addWidget(pb3);

    connect(pb1,SIGNAL(clicked()),this,SLOT(showwarning()));
    connect(pb2,SIGNAL(clicked()),this,SLOT(showinfomation()));
    connect(pb3,SIGNAL(clicked()),this,SLOT(showquestion()));


}
void Widget::showwarning()
{
    int sb = QMessageBox::warning(this,"warning","unuse var",QMessageBox::Open|QMessageBox::Save);
    qDebug()<<sb<<endl;
}
void Widget::showinfomation()
{
    int mes = QMessageBox::information(this,"information","about me",QMessageBox::Open|QMessageBox::Save);
    qDebug()<<mes<<endl;
}
void Widget::showquestion()
{
    int mes = QMessageBox::question(this,"question","what happen?",QMessageBox::Open|QMessageBox::Save);
    qDebug()<<mes<<endl;
}



Widget::~Widget()
{
}

