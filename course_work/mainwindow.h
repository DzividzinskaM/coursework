#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPainter>
#include <QGraphicsScene>
#include <QList>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QtGui>
#include <QtCore>

#include "moveitem.h"

using namespace std;

#define MAX_NODES 100  // Максимальное количество вершин
#define MAX_EDGES 100  // Максимальное количество ребер в графе

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    int x1_koordinate;
    int x2_koordinate;
    int y1_koordinate;
    int y2_koordinate;
    int **array_;
    /*int last_n;
    struct edge_t;
   int nodes[MAX_NODES];  // Вершины графа.  Значение - "верхняя вершина"*/
   // int getColor(int n);
   //int cmpw(edge_t *a, edge_t *b);

    ~MainWindow();
    int count=0;

private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();




    void on_Prima_clicked();

    void on_Boruvka_clicked();

    void on_Kruskal_clicked();

    void on_Prima_2_clicked();

    void on_radioButton_2_clicked();

    void on_Boruvka_2_clicked();

    void on_Kruskala_clicked();

private:



    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    QList<MoveItem*> vertexlist;
    QVector <QVector<int>> list_of_vertices;

};



#endif // MAINWINDOW_H
