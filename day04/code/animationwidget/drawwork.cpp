#include "drawwork.h"
#include <QPixmap>
#include <QThread>

DrawWork::DrawWork(QPixmap *pixmap, QObject *parent)
    : QObject(parent),pixmap_(pixmap)
{

}
void DrawWork::drawpixmap()
{
    int i = 0;
    while(1)
    {
        QThread::msleep(100);
        pixmap_->load(QString("E:/Study/My_C++/Qt_study/day04/source/test%1.jpg").arg(i+1));
        *pixmap_ = pixmap_->scaled(400,400,Qt::KeepAspectRatio,Qt::SmoothTransformation);
        i = (++i)%6;
        emit updatesignal();
//        this->update();
    }
}
