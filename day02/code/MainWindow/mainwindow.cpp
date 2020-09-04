#include "mainwindow.h"
#include <QMenuBar>
#include <QDebug>
#include <QToolBar>
#include <QStatusBar>
#include <QTextEdit>
#include <QDockWidget>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QTextEdit * edit = new QTextEdit(this);

    this->resize(640,480);
    this->initMenuBar();   // 菜单栏
    this->initToolBar();   // 工具栏
    QStatusBar* statusb = this->statusBar();     // 状态栏
    statusb->showMessage("OK",5000);
    // 中央窗口
    this->setCentralWidget(edit);
    // 停靠窗口
    this->initDockWidget();


}
void MainWindow::initDockWidget()
{
    QTextEdit * edit = new QTextEdit(this);
    dock_ = new QDockWidget(this);
    this->addDockWidget(Qt::LeftDockWidgetArea,dock_);
    dock_->setWidget(edit);
}
void MainWindow::initToolBar()
{
    QToolBar * toolbar= this->addToolBar("ToolBar");
    toolbar->addAction(open_);
    toolbar->addAction(close_);
    toolbar->addAction(save_);
//    this->addToolBar("ToolBar");
}

void MainWindow::saveSlot()
{
    qDebug()<<"save file success"<<endl;
}
void MainWindow::initMenuBar()
{
    QMenuBar * menuBar = this->menuBar();
    QMenu * fileMenu = new QMenu("File(&F)",menuBar);
    menuBar->addMenu(fileMenu);
    menuBar->addMenu("Help(&H)");

    fileMenu->addAction("default")->setCheckable(true);    //二次操作 是否可以勾选
    fileMenu->addSeparator(); //添加分隔符
    open_ = fileMenu->addAction(QIcon(),"Open");                   // 使用图标  直接加上路径就可以
    close_= fileMenu->addAction("close",this,SLOT(close()));       //
    save_ = fileMenu->addAction(QIcon(),"Save",this,SLOT(saveSlot()),QKeySequence("Ctrl+s"));   //添加快捷键
    fileMenu->addMenu("子菜单")->addAction("default");
}



MainWindow::~MainWindow()
{
}

