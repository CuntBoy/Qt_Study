#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

class QFile;
class QTextEdit;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    void initMenuBar();

private:
    QFile * file_;
    QTextEdit * edit_;
    QString curpath_;
public slots:
    void warpSlot(bool isChecked);
    void creatSLot() ;
    void openSLot()  ;
    void saveSLot()  ;
    bool saveAsSLot()  ;
    void closeSLot() ;
};
#endif // MAINWINDOW_H
