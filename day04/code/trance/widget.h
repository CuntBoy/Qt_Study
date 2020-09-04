#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMutex>
#include <QSemaphore>

class Work;
class QThread;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    Work * w0;
    Work * w1;
    QThread * thread0_;
    QThread * thread1_;
    QSemaphore * semaphore_;
private:
    int value_;
    QMutex * mutex_;
};
#endif // WIDGET_H
