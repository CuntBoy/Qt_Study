#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    virtual void keyPressEvent(QKeyEvent * keyevent);
    virtual void keyReleaseEvent(QKeyEvent *keyevent);

};
#endif // WIDGET_H
