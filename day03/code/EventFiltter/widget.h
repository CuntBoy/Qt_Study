#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    bool eventFilter(QObject *watched, QEvent *event);
signals:

};

#endif // WIDGET_H
