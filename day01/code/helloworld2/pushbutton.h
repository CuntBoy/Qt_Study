#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H
#include <QPushButton>

class PushButton : public QPushButton
{
public:
//    PushButton();
    PushButton(const QString &text, QWidget *parent);
    ~PushButton();
};

#endif // PUSHBUTTON_H
