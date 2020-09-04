#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void enterEvent(QEvent * ev);
    void leaveEvent(QEvent * ev);
    void closeEvent(QCloseEvent * ev);

};
#endif // WIDGET_H
