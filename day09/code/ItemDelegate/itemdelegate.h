#ifndef ITEMDELEGATE_H
#define ITEMDELEGATE_H

#include <QItemDelegate>

class ItemDelegate : public QItemDelegate
{
public:
    ItemDelegate(QObject * parent = nullptr);
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // ITEMDELEGATE_H
