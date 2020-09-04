#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include "graphicsscene.h"

class GraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    GraphicsView(QWidget *parent = nullptr);
    ~GraphicsView();
    void mousePressEvent(QMouseEvent *event);
private:
    GraphicsScene * scene_;
};
#endif // WIDGET_H
