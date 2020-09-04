#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPixmap>

class DrawWork;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    virtual void paintEvent(QPaintEvent * ev);
private:
    QPixmap * pixmap_;
    QThread * thread_;
    DrawWork *work_;
public slots:
//    void drawpixmap();
};
#endif // WIDGET_H
