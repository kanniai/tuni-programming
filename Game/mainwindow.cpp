#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QDebug>

const int PADDING = 10;
const int MATCH_COORDINATES = 9;

const int MAP_LEFT_SIDE_XCOORD = 20;
const int MAP_UPPER_YCOORD = 20;
const int MAP_RIGHT_SIDE_XCOORD = 469;
const int MAP_LOWER_YCOORD = 469;

namespace StudentSide {

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->gameView->setFixedSize(width_, height_);
    ui->centralwidget->setFixedSize(width_ + ui->startButton->width() + PADDING, height_ + PADDING);

    ui->startButton->move(width_ + PADDING , PADDING);

    map = new QGraphicsScene(this);
    ui->gameView->setScene(map);
    map->setSceneRect(0,0,width_,height_);

    resize(minimumSizeHint());
    //ui->gameView->fitInView(0,0, MAPWIDTH, MAPHEIGHT, Qt::KeepAspectRatio);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, map, &QGraphicsScene::advance);
    timer->start(tick_);

    animation_ = new StudentSide::Animation();
    bullet2_ = new StudentSide::Bullet();

    connect(animation_, &StudentSide::Animation::animationLocation, this,
            &StudentSide::MainWindow::checkBulletCollision);
    connect(animation_, &StudentSide::Animation::signalRemoveBullet, this,
            &StudentSide::MainWindow::removeBullet);

    connect(bullet2_, &StudentSide::Bullet::bulletMoved, this,
            &StudentSide::MainWindow::bulletMoved);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setSize(int w, int h)
{
    width_ = w;
    height_ = h;
}

void MainWindow::setTick(int t)
{
    tick_ = t;
}

void MainWindow::addActor(int locX, int locY, int type, std::shared_ptr<Interface::IActor> actor)
{
    ActorItem* nActor = new ActorItem(locX, locY, type);
    map->addItem(nActor);
    last_ = nActor;

    if (type == 1) {
        buses_.insert( {actor, nActor} );
    } else if (type == 2) {
        passengers_.insert( {actor, nActor} );
    } else if (type == 3) {
        player1_.first = actor;
        player1_.second = nActor;
    }
}

void MainWindow::updateCoords(int nX, int nY)
{
    last_->setCoord(nX, nY);
    checkCollision(last_);
}

void MainWindow::updateActorCoords(int nX, int nY, std::shared_ptr<Interface::IActor> actor,
                                   int type)
{
    if (type == 1) {
        std::map<std::shared_ptr<Interface::IActor>,ActorItem*>::iterator it;
        it = buses_.find(actor);
        if (it != buses_.end())
          it->second->setCoord(nX, nY);
    } else if (type == 2) {
        std::map<std::shared_ptr<Interface::IActor>,ActorItem*>::iterator it;
        it = passengers_.find(actor);
        if (it != passengers_.end())
          it->second->setCoord(nX, nY);
    }
}

void StudentSide::MainWindow::MainWindow::showTime()
{
    QString minutes = QString::number(minutes_);
    QString hours = QString::number(hours_);

    if (minutes_ < 10) {
        minutes = "0" + minutes;
    }
    if (hours_ < 10) {
        hours = "0" + hours;
    }

    ui->runningTime->setText(hours + " : " + minutes);
}

void MainWindow::setPicture(QImage &img)
{
    map->setBackgroundBrush(img);
}

void MainWindow::setTime(int hours, int minutes)
{
    hours_ = hours;
    minutes_ = minutes;
}

std::pair<std::shared_ptr<Interface::IActor>, ActorItem *> MainWindow::getPlayer1() const
{
    return player1_;
}

void MainWindow::checkBulletCollision(int animationXCoord_, int animationYCoord_,
                                      int playerXCoord, int playerYCoord)
{
    bullet_->setCoord(animationXCoord_ + playerXCoord, animationYCoord_ + playerYCoord);

    QList<QGraphicsItem *> collidingActors = bullet_->collidingItems();

    if (collidingActors.size() != 0) {
        for (QGraphicsItem* actor: collidingActors) {
            if (actor == player1_.second) {
                continue;
            }
            map->removeItem(actor);
        }
    }      //Miten saan poistettua passengerin logickista?
}

void MainWindow::bulletMoved(int x2, int y2)
{
    bullet2_->setPos(x2, y2);
    checkCollision(bullet2_);

    if (bullet2_->x() < MAP_LEFT_SIDE_XCOORD -30  || bullet2_->y() < MAP_UPPER_YCOORD -20
            || bullet2_->x() > MAP_RIGHT_SIDE_XCOORD + 10 || bullet2_->y() > MAP_LOWER_YCOORD + 10) {
        bullet2_->removeBullet();
        map->removeItem(bullet2_);

    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W) {
        emit buttonPressed('w');
        player1_.second->setRotation(-90);
    } else if (event->key() == Qt::Key_D) {
        emit buttonPressed('d');
        player1_.second->setRotation(0);
    } else if (event->key() == Qt::Key_S) {
        emit buttonPressed('s');
        player1_.second->setRotation(90);
    } else if (event->key() == Qt::Key_A) {
        emit buttonPressed('a');
        player1_.second->setRotation(180);

    } else if (event->key() == Qt::Key_Space) {
        qDebug() << "space pressed";
        spacePressed();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (animation_->isBulletMoving() == true) {
        return;
    }
    int x2 = event->x() - MATCH_COORDINATES;
    int y2 = event->y() - MATCH_COORDINATES;

    int x = player1_.first->giveLocation().giveX();
    int y = player1_.first->giveLocation().giveY();

    bullet_ = new ActorItem(x, y, 4);
    map->addItem(bullet_);

    animation_->newAnimation(x, y, x2, y2, bullet_);

}

void MainWindow::spacePressed()
{
    if (bullet2_->isBulletMoving() == true) {
        return;
    }

    bullet2_->shoot(player1_.first->giveLocation().giveX(),
                                      player1_.first->giveLocation().giveY(),
                                player1_.second->rotation());
    map->addItem(bullet2_);
}

void MainWindow::checkCollision(QGraphicsItem* actorItem)
{

    QList<QGraphicsItem *> collidingActors = actorItem->collidingItems();
    if (collidingActors.size() != 0) {
        for (QGraphicsItem* actor: collidingActors) {
            if (actor == bullet2_) {
                continue;
            } else if (actor == player1_.second) {
                return;
            }

            map->removeItem(actor);
            bullet2_->removeBullet();
            map->removeItem(bullet2_);
            break;
            //std::shared_ptr<Interface::IActor> IActor = getActor(actorItem);

            // if actor is stop, do not remove it
            //if (IActor == nullptr) {
              //  return;
            //}

            //Passenger::remove()
            // Miten tuhota actorit logicista?
            //https://www.boost.org/doc/libs/1_66_0/libs/bimap/doc/html/boost_bimap/one_minute_tutorial.html
        }
    }
}

std::shared_ptr<Interface::IActor> MainWindow::getActor(ActorItem* actorItem)
{
    return nullptr;
}

void MainWindow::removeBullet()
{
    map->removeItem(bullet_);
}

void StudentSide::MainWindow::on_startButton_clicked()
{
    qDebug() << "Start clicked";
    emit gameStarted();
}
}
