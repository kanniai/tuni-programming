#include "actoritem.hh"
#include <QtWidgets>

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
    QImage stop(":/../../../Downloads/stop.png");
    //QColor color(type_%256, type_%256, type_%256);
    QColor color;
    if (type_ == 0) {
        color = Qt::blue;
    } else if (type_ == 1) {
        color = Qt::green;
    } else if (type_ == 2) {
        color = Qt::red;
    }
    QBrush brush(color);


    painter->setBrush(brush);
    painter->drawEllipse(bounds);

}

void ActorItem::setCoord(int x, int y)
{
    setX( x );
    setY( y );
}

}
