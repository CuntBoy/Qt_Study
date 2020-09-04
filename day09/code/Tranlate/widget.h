#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class QLabel;
class QComboBox;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    void setui();
    ~Widget();
public slots:
    void reTranslate(QString s);


private:
    QLabel * Label_;
    QComboBox * comb_;

};
#endif // WIDGET_H
