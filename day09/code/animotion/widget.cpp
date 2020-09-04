#include "widget.h"
#include "pushbutton.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    new PushButton(this);
}

Widget::~Widget()
{
}

