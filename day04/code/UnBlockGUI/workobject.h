#ifndef WORKOBJECT_H
#define WORKOBJECT_H

#include <QObject>

class WorkObject : public QObject
{
    Q_OBJECT
public:
    explicit WorkObject(QObject *parent = nullptr);
    ~WorkObject();
signals:
public slots:
    void workSlot();
    void presswork();

};

#endif // WORKOBJECT_H
