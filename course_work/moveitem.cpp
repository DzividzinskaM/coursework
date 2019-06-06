#include "moveitem.h"

MoveItem::MoveItem(QObject *parent) :
    QObject(parent), QGraphicsItem()
{

}

MoveItem::~MoveItem()
{

}

QRectF MoveItem::boundingRect() const
{
    return QRectF (-30,-30,60,60);
}

void MoveItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    painter->setPen(Qt::black);
  //  painter->setBrush(Qt::white);
    painter->setPen(QPen(Qt::blue, 3));
    painter->setBrush(Qt::white);
    painter->drawEllipse(-30, -30, 60, 60);
    QString num=QString::number(count);
    painter->setPen(QPen(Qt::black, 5));
    painter->drawText(-3, 4, num);
    Q_UNUSED(widget);
}

void MoveItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    /* Устанавливаем позицию графического элемента
     * в графической сцене, транслировав координаты
     * курсора внутри графического элемента
     * в координатную систему графической сцены
     * */
    this->setPos(mapToScene(event->pos()));
}

void MoveItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    /* При нажатии мышью на графический элемент
     * заменяем курсор на руку, которая держит этот элемента
     * */
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void MoveItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    /* При отпускании мышью элемента
     * заменяем на обычный курсор стрелку
     * */
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}


