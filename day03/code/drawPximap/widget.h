#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void paintEvent(QPaintEvent * pevent);
private:
//    QImage * image_;
    QPixmap * pixmap_;
public slots:
    void drawpixmapslot();


};
#endif // WIDGET_H
