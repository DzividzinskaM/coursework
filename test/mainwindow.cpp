#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPen>

static int randomBetween(int low, int high)
{
    return(qrand()%((high+1)-low)+low);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Косметическая подготовка приложения
        this->resize(640,640);          // Устанавливаем размеры окна приложения
        this->setFixedSize(640,640);

        scene = new QGraphicsScene(this);   // Инициализируем графическую сцену
        scene->setItemIndexMethod(QGraphicsScene::NoIndex); // настраиваем индексацию элементов

        ui->graphicsView->resize(600,600);  // Устанавливаем размер graphicsView
        ui->graphicsView->setScene(scene);  // Устанавливаем графическую сцену в graphicsView
        ui->graphicsView->setRenderHint(QPainter::Antialiasing);    // Настраиваем рендер
        ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground); // Кэш фона
        ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

        scene->setSceneRect(0,0,500,500); // Устанавливаем размер сцены
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
    MoveItem *item = new MoveItem(count);        // Создаём графический элемента
        int x=randomBetween(30, 470);
        int y=randomBetween(30, 470);
        item->setPos(x, y);  // Устанавливаем случайную позицию элемента
        item->setObjectName(name);

        scene->addItem(item);   // Добавляем элемент на графическую сцену
        count++;
        vertexlist.append(item);
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

 //painter->setPen(QPen(Qt::blue, 3));
  QPen penBlack(Qt::green, 2); // Задаём чёрную кисть
    scene->addLine(x1_number, y1_number, x2_number, y2_number, penBlack);

}

/*void MainWindow :: paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
   //painter.drawLine(0,0,120,120);

   // painter.drawl
    painter.drawLine(x1_koordinate, y1_koordinate, x2_koordinate, y2_koordinate);
}*/



/* Как только один из радиобаттонов оказывается нажатым,
 * вызываем перерисовку содержимого виджета,
 * с которым работаем.
 * */




