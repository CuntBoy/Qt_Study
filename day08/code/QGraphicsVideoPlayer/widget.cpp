#include "widget.h"
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QGraphicsVideoItem>

Widget::Widget(QWidget *parent)
    : QGraphicsView(parent)
{
    QGraphicsScene * scene = new QGraphicsScene(this);
    this->setScene(scene);
    QMediaPlayer * player = new QMediaPlayer(this);
    player->setMedia(QUrl::fromLocalFile("E:/Study/My_C++/Qt_study/day08/code/QGraphicsVideoPlayer/re.avi"));
    QGraphicsVideoItem * item = new QGraphicsVideoItem;
    scene->addItem(item);
    item->setFlag(QGraphicsItem::ItemIsMovable);
    player->setVideoOutput(item);
    player->play();
}

Widget::~Widget()
{
}

