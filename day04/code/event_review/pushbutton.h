#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <QPushButton>

class PushButton : public QPushButton
{
public:
    PushButton(const QString & text,QWidget * parent = NULL);
};

#endif // PUSHBUTTON_H
