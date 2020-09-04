#include "widget.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QComboBox>
#include <QDebug>
#include <QTranslator>
#include <QApplication>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setFixedSize(640,480);
    QHBoxLayout *hbox = new QHBoxLayout(this);

    Label_ = new QLabel(tr("tea"));
    hbox->addWidget(Label_);

    comb_ = new QComboBox;
    hbox->addWidget(comb_);

    comb_->addItem(tr("Chinese"));
    comb_->addItem(tr("English"));

    connect(comb_,SIGNAL(currentTextChanged(QString)),this,SLOT(reTranslate(QString)));

}


void Widget::setui()
{
    Label_->setText(tr("tea"));
//    comb_->setItemText(0,tr("Chinese"));
//    comb_->setItemText(1,tr("English"));
}

void Widget::reTranslate(QString s)
{
    qDebug()<<s<<endl;
    static QTranslator * tran = NULL;
    if(tran != NULL)
    {
        delete tran;
        tran = NULL;
    }
    tran = new QTranslator;
    tran->load(QString("E:/Study/My_C++/Qt_study/day09/code/Tranlate/%1.qm").arg(s));
    QApplication::instance()->installTranslator(tran);
    setui();
}

Widget::~Widget()
{
}

