#include "itemdelegate.h"
#include <QItemDelegate>
#include <QDebug>
#include <QSpinBox>
#include <QLineEdit>
#include <QDateEdit>

ItemDelegate::ItemDelegate(QObject *parent)
    :QItemDelegate(parent)
{

}

QWidget* ItemDelegate::createEditor(QWidget *parent,
                                const QStyleOptionViewItem &option,
                                const QModelIndex &index) const
{
    qDebug()<<__FUNCTION__<<endl;
    if(index.column() == 1)
    {
        QSpinBox * spin = new QSpinBox(parent);
        spin->setMaximum(200);
        spin->setMinimum(0);
        return spin;
    }
    if(index.column() == 2)
    {
        QDateEdit * date = new QDateEdit(parent);
        return date;
    }

//    else
//    {
//        QLineEdit * edit = new QLineEdit(parent);
//        editor = edit;
//    }

    return  QItemDelegate::createEditor(parent,option,index);
}
