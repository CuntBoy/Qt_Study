#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>

class GraphicsScene : public QGraphicsScene
{
public:
    GraphicsScene(QObject * parent = nullptr);
    ~GraphicsScene();
};

#endif // GRAPHICSSCENE_H
