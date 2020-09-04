#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H
#include <QPushButton>
#include <QString>

class PushButton : public QPushButton
{
public:
    PushButton(const QString & text, QWidget * parent = NULL);
    virtual bool event(QEvent *event);

};

#endif // PUSHBUTTON_H
