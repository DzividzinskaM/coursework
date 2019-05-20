#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPainter>
#include <QGraphicsScene>
#include <QList>
#include <QLabel>
#include <QPushButton>
#include <iostream>
#include <QLineEdit>
#include <QtGui>
#include <QtCore>

#include "moveitem.h"
#include "line.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int x1_koordinate;
    int x2_koordinate;
    int y1_koordinate;
    int y2_koordinate;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int count=0;


private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

    //void on_pushButton_3_clicked();

private:


    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    QList<MoveItem*> vertexlist;
//protected:
   // void paintEvent(QPaintEvent *e);

};



#endif // MAINWINDOW_H
