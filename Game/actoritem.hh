#ifndef ACTORITEM_HH
#define ACTORITEM_HH

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <iostream>

/**
  * @brief Base class for class Player
  */



namespace StudentSide {

class ActorItem : public QGraphicsItem
{
public:
    ActorItem(int x, int y, int type = 0);
    virtual ~ActorItem();
    QRectF boundingRect() const;
    QRectF playerRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void selectVehicle(int num);

    void setCoord(int x, int y);

    const int WIDTH = 15;
    const int HEIGHT = 15;
private:
    int x_;
    int y_;
    int type_;   
};

}
#endif // ACTORITEM_HH
