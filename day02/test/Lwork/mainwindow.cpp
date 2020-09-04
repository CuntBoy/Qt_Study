#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLineEdit>
#include <QDebug>
#include <QString>
#include <QByteArray>
#include <QFile>
#include <QFileDialog>
#include <QTextEdit>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    file_ = new QFile(this);
    edit_ = new QTextEdit(this);
    this->setCentralWidget(edit_);
    initMenuBar();
    QStatusBar* statusb = this->statusBar();
    statusb->showMessage("OK",5000);

}


void MainWindow::initMenuBar()
{
    this->resize(640,480);
    QMenuBar * menubar = this->menuBar();
    QMenu *fileMenu = menubar->addMenu("FILE (&F) ");
    fileMenu->addAction("CREATE", this,SLOT(creatSLot()), QKeySequence("Ctrl+N"));
    fileMenu->addAction("OPEN",   this,SLOT(openSLot()),  QKeySequence("Ctrl+O"));
    fileMenu->addAction("SAVE",   this,SLOT(saveSLot()),  QKeySequence("Ctrl+S"));
    fileMenu->addAction("Save As",this,SLOT(saveAsSLot()),QKeySequence("Ctrl+Shift+S"));
    fileMenu->addAction("CLOSE",  this,SLOT(closeSLot()), QKeySequence("Ctrl+D"));

    QMenu *styleMenu = menubar->addMenu("Style (&S)");
    QAction * warpAction = styleMenu->addAction("WARP(W)",this,SLOT(warpSlot(bool)));
    warpAction->setCheckable(true);
    warpAction->setChecked(true);

}

void MainWindow::warpSlot(bool isChecked)
{
    isChecked?edit_->setWordWrapMode(QTextOption::WrapAtWordBoundaryOrAnywhere)
            :edit_->setWordWrapMode(QTextOption::NoWrap);
}

void MainWindow::creatSLot()
{
    if(edit_->document()->isModified())
    {
        int sb =  QMessageBox::warning(this,"Warnning","�Ƿ񱣴棿",QMessageBox::Save|QMessageBox::No|QMessageBox::Cancel);
        switch (sb) {
        case QMessageBox::Save:
            if(curpath_.isEmpty())
            {
                if(saveAsSLot())
                    break;
            }
            else
            {
                saveSLot();
            }
            break;
        case QMessageBox::No:
        case QMessageBox::Cancel:
            edit_->clear();
            curpath_.clear();
            break;
        default:
            break;
        }
    }else
    {
        edit_->clear();
        curpath_.clear();
    }
}

void MainWindow::openSLot()
{
    QString filename = QFileDialog::getOpenFileName(this,"OPEN","","text(*.txt)");
    if(QFileInfo(filename).isFile())
    {
        file_->setFileName(filename);
        file_->open(QIODevice::ReadWrite|QIODevice::Text);
        edit_->setText(file_->readAll());
        file_->close();
    }
}

void MainWindow::saveSLot()
{
    if(curpath_.isEmpty())
    {
        saveAsSLot();
    }
    file_->open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate);
    file_->write(edit_->toPlainText().toUtf8());
    file_->close();

}

bool MainWindow::saveAsSLot()
{
    QString filename = QFileDialog::getSaveFileName(this,"Save AS",curpath_,"text(*.txt)");
    if(QFileInfo(filename).isNativePath())
    {
        curpath_ = filename;
        file_->setFileName(filename);
        file_->open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate);
        file_->write(edit_->toPlainText().toUtf8());
        file_->close();

    }
    return filename.isEmpty();

}

void MainWindow::closeSLot()
{

}



MainWindow::~MainWindow()
{
}

