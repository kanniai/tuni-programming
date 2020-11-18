#include "actoritem.hh"
#include <QtWidgets>
#include <QPixmap>

namespace StudentSide {

ActorItem::ActorItem(int x, int y, int type):x_(x), y_(y), type_(type)
{
    setPos(mapToParent(x_, y_ ));
}

ActorItem::~ActorItem()
{

}

QRectF ActorItem::boundingRect() const
{
    return QRectF(0, 0, WIDTH, HEIGHT);
}

void ActorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QRectF bounds = boundingRect();

    //QColor color(type_%256, type_%256, type_%256);
    QColor color;
    QBrush brush(color);
    if (type_ == 0) {
        painter->drawImage(bounds, QImage(":/images/stop.jpg"));
    } else if (type_ == 1) {
        painter->drawImage(bounds, QImage(":/images/bus.jpg"));
    } else if (type_ == 2) {
        //painter->drawImage(bounds, QImage(":/images/passenger.jpg"));
        color = Qt::red;
        QBrush brush(color);
        painter->setBrush(brush);
        painter->drawEllipse(bounds);
    } else if (type_ == 3) {
        painter->drawImage(bounds, QImage(":/images/fighter.jpg"));
    } else if (type_ == 4) {
        color = Qt::black;
        QBrush brush(color);
        painter->setBrush(brush);
        painter->drawEllipse(bounds);
    }



}

void ActorItem::setCoord(int x, int y)
{
    setX( x );
    setY( y );
}

}
