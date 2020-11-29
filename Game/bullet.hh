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

#ifndef BULLET_HH
#define BULLET_HH
#include <QTimer>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QObject>
#include <qmath.h>
#include <QDebug>

/**
  * @brief Defines a bullet that moves when user shoots a gun
  */

const int WIDTH = 15;
const int HEIGHT = 15;

namespace StudentSide {

class Bullet : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    Bullet();
    virtual ~Bullet();

    /**
     * @brief Initializes bullet coordinates and angle. Start timer
     * @param angle in degrees.
     * @param x and y: initial coordinates of bullet
     */
    void shoot(int x, int y, int angle);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    /**
     * @brief Timer is connected to this function
     * move() emits bulletMoved which is connected to MainWindow
     */
    void move();
    void stopTimer();

    void setBulletSpeed(int num);

    /**
     * @brief return true if timer is active
     */
    bool isBulletMoving();

signals:
    void bulletMoved(int x2, int y2);

private:
    int x_;
    int y_;
    double radianAngle_;
    QTimer* timer_;
    int bulletSpeed_;

};
}
#endif // BULLET_HH
