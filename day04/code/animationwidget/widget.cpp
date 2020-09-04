#include "widget.h"
#include <QPainter>
#include <QPixmap>
#include <QPushButton>
#include <QHBoxLayout>
#include <QThread>
#include "drawwork.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(640,480);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    pixmap_ = new QPixmap(this->size());
//    QHBoxLayout * hbox = new QHBoxLayout(this);
//    QPushButton *pb = new QPushButton("start");
//    hbox->addWidget(pb);
    pixmap_->fill(QColor("#00000000"));

    work_ = new DrawWork(pixmap_);
    thread_ = new QThread(this);
    work_->moveToThread(thread_);

    connect(thread_,SIGNAL(started()),work_,SLOT(drawpixmap()));
    connect(thread_,SIGNAL(finished()),work_,SLOT(deleteLater()));
    connect(work_,SIGNAL(updatesignal()),this,SLOT(update()));

    thread_->start();

//    connect(pb,SIGNAL(clicked()),this,SLOT(drawpixmap()));
}

void Widget::paintEvent(QPaintEvent * ev)
{
    QPainter painter;
    painter.begin(this);
    painter.drawPixmap(0,0,*(this->pixmap_));
    painter.end();

}


Widget::~Widget()
{
    thread_->quit();
    thread_->wait();

    delete pixmap_;
}

