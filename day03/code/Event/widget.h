#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    virtual bool event(QEvent * event);
    virtual void mousePressEvent(QMouseEvent * event);
};
#endif // WIDGET_H
