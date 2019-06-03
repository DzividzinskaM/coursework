#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPen>
#include <iostream>
#include <QVector>
#include <QtDebug>
#include <ctime>
using namespace std;
static int randomBetween(int low, int high)
{
    return(qrand()%((high+1)-low)+low);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
        this->resize(640,640);
        this->setFixedSize(640,640);

        scene = new QGraphicsScene(this);
        scene->setItemIndexMethod(QGraphicsScene::NoIndex);

        ui->graphicsView->resize(600,600);
        ui->graphicsView->setScene(scene);
        ui->graphicsView->setRenderHint(QPainter::Antialiasing);
        ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
        ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

        scene->setSceneRect(0,0,500,500);
}

MainWindow::~MainWindow()
{
    delete ui;
}


/* Метод, в котором происходит рисование
 * */
void MainWindow::on_pushButton_clicked()
{
    QString name=QString ::number(count);
    MoveItem *item = new MoveItem(count);        // Создаём графический элемент
        int x=randomBetween(30, 470);
        int y=randomBetween(30, 470);
        item->setPos(x, y);  // Устанавливаем случайную позицию элемента
        item->setObjectName(name);

        scene->addItem(item);   // Добавляем элемент на графическую сцену
        list_of_vertices.push_back(QVector <int>());
        list_of_vertices[count].push_back(count);
        count++;
        vertexlist.append(item);

        array_=new int*[vertexlist.length()];
        for(int i=0; i<vertexlist.length(); i++)
            array_[i]=new int [vertexlist.length()];

        for(int i=0; i<vertexlist.length(); i++)
        {
            for(int j=0; j<vertexlist.length(); j++)
            {
                array_[i][j]=0;
            }
        }
}

void MainWindow::on_pushButton_2_clicked()
{
    QString vertex1=ui->vertex1->text();
    QString vertex2=ui->vertex2->text();
    QString weight=ui->weight->text();

   int vertex1_num=QString(vertex1).toInt();
     MoveItem *item1 = new MoveItem();
   item1=vertexlist.at(vertex1_num);
   double x1_number=item1->x();
   double y1_number=item1->y();


 int vertex2_num=QString(vertex2).toInt();
   MoveItem *item2 = new MoveItem();
 item2=vertexlist.at(vertex2_num);
 double x2_number=item2->x();
 double y2_number=item2->y();


    QPen penBlack(Qt::blue, 2);
    scene->addLine(x1_number, y1_number, x2_number, y2_number, penBlack);
    double x_average=(x1_number+x2_number)/2;
    double y_average=(y1_number+y2_number)/2;
    scene->addText(weight)->setPos(x_average, y_average);

    //int num=0;
   QString name=QString:: number(vertex1_num);
      MoveItem *item = new MoveItem(vertex1_num);
      item1=vertexlist.at(vertex1_num);
      item->setPos(x1_number, y1_number);
      item->setObjectName(name);

      scene->addItem(item);  // Добавляем элемент на графическую сцену*/

      name=QString:: number(vertex2_num);
        MoveItem *item0 = new MoveItem(vertex2_num);
        item1=vertexlist.at(vertex2_num);
        item0->setPos(x2_number, y2_number);
        item0->setObjectName(name);

        scene->addItem(item0);  // Добавляем элемент на графическую сцену*/



    array_[vertex1_num][vertex2_num]=array_[vertex2_num][vertex1_num]=weight.toInt();
    //ui->matrix->setText(QString :: number(vertexlist.length()));
}


/* Как только один из радиобаттонов оказывается нажатым,
 * вызываем перерисовку содержимого виджета,
 * с которым работаем.
 * */


