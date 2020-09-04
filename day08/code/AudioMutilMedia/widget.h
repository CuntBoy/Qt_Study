#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class QMediaPlayer;
class QLabel;
class QMediaPlaylist;
class QMediaContent;
class QSlider;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


public slots:
    void openFileSlot();
    void changeNameSlot(const QMediaContent &content);
    void durationChangeSlot(qint64 duration);
    void positionChangedSLot(qint64 position);
    void changepositionSlot();

private:
    QMediaPlayer * player_;
    QLabel * filenamelabel_;
    QMediaPlaylist * playlist_;
    QLabel * timelabel_;   // all time
    QLabel * currenttime_; // current time
    QSlider * musicslider_;
};
#endif // WIDGET_H
