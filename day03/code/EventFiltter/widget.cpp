#include "widget.h"
#include "pushbutton.h"
#include <QDebug>
#include <QEvent>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent) : QWidget(parent)
{

    QHBoxLayout * hbox = new QHBoxLayout(this);
    PushButton * pb1 = new PushButton("pb1",this);
    PushButton * pb2 = new PushButton("pb2",this);
    hbox->addWidget(pb1);
    hbox->addWidget(pb2);
    pb1->installEventFilter(this);
    pb2->installEventFilter(this);

}

bool Widget::eventFilter(QObject *watched, QEvent *event)
{
//    static int i = 0;
    QString text = dynamic_cast<PushButton*>(watched)->text();
    if(text == "pb1" && event->type() == QEvent::MouseButtonPress)
    {
        qDebug()<<__FUNCTION__<<" Fillter Mousbuttonpress event"<<endl;
        return true;
    }


//    return true;   // 过滤事件
    return QWidget::eventFilter(watched,event);  // 调用基类的事件过滤器
}

Widget::~Widget()
{

}
