#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>

class GraphicsScene : public QGraphicsScene
{
public:
    GraphicsScene(QObject * parent = nullptr);
    ~GraphicsScene();
    virtual void mousePressEvent(QGraphicsSceneMouseEvent * event);
    virtual void keyPressEvent(QKeyEvent * ev);

};

#endif // GRAPHICSSCENE_H
