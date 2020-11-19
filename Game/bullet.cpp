#include "bullet.hh"
const int STEP_SIZE = 5;

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
    QColor color = Qt::white;
    QBrush brush(color);

    painter->setBrush(brush);
    painter->drawEllipse(bounds);
}

void Bullet::move()
{
    double dy = STEP_SIZE * qSin(radianAngle_);
    double dx = STEP_SIZE * qCos(radianAngle_);
    x_ += dx;
    y_ += dy;
    setX(x_);
    setY(y_);
    emit bulletMoved(x_ + dx, y_ + dy);
}

void Bullet::setAngle(int angle)
{
    radianAngle_ = (double) angle* (M_PI/180);
}

void Bullet::stopTimer()
{
    timer_->stop();
}

bool Bullet::isBulletMoving()
{
    return timer_->isActive();
}
}
