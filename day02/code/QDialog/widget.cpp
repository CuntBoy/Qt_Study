#include "widget.h"
#include <QPushButton>
#include <QDialog>
#include <QDebug>

/*普通窗口QWidget可以通过两种方式显示
* 不指定父窗口，直接调用show显示
* 指定父窗口 来嵌套显示
* 指定父窗口的时候 调用show函数 还是嵌套显示
*
* QDiaLog 显示方式
* 不指定父窗口直接show函数显示
* 指定父窗口的时候 调用show函数 无法嵌套到父窗口中显示
* 指定父窗口的时候 调用show函数 单独显示
* 调用exec函数 直接用模态窗口的方式运行
*/



Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(640,480);
    QPushButton * pb = new QPushButton("dialog",this);
    //    pb->show();

    Qdia = new QDialog();
        Qdia->resize(64,48);
    //    Qdia->show();

    //    Qdia->exec();   //阻塞到此处  可以通过点击启用
    connect(pb,SIGNAL(clicked()),this,SLOT(showdialog()));
}

void Widget::showdialog()
{
    qDebug()<<"open it"<<endl;
    int ret = Qdia->exec();
    qDebug()<<ret<<endl;
}

Widget::~Widget()
{
}

