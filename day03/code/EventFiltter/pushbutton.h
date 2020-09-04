#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <QPushButton>

class PushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit PushButton(const QString &text,QWidget *parent = nullptr);
    ~PushButton();
//    void keyPressEvent(QKeyEvent * ev);
//    void keyReleaseEvent(QKeyEvent * ev);
    bool event(QEvent * ev);
signals:

};

#endif // PUSHBUTTON_H