void MainWindow::on_pushButton_3_clicked()
{
    int n=vertexlist.length();
    int *path=new int [n];
    int path_index = 0;
    int *visited = new int[n];
        for (int i = 0; i < n; i++)
            visited[i] = 0;

    int min, mincost = 0;
    int a, b, u, v, i, j, ne = 0;


    for (i = 0; i <n; i++)
            for (j = 0; j < n; j++)
            {
                if (array_[i][j] == 0)
                    array_[i][j] = 999; //999 - это что-типа бесконечности. Должно быть больше чем значения веса каждого из ребер в графе
            }
    visited[0] = 1;


    while (ne < n-1)
    {
        for (i = 0, min = 999; i < n; i++)
            for (j = 0; j < n; j++)
                if (array_[i][j] < min)
                    if (visited[i] != 0)
                    {
                        min = array_[i][j];
                        a = u = i;
                        b = v = j;
                    }
        if (visited[u] == 0 || visited[v] == 0)
        {
            path[path_index] = b;
            path_index++;
            //cout<<"\n "<<ne++<<"  "<<a<<"  "<<b<<min; //Можно вывести так
            ne++; //если строчку выше раскомментировать - эту закомментировать
            mincost += min;
            visited[b] = 1;

            MoveItem *item1 = new MoveItem();
            item1=vertexlist.at(a);
            double x1=item1->x();
            double y1=item1->y();

            MoveItem *item2 = new MoveItem();
            item2=vertexlist.at(b);
            double x2=item2->x();
            double y2=item2->y();

            QPen penBlack(Qt::red, 3);
            scene->addLine(x1, y1, x2, y2, penBlack);

            QString name=QString:: number(a);
               MoveItem *item = new MoveItem(a);
               item1=vertexlist.at(a);
               item->setPos(x1, y1);
               item->setObjectName(name);

               scene->addItem(item);  // Добавляем элемент на графическую сцену*/

               name=QString:: number(b);
                 MoveItem *item0 = new MoveItem(b);
                 item1=vertexlist.at(b);
                 item0->setPos(x2, y2);
                 item0->setObjectName(name);
                 scene->addItem(item0);  // Добавляем элемент на графическую сцену*/
        }
        array_[a][b] = array_[b][a] = 999;
    }
    
    
   /* QString s="0->";
    for (int i=0; i<n-1; i++)
    {
        s=s+QString::number(path[i])+"->";
    }*/
    ui->matrix->setText(QString::number(mincost));

}
void MainWindow::on_Boruvka_clicked()
{
  QPen pen(Qt::green, 3);
  int min = INT_MAX;
  int i_min = -1, min_cost = 0;
  int k = list_of_vertices.length();
  QVector <int> route;
  for (int i = 0 ; i < k; i++)
  {
      route.push_back(i);
  }
  for (int i = 0; i < list_of_vertices.length(); i++)
  {
      for (int j = 0; j < list_of_vertices.length(); j++)
      {
          if (array_[i][j] > 0 && array_[i][j] < min)
          {
              min = array_[i][j];
              i_min = j;
          }
      }
     if (i_min != -1)
      {
        if (i != route[i_min])
        {
         if (!list_of_vertices[i_min].isEmpty())
         {
            route[i] = i_min;
            while (!list_of_vertices[i].isEmpty())
            {
               list_of_vertices[i_min].push_back(list_of_vertices[i].front());
               list_of_vertices[i].pop_front();
            }
         }
         else
         {
             route[i] = route[i_min];
             while (!list_of_vertices[i].isEmpty())
             {
             list_of_vertices[route[i_min]].push_back(list_of_vertices[i].front());
             list_of_vertices[i].pop_front();
             }
         }
         MoveItem *temp = new MoveItem();
         temp = vertexlist.at(i);
         double temp_x = temp->x();
         double temp_y = temp->y();
         MoveItem *temp2 = new MoveItem();
         temp2 = vertexlist.at(i_min);
         double temp2_x = temp2->x();
         double temp2_y = temp2->y();
         min_cost  += array_[i][i_min];
         scene->addLine(temp_x, temp_y, temp2_x, temp2_y, pen);
         k--;
       }
       min = INT_MAX;
       i_min = -1;
     }
  }
  if (k==1) ui->matrix->setText(QString::number(min_cost));
  else
  {
      cout <<"-------------------------------------------------------------" << endl;
      for (int s = 0; s < list_of_vertices.length(); s++)
      {
          for (int h = 0; h < list_of_vertices[s].length(); h++)
          {
              cout << list_of_vertices[s][h] << " ";
          }
          cout << endl;
      }
      cout <<"-------------------------------------------------------------" << endl;
      int start = -1, finish = -1;
      int src = 0;
      int end = -1;
      while (k != 1)
      {
          for (int p = 0; p < list_of_vertices.length(); p++)
          {
              if (!list_of_vertices[p].isEmpty())
              {
                  if (start == -1)
                  {
                      start = p;
                      continue;
                  }
                  else
                  {
                          finish = p;
                          min = INT_MAX;
                          i_min = -1;
                          for (finish; finish < list_of_vertices.length(); finish++)
                          {
                            if (!list_of_vertices[finish].isEmpty())
                            {
                                 for (int i = 0; i < list_of_vertices[start].length(); i++)
                                 {
                                    for (int j = 0; j < list_of_vertices[finish].length(); j++)
                                    {
                                        if (array_[list_of_vertices[start][i]][list_of_vertices[finish][j]] > 0 && array_[list_of_vertices[start][i]][list_of_vertices[finish][j]] < min)
                                        {
                                        src = i;
                                        min = array_[list_of_vertices[start][i]][list_of_vertices[finish][j]];
                                        i_min = j;
                                        end = finish;
                                        }
                                    }
                                 }
                            }
                          }
                          MoveItem *temp = new MoveItem();
                          temp = vertexlist.at(list_of_vertices[start][src]);
                          double temp_x = temp->x();
                          double temp_y = temp->y();
                          MoveItem *temp2 = new MoveItem();
                          temp2 = vertexlist.at(list_of_vertices[end][i_min]);
                          double temp2_x = temp2->x();
                          double temp2_y = temp2->y();
                          min_cost  += array_[list_of_vertices[start][src]][list_of_vertices[end][i_min]];
                          scene->addLine(temp_x, temp_y, temp2_x, temp2_y, pen);
                          k--;
                          while (!list_of_vertices[start].isEmpty())
                          {
                              list_of_vertices[end].push_back(list_of_vertices[start].front());
                              list_of_vertices[start].pop_front();
                          }
                          break;
                      }
                 }

           }
          start = finish = -1;
          for (int s = 0; s < list_of_vertices.length(); s++)
          {
              for (int h = 0; h < list_of_vertices[s].length(); h++)
              {
                  cout << list_of_vertices[s][h] << " ";
              }
              cout << endl;
          }
          cout <<"-------------------------------------------------------------" << endl;
          }
      ui->matrix->setText(QString::number(min_cost));
  }
}
