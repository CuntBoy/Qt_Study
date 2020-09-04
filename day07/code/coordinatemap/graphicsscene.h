#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>

class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    GraphicsScene(QObject * parent = nullptr);
    ~GraphicsScene();
};

#endif // GRAPHICSSCENE_H
