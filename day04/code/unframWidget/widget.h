#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMenu>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    virtual void paintEvent(QPaintEvent * event);
    virtual void mousePressEvent(QMouseEvent * ev);
    virtual void mouseMoveEvent(QMouseEvent * ev);
private:
    QPoint pos_press;
    QMenu * menu_;

};
#endif // WIDGET_H
