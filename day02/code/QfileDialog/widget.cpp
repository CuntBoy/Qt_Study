#include "widget.h"
#include <QFileDialog>
#include <QHBoxLayout>
#include <QPushButton>
#include <QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(640,480);
    QHBoxLayout * hbox = new QHBoxLayout(this);
    QPushButton * pb_open = new QPushButton("OpenDialog");
    QPushButton * pb_save = new QPushButton("SavenDialog");
    hbox->addWidget(pb_open);
    hbox->addWidget(pb_save);
    connect(pb_open,SIGNAL(clicked()),this,SLOT(showOpenFile()));
    connect(pb_save,SIGNAL(clicked()),this,SLOT(showSaveFile()));

}

void Widget::showSaveFile()
{
    QString filename = QFileDialog::getSaveFileName(this,"save",filename_,"Image(*.png *.jpg *.jepg *.bmp)");
    if(!filename.isEmpty())
    {
        qDebug()<<filename<<endl;
        filename_ = filename;
    }else
    {
        qDebug()<<"is Null"<<endl;
    }
}

void Widget::showOpenFile()
{
    QString filename = QFileDialog::getOpenFileName(this,"open",filename_,"Image(*.png *.jpg *.jepg *.bmp)");
    if(!filename.isEmpty())
    {
        qDebug()<<filename<<endl;
        filename_ = filename;
    }else
    {
        qDebug()<<"is Null"<<endl;
    }

}


Widget::~Widget()
{
}

