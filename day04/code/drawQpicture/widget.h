#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    virtual void paintEvent(QPaintEvent * event);
public slots:
    void drawPictureSlot();
private:
    //    QPixmap * pixmap_;
    //    QImage * image_;
    QPicture * picture_;

};
#endif // WIDGET_H
