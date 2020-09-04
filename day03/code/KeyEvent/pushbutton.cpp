#include "pushbutton.h"
#include <QPushButton>
#include <QDebug>
#include <QKeyEvent>

PushButton::PushButton(const QString &text,QWidget *parent) : QPushButton(text,parent)
{

}
void PushButton::keyPressEvent(QKeyEvent * ev)
{
    qDebug()<<ev->key()<<ev->text()<<"PushButton:"<<__FUNCTION__<<endl;
//    qDebug()<<this->text()<<endl;
}
void PushButton::keyReleaseEvent(QKeyEvent * ev)
{
    qDebug()<<ev->key()<<ev->text()<<"PushButton:"<<__FUNCTION__<<endl;
    qDebug()<<this->text()<<endl;
}
