#include "widget.h"
#include <QPushButton>
#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
#if 0
    QGridLayout * grid = new QGridLayout(this);

    QHBoxLayout * hbox1 = new QHBoxLayout();
    QLabel * uname1 = new QLabel("用户名: ");
    QLineEdit * uname_input1 = new QLineEdit("请输入用户名");

    QHBoxLayout * hbox2 = new QHBoxLayout();
    QLabel * uname2 = new QLabel("密 码: ");
    QLineEdit * uname_input2 = new QLineEdit("请输入密码");

    QHBoxLayout * hbox3 = new QHBoxLayout();
    sign = new QPushButton("Sign");
    canc = new QPushButton("cacnle");

    grid->addLayout(hbox1,1,1,1,3);
    hbox1->addWidget(uname1,0);
    hbox1->addWidget(uname_input1,0);

    grid->addLayout(hbox2,2,1,1,3);
    hbox2->addWidget(uname2,0);
    hbox2->addWidget(uname_input2,0);



    //    grid->setRowStretch(0,1);
    //    grid->setRowStretch(3,1);
    //    grid->setColumnStretch(0,1);
    //    grid->setColumnStretch(4,1);

#endif

    QGridLayout * grid = new QGridLayout(this);
    QHBoxLayout * hbox = new QHBoxLayout();
    sign = new QPushButton("Sign Up");
    canc = new QPushButton("cancle");

    QLabel * uname = new QLabel("用户名: ");
    uname_input = new QLineEdit("请输入用户名");

    QLabel * passwd = new QLabel("密 码: ");
    passwd_input = new QLineEdit;

    passwd_input->setEchoMode(QLineEdit::Password);

    grid->addWidget(uname,0,0,1,1);
    grid->addWidget(uname_input,0,1,1,2);

    grid->addWidget(passwd,1,0,1,1);
    grid->addWidget(passwd_input,1,1,1,2);

    grid->addLayout(hbox,2,0,1,3);
    hbox->addSpacing(100);
    hbox->addWidget(sign);
    hbox->addWidget(canc);

    connect(canc,SIGNAL(clicked()),this,SLOT(close()));
    connect(sign,SIGNAL(clicked()),this,SLOT(enterslot()));

    connect(sign,SIGNAL(clicked()),this,SLOT(close()));



}

void Widget::enterslot()
{
    if(uname_input->text() == "admin")
    {
        if(passwd_input->text() == "admin")
        {
            qDebug()<<"Login Success"<<endl;
        }else
        {
            qDebug()<<"passwd error"<<endl;
        }
    }
    else
    {
        qDebug()<<"用户不存在"<<endl;
    }
}


Widget::~Widget()
{
}

