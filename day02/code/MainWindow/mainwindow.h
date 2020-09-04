#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QAction>
#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void saveSlot();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void initMenuBar();
    void initToolBar();
    void initDockWidget();
    QAction * open_;
    QAction * close_;
    QAction * save_;
    QDockWidget * dock_;
};
#endif // MAINWINDOW_H
