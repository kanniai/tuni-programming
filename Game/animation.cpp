#include "animation.hh"


namespace StudentSide {

Animation::Animation()
{
    timeLineTimer_ = new QTimeLine(1000);
    timeLineTimer_->setFrameRange(0, 1);
    connect(timeLineTimer_, &QTimeLine::frameChanged, this, &Animation::removeBullet);

}

void Animation::newAnimation(int x, int y, int x2, int y2, ActorItem* bullet)
{
    double dx = ((double)x2 -(double)x) / 200;
    double dy = ((double)y2 -(double)y) / 200;

    animation_ = new QGraphicsItemAnimation;

    animation_->setItem(bullet);
    animation_->setTimeLine(timeLineTimer_);

    for (step_ = 0; step_ < 200; ++step_) {
        animation_->setTranslationAt(step_ / 200.0, dx * step_, dy * step_);
        checkBulletCollision(x, y);
    }
    bullet->setCoord(x, y);
    timeLineTimer_->start();
}

void Animation::checkBulletCollision(int playerXCoord,int playerYCoord)
{
    animationXCoord_ = animation_->xTranslationAt(step_);
    animationYCoord_ = animation_->yTranslationAt(step_);
    emit animationLocation(animationXCoord_, animationYCoord_, playerXCoord, playerYCoord);
}

void Animation::removeBullet()
{
    timeLineTimer_->setCurrentTime(0);
    timeLineTimer_->stop();
    animation_->clear();
    emit signalRemoveBullet();
}

bool Animation::isBulletMoving()
{
    if (timeLineTimer_->currentTime() != 0) {
        return true;
    }
    return false;
}
}
