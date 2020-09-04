#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsView>

class GraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    GraphicsView(QWidget *parent = nullptr);
    ~GraphicsView();
};
#endif // WIDGET_H
