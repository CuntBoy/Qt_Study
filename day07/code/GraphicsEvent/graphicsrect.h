#ifndef GRAPHICSRECT_H
#define GRAPHICSRECT_H
#include <QGraphicsRectItem>

class GraphicsRect : public QGraphicsRectItem
{
public:
    GraphicsRect(QGraphicsItem *parent = nullptr);
    ~GraphicsRect();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void wheelEvent(QGraphicsSceneWheelEvent *event);
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    virtual void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
private:
    QPointF point_;
    bool isPress_;

};

#endif // GRAPHICSRECT_H
