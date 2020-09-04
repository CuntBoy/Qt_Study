#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QColor>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void paintEvent(QPaintEvent * pevent);

private:
    QColor background_;
public slots:
    void setBlueSlot();
    void UpdateBlueSlot();
    void repaintSlot();

};
#endif // WIDGET_H
