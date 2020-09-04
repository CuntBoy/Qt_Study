#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QVideoWidget;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    void resizeEvent(QResizeEvent *event);

    ~Widget();

private:
    QVideoWidget * voidout_;

};
#endif // WIDGET_H
