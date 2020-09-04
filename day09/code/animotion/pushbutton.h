#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <QPushButton>
#include <QList>
#include <QPropertyAnimation>
class PushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit PushButton(QWidget *parent = nullptr);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    void paintEvent(QPaintEvent *event);
private:
    QList<QPixmap> list_;
    QPropertyAnimation *animotion_;
    int index_;
public slots:
    void valuechangeSlot(QVariant value);

};

#endif // PUSHBUTTON_H
