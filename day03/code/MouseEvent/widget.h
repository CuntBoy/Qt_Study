#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    virtual void mousePressEvent(QMouseEvent * event);     // 鼠标按压
    virtual void mouseReleaseEvent(QMouseEvent * event);   // 鼠标释放
    virtual void mouseMoveEvent(QMouseEvent * event);      // 鼠标移动
    virtual void wheelEvent(QWheelEvent * event);



};
#endif // WIDGET_H
