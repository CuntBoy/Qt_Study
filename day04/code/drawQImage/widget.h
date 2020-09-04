#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPixmap>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    virtual void paintEvent(QPaintEvent * event);
public slots:
    void drawImageSlot();
private:
    QPixmap * pixmap_;
    QImage * image_;

};
#endif // WIDGET_H
