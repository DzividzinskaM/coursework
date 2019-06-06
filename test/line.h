#ifndef LINE_H
#define LINE_H


#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <QString>


using namespace std;

class Printline : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    int xx1, yy1, xx2, yy2, weight;
    explicit Printline(QObject *parent=nullptr);
   Printline(int x1, int y1, int x2, int y2, int weight_)
    {
        xx1=x1;
        yy1=y1;
        xx2=x2;
        yy2=y2;
        weight=weight_;
    }
    ~Printline();

signals:

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public slots:
};



#endif // LINE_H
