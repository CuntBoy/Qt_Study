#include "widget.h"
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QResizeEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QMediaPlayer * player = new QMediaPlayer(this);
    player->setMedia(QUrl::fromLocalFile("E:/Study/My_C++/Qt_study/day08/code/videoPlayer/re.avi"));
    voidout_ = new QVideoWidget(this);
    voidout_->resize(640,480);
    player->setVideoOutput(voidout_);
    player->play();
}

void Widget::resizeEvent(QResizeEvent *event)
{
    voidout_->resize(event->size());
}

Widget::~Widget()
{
}

