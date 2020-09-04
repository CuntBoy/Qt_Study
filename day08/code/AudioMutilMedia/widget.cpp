#include "widget.h"
#include <QMediaPlayer>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QFile>
#include <QFileInfo>
#include <QVBoxLayout>
#include <QLabel>
#include <QMediaPlaylist>
#include <QMediaContent>
#include <QSlider>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // init media
    player_ = new QMediaPlayer(this);
    playlist_ = new QMediaPlaylist(this);
    player_->setPlaylist(playlist_);
    player_->setVolume(47);
    playlist_->setPlaybackMode(QMediaPlaylist::Random);
    //    player_->setVolume();

    //显示播放歌曲  歌单
    filenamelabel_ = new QLabel("wait");
    QVBoxLayout * vbox = new QVBoxLayout(this);
    vbox->addWidget(filenamelabel_);

    //    显示时间
    timelabel_ = new QLabel("00:00:00");
    QHBoxLayout * timelabel = new QHBoxLayout;
    currenttime_ = new QLabel("00:00:00");
    timelabel->addWidget(timelabel_);
    vbox->addLayout(timelabel);
    timelabel->addWidget(currenttime_);
    musicslider_ = new QSlider(Qt::Horizontal,this);
    musicslider_->setMinimum(0);
    musicslider_->setMaximum(0);
    musicslider_->setDisabled(true);
    timelabel->addWidget(musicslider_);
    timelabel->addWidget(timelabel_);



    // 音量控制
    QHBoxLayout * volume = new QHBoxLayout;
    vbox->addLayout(volume);
    volume->addWidget(new QLabel("音量"));
    QSlider * volumeslider = new QSlider(Qt::Horizontal,this);
    //    valmue->addWidget();
    volume->addWidget(volumeslider);
    volumeslider->setMinimum(10);
    volumeslider->setMaximum(100);
    volumeslider->setValue(player_->volume());


    // layout
    QHBoxLayout * hbox = new QHBoxLayout;
    QPushButton * pb_player = new QPushButton("Player");
    QPushButton * open_dialog = new QPushButton("OPen");
    QPushButton * pause = new QPushButton("Pause");
    QPushButton * stop = new QPushButton("Stop");
    QPushButton * next = new QPushButton("Next");
    QPushButton * previous = new QPushButton("Previous");
    QPushButton * pb_delete = new QPushButton("Delete");
    QPushButton * all_delete = new QPushButton("Delete_all");

    hbox->addWidget(pb_player);
    hbox->addWidget(open_dialog);
    hbox->addWidget(pause);
    hbox->addWidget(stop);
    hbox->addWidget(next);
    hbox->addWidget(previous);
    hbox->addWidget(pb_delete);
    hbox->addWidget(all_delete);
    vbox->addLayout(hbox);



    connect(pb_player,SIGNAL(clicked()),player_,SLOT(play()));
    connect(open_dialog,SIGNAL(clicked()),this,SLOT(openFileSlot()));
    connect(pause,SIGNAL(clicked()),player_,SLOT(pause()));
    connect(stop,SIGNAL(clicked()),player_,SLOT(stop()));
    connect(next,SIGNAL(clicked()),playlist_,SLOT(next()));
    connect(previous,SIGNAL(clicked()),playlist_,SLOT(previous()));
    connect(pb_delete,QPushButton::clicked,[](){playlist_->removeMedia(playlist_->currentIndex());});
    connect(all_delete,QPushButton::clicked,[](){playlist_->clear();});

    connect(playlist_,SIGNAL(currentMediaChanged(QMediaContent)),this,SLOT(changeNameSlot(QMediaContent)));
    connect(volumeslider,SIGNAL(valueChanged(int)),player_,SLOT(setVolume(int)));
    connect(player_,SIGNAL(durationChanged(qint64)),this,SLOT(durationChangeSlot(qint64)));
    connect(player_,SIGNAL(positionChanged(qint64)),this,SLOT(positionChangedSLot(qint64)));
    connect(musicslider_,SIGNAL(sliderReleased()),this,SLOT(changepositionSlot()));
}

Widget::~Widget()
{
}

void Widget::openFileSlot()
{
    QStringList filenames = QFileDialog::getOpenFileNames(this,"MP3","","audio(*.mp3)");
    foreach (QString filename, filenames) {
        QFileInfo fileInfo(filename);
        if(fileInfo.isFile())
        {
            playlist_->addMedia(QUrl::fromLocalFile(filename));
        }
    }
#if 0
    QFileInfo fileInfo(filename);
    //    filenamelabel_->setText(fileInfo.fileName());
    if(fileInfo.isFile())
    {
        //        filenamelabel_->setText(fileInfo.fileName());
        //        player_->setMedia(QUrl::fromLocalFile(filename));
        playlist_->addMedia(QUrl::fromLocalFile(filename));
    }
#endif
}

void Widget::changeNameSlot(const QMediaContent & content)
{

    filenamelabel_->setText(content.request().url().fileName());/*.canonicalUrl().toString());*/  // .canonicalUrl().fileName()
//    timelabel_->setText(QString::asprintf("%d:%d:%d",duration/3600,duration%3600/60,duration/60));

}

void Widget::durationChangeSlot(qint64 duration)
{

    duration = duration / 1000;
    musicslider_->setMaximum(duration);
    musicslider_->setDisabled(false);
    timelabel_->setText(QString::asprintf("%02lld:%02lld:%02lld",
                                          duration / 3600,duration % 3600 / 60,duration % 60));
}

void Widget::positionChangedSLot(qint64 position)
{
    position /= 1000;
    musicslider_->setValue(position);
    currenttime_->setText(QString::asprintf("%02lld:%02lld:%02lld",
                                            position / 3600,position % 3600 / 60,position % 60));
}

void Widget::changepositionSlot()
{
    qint64 value = (musicslider_->value())*1000;
    player_->setPosition(value);
}





