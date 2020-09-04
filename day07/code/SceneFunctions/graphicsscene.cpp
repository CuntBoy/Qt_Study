#include "graphicsscene.h"
#include <QGraphicsLineItem>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>

GraphicsScene::GraphicsScene(QObject *parent)
    :QGraphicsScene(parent)
{
    this->setBackgroundBrush(QBrush(QPixmap("E:/Study/My_C++/Qt_study/day07/source/a.jpg")));
    this->setForegroundBrush(QBrush(QColor(125,125,125,125)));
    this->addLine(-500,0,500,0,QPen(Qt::red));
    this->addLine(0,-500,0,500,QPen(Qt::red));
    this->addSimpleText("O(0,0)");
    this->addSimpleText("X")->setPos(400,0);
    this->addSimpleText("Y")->setPos(0,400);

    qDebug()<<this->itemsBoundingRect()<<endl;

    QGraphicsRectItem * item0 = this->addRect(0,0,100,100);
    item0->setBrush(QBrush(Qt::gray));
    item0->setZValue(9);

    item0->setFlags(QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIsMovable);

    QGraphicsRectItem * item1 = this->addRect(0,0,100,100);
    item1->setBrush(QBrush(Qt::green));
    item1->setZValue(10);
    item1->setFlags(QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIsMovable);

    //    this->selectedItems();

    QGraphicsEllipseItem * item2 = this->addEllipse(0,0,100,100);
    item2->setPos(200,200);
    item2->setFlags(QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIsMovable);

}

GraphicsScene::~GraphicsScene()
{
    qDebug()<<__FUNCTION__<<endl;
}
void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    QGraphicsScene::mousePressEvent(event);
    qDebug()<<__FUNCTION__<<event->scenePos()<<endl;
    QAbstractGraphicsShapeItem * rect = dynamic_cast<QAbstractGraphicsShapeItem*>(this->itemAt(event->scenePos(),QTransform()));
    if(rect)
    {
        rect->setBrush(QBrush(Qt::yellow));
    }
}

void GraphicsScene::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key() == Qt::Key_H)
    {
        QList<QGraphicsItem *> items = this->selectedItems();
        foreach (QGraphicsItem * item, items)
        {
            item->hide();
        }
    }
}

