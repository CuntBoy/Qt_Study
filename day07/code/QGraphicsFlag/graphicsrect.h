#ifndef GRAPHICSRECT_H
#define GRAPHICSRECT_H
#include <QGraphicsRectItem>

class GraphicsRect : public QGraphicsRectItem
{
public:
    GraphicsRect(QGraphicsItem *parent = nullptr);
    ~GraphicsRect();
    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent * ev);

};

#endif // GRAPHICSRECT_H
