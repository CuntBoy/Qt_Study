#ifndef DRAWWORK_H
#define DRAWWORK_H

#include <QObject>

class QThread;
class DrawWork : public QObject
{
    Q_OBJECT
public:
    explicit DrawWork(QPixmap * pixmap,QObject *parent = nullptr);

signals:
    void updatesignal();
public slots:
    void  drawpixmap();

private:
    QPixmap * pixmap_;

};

#endif // DRAWWORK_H
