#include "pushbutton.h"
#include <QDebug>

PushButton::PushButton(const QString &text, QWidget *parent)
    :QPushButton(text, parent){}

PushButton::~PushButton()
{
    qDebug() <<__FUNCTION__<< endl;
}
