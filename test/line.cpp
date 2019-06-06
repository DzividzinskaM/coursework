#include "line.h"

Printline::Printline(QObject *parent) :
    QObject(parent), QGraphicsItem()
{

}

Printline::~Printline()
{

}

QRectF Printline::boundingRect() const
{
    return QRectF (-30,-30,60,60);
}

void Printline::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(Qt::green);
    painter->drawLine(xx1, yy1, xx2, yy2);
  //  painter->drawRect(-30,-30,60,60);
   // QString num=QString::number(count);
 //  painter->drawText(-3,-1, weight);

    Q_UNUSED(widget);
}


