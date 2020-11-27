#include "actoritem.hh"
#include <QtWidgets>
#include <QPixmap>

const int STOP = 0;
const int NYSSE = 1;
const int PASSENGER = 2;
const int HELICOPTER= 3;
const int FIGHTER = 4;
const int SPACESHIP = 5;
const int CANNON = 6;

namespace StudentSide {

ActorItem::ActorItem(int x, int y, int type):x_(x), y_(y), type_(type)
{
    setPos(mapToParent(x_, y_ ));
}

ActorItem::~ActorItem()
{}

QRectF ActorItem::boundingRect() const
{
    return QRectF(0, 0, WIDTH, HEIGHT);
}

void ActorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                      QWidget *widget)
{
    QRectF bounds = boundingRect();

    QColor color;
    QBrush brush(color);
    if (type_ == STOP) {
        painter->drawImage(bounds, QImage(":/images/stop.jpg"));
    } else if (type_ == NYSSE) {
        painter->drawImage(bounds, QImage(":/images/bus.jpg"));
    } else if (type_ == PASSENGER) {
        // Passengers are not printed on map
    } else if (type_ == HELICOPTER) {
        painter->drawImage(bounds, QImage(":/images/heli.jpg"));
    } else if (type_ == FIGHTER) {
        painter->drawImage(bounds, QImage(":/images/fighter.jpg"));
    } else if (type_ == SPACESHIP) {
        painter->drawImage(bounds, QImage(":/images/spaceship.jpg"));
    } else if (type_ == CANNON) {
        painter->drawImage(bounds, QImage(":/images/cannon.jpg"));
    }
}

void ActorItem::setCoord(int x, int y)
{
    setX( x );
    setY( y );
}
}
