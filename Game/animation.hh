#ifndef ANIMATION_HH
#define ANIMATION_HH
#include "actoritem.hh"

#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <QTimer>
#include <QObject>


namespace StudentSide {

class Animation : public QObject
{
    Q_OBJECT

public:
    Animation();
    void newAnimation(int x, int y, int x2, int y2, ActorItem* bullet);
    void removeBullet();
    bool isBulletMoving();

signals:
    void animationLocation(int x, int y, int playerXCoord, int playerYCoord);
    void signalRemoveBullet();

private slots:
    void checkBulletCollision(int playerXCoord,int playerYCoord);

private:
    QTimeLine *timeLineTimer_;
    int step_;
    int animationXCoord_;
    int animationYCoord_;
    QGraphicsItemAnimation *animation_;

};
}

#endif // ANIMATION_HH
