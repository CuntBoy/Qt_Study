#include "widget.h"
#include "graphicsscene.h"
#include <QApplication>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GraphicsView w;
    w.show();
    return a.exec();
}
