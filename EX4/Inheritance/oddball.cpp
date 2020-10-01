#include "oddball.hh"
#include "constants.hh"

#include <QDebug>

OddBall::OddBall():
    MovingObject::MovingObject()
{
    speed_ = randomValue(1, 20);
    dir_x_ = randomValue(-10, 10);
    dir_y_ = randomValue(-10, 10);
    qDebug() << "Constucted FastBall with speed " << speed_ << " direction: "
             << dir_x_ << ", " << dir_y_;

}

void OddBall::move()
{
    int new_x = x_ + dir_x_ * speed_;
    int new_y = y_ + dir_y_ * speed_;

    x_ = std::max(0, std::min(new_x, VIEW_WIDTH));
    y_ = std::max(0, std::min(new_y, VIEW_HEIGHT));

    qDebug() << "New coord: " << x_ << ", " << y_;
}
