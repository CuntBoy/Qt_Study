#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>
class QGraphicsRectItem;
class GraphicsScene : public QGraphicsScene
{
public:
    GraphicsScene(QObject * parent = nullptr);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
    ~GraphicsScene();
private:
    QGraphicsRectItem *rect_;
    QGraphicsEllipseItem * ellipse_;

};

#endif // GRAPHICSSCENE_H
