/**
  * Ohjelmointi 3 projekti - The Last of Bus II
  * Syksy 2020, vastuuopettaja Terhi Kilamo
  *
  * Olli Luukkonen H282332
  * olli.luukkonen@tuni.fi
  *
  * Matias Kanniainen H285295
  * matias.kanniainen@tuni.fi
  */

#ifndef ACTORITEM_HH
#define ACTORITEM_HH

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <iostream>

/**
  * @brief Create QGraphicsItem objects to show actors on map
  */

namespace StudentSide {

class ActorItem : public QGraphicsItem
{
public:
    ActorItem(int x, int y, int type = 0);
    virtual ~ActorItem();
    QRectF boundingRect() const;

    /**
      * @brief Choose image for actors
      */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
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
