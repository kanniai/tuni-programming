#ifndef BULLET_HH
#define BULLET_HH
#include <QTimer>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QObject>
#include <qmath.h>
#include <QDebug>

const int WIDTH = 15;
const int HEIGHT = 15;

namespace StudentSide {

class Bullet : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    Bullet();
    virtual ~Bullet();
    void shoot(int x, int y, int angle);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void move();
    void setAngle(int angle);
    void removeBullet();
    bool isBulletMoving();

signals:
    void bulletMoved(int x2, int y2);

private:
    int x_;
    int y_;
    double radianAngle_;
    QTimer* timer_;

};

}
#endif // BULLET_HH
