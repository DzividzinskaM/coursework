#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
//#include <QPainter>
#include <QGraphicsScene>

#include "moveitem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
};


#endif // MAINWINDOW_H
