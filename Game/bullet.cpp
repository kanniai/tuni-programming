#include "bullet.hh"
const int HELIBULLETSPEED = 10;
const int FIGHTERBULLETSPEED = 6;
const int SPACEBULLETSPEED = 2;

namespace StudentSide {

Bullet::Bullet()
{
    timer_ = new QTimer();
    connect(timer_, &QTimer::timeout, this, &Bullet::move);
}

Bullet::~Bullet()
{}

void Bullet::shoot(int x, int y, int angle)
{
     x_ = x;
     y_ = y;
     radianAngle_ = (double) angle* (M_PI/180);
     timer_->start(1000/60);
}

QRectF Bullet::boundingRect() const
{
    return QRectF(0, 0, WIDTH, HEIGHT);
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF bounds = boundingRect();
    QColor color = Qt::black;
    QBrush brush(color);

    painter->setBrush(brush);
    painter->drawEllipse(bounds);
}

void Bullet::move()
{
    double dy = bulletSpeed_ * qSin(radianAngle_);
    double dx = bulletSpeed_ * qCos(radianAngle_);
    x_ += dx;
    y_ += dy;
    setX(x_);
    setY(y_);
    emit bulletMoved(x_ + dx, y_ + dy);
}

void Bullet::stopTimer()
{
    timer_->stop();
}

void Bullet::setBulletSpeed(int num)
{
    if (num == 1) {
        bulletSpeed_ = HELIBULLETSPEED;
    } else if (num == 2) {
        bulletSpeed_ = FIGHTERBULLETSPEED;
    } else if (num == 3) {
        bulletSpeed_ = SPACEBULLETSPEED;
    }
}

bool Bullet::isBulletMoving()
{
    return timer_->isActive();
}
}
