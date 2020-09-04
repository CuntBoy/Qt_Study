#ifndef WORK_H
#define WORK_H

#include <QObject>
#include <QMutex>
#include <QSemaphore>
class Work : public QObject
{
    Q_OBJECT
public:
    explicit Work(QSemaphore * semaphore,QMutex * mutex,int *value,QObject *parent = nullptr);

public slots:
    void workingSlot();
    void working2Slot();
    int working3Slot();
    int working4Slot();
private:
    int * value_;
    QMutex * mutex_;
    QSemaphore *semaphore_;


signals:

};

#endif // WORK_H
