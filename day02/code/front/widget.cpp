#include "widget.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFontDialog>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QFont font = this->font();
    font.setPointSize(50);
    //    font.setFamilies("verdana");
    this->setFont(font);

    QLabel * label = new QLabel("helloworld",this);

    QVBoxLayout *vbox = new QVBoxLayout(this);
    QPushButton * pb = new QPushButton("showFontDialog");
    vbox->addWidget(label);
    vbox->addWidget(pb);
    connect(pb,SIGNAL(clicked()),this,SLOT(showFontDialog()));

}

void Widget::showFontDialog()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok,this->font(),this,"Font");
    if(ok)
    {
        qDebug()<<font<<endl;
        this->setFont(font);
    }
}

Widget::~Widget()
{
}

