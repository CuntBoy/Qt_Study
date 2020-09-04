#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>  // 圆
#include <QGraphicsSimpleTextItem>
#include <QGraphicsPixmapItem>

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    QGraphicsView view;  //视图

    //添加场景
    QGraphicsScene scene;
    view.setScene(&scene);

    // 添加图元 线
    QGraphicsLineItem line;
    line.setLine(0,0,100,100);

    scene.addItem(&line);
    line.setPen(QPen(Qt::red));

    //添加矩形
    //    QGraphicsRectItem rect;
    //    rect.setRect(0,0,200,100);
    //    scene.addItem(&rect);
    //    rect.setPen(QPen(Qt::blue));
    QGraphicsRectItem * rect = scene.addRect(100,100,100,100,QPen(Qt::blue),QBrush(Qt::green));
    rect->setPos(0,100);

    QGraphicsEllipseItem * ellipse = scene.addEllipse(200,200,100,100,QPen(Qt::red),QBrush(Qt::yellow));
    Q_UNUSED(ellipse);
    QGraphicsSimpleTextItem * text = scene.addSimpleText("hello bun",QFont("system",40));
    text->setBrush(QBrush(Qt::red));
    text->setPen(QPen(Qt::yellow,5));

    // 添加图片
//    QGraphicsPixmapItem * pixmap = scene.addPixmap(QPixmap("E:/Study/My_C++/Qt_study/day07/source/QGraphicsPixmap.jpg"));

    view.show();
    return app.exec();
}
