#include "pushbutton.h"
#include <QDebug>
#include <QEvent>

PushButton::PushButton(const QString & text,QWidget * parent)
    :QPushButton(text, parent)
{

}
bool PushButton::event(QEvent *event)
{
    static int i = 0;
    //    qDebug()<<__FUNCTION__<<i++<<endl;
    if(event->type() == QEvent::MouseButtonPress)
    {
        qDebug()<<i++<<"QPushButton ==> QEvent::MouseButtonPress"<<endl;
        //event->ignore(); // 忽略这个事件
        event->accept(); // 接收这个事件
        return true;    // true 表示处理这个 事件，不传给父窗口
        //return false;   //表示我不处理这个事件

    }
    return QWidget::event(event);

}
