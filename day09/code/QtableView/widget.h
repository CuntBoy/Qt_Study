#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTableView>

class Widget : public QTableView
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    void contextMenuEvent(QContextMenuEvent *event);

    ~Widget();
public slots:
    void dataChangedSlot(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles);
    void clickedSlot(QModelIndex index);

private:
};
#endif // WIDGET_H
