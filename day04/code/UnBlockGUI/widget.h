#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>


class WorkObject;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void mousePressEvent(QMouseEvent * ev);
signals:
    void startworking();
private:
    QThread * thread_;
    WorkObject * work_;

public slots:
    void workSlot();
};
#endif // WIDGET_H
