#ifndef WIDGET_H
#define WIDGET_H
#include <QLineEdit>

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    QLineEdit * edit;
public slots:
    void printSlot();
};
#endif // WIDGET_H
