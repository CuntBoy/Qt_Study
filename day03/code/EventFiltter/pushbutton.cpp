#include "pushbutton.h"
#include <QPushButton>
#include <QDebug>
#include <QKeyEvent>
#include <QEvent>

PushButton::PushButton(const QString &text,QWidget *parent) : QPushButton(text,parent)
{

}
bool PushButton::event(QEvent * ev)
{
    if(ev->type() == QEvent::MouseButtonPress)
    {
        qDebug()<<"child mouse press button: => "<<this->text()<<endl;
        return true;
    }
    else if(ev->type() == QEvent::MouseButtonRelease)
    {
        qDebug()<<"child mouse relese button: => "<<this->text()<<endl;
        return true;
    }
//    qDebug()<<"PushButton::event"<<__FUNCTION__<<endl;
    return QWidget::event(ev);
}
//void PushButton::keyPressEvent(QKeyEvent * ev)
//{
//    qDebug()<<"PushButton: keyPressEvent"<<__FUNCTION__<<this->text()<<endl;
//}

//void PushButton::keyReleaseEvent(QKeyEvent * ev)
//{
//    qDebug()<<"PushButton: keyReleaseEvent"<<__FUNCTION__<<this->text()<<endl;
//}

PushButton::~PushButton()
{

}
