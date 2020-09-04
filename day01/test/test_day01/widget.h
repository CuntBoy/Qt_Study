#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QGridLayout>


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    QPushButton * sign;
    QPushButton * canc;
    QLineEdit * uname_input;
    QLineEdit * passwd_input;
public slots:
    void enterslot();

};
#endif // WIDGET_H
