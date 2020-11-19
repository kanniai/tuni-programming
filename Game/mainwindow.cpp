#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QDebug>
#include <iostream>

const int MATCH_COORDINATES = 9;

const int MAP_LEFT_SIDE_XCOORD = 20;
const int MAP_UPPER_YCOORD = 20;
const int MAP_RIGHT_SIDE_XCOORD = 469;
const int MAP_LOWER_YCOORD = 469;

const int PADDING = 40;
const int NEXTROW = 30;
const int WINDOW_WIDTH = 700;
const int WINDOW_HEIGHT = 700;

const int ACTOR_WIDTH = 15;
const int ACTOR_HEIGHT = 15;

const int MAP_CENTER_XCOORD = 250;
const int MAP_CENTER_YCOORD = 250;


namespace StudentSide {

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->gameView->setFixedSize(width_, height_);
    ui->centralwidget->setFixedSize(WINDOW_WIDTH + ui->startButton->width() + PADDING, WINDOW_HEIGHT+ PADDING);

    ui->startButton->move(width_ + PADDING , PADDING);
    ui->timeLabel->move(width_ + PADDING, 3*NEXTROW);
    ui->runningTime->move(width_ + 3*PADDING, 3*NEXTROW);
    ui->timeFrame->move(width_ + 2.75*PADDING, 3*NEXTROW);

    ui->busesLabel->move(width_ + PADDING, 5*NEXTROW);
    ui->busCount->move(width_ + 4*PADDING, 5*NEXTROW);
    ui->busesAdded->move(width_ + PADDING, 6*NEXTROW);
    ui->busesAdded->setText("Testi");

    ui->statisticsLabel->move(width_ + 1.2*PADDING, 7.2*NEXTROW);
    ui->statisticsLabel->setStyleSheet("border-bottom-width: 1px; border-bottom-style: solid; border-radius: 0px");
    ui->destroyedTextLabel->move(width_ + PADDING, 8.5*NEXTROW);
    ui->destroyedLabel->move(width_ + 6*PADDING, 8.5*NEXTROW);
    ui->killedTextLabel->move(width_ + PADDING, 9.5*NEXTROW);
    ui->killedLabel->move(width_ + 6*PADDING, 9.5*NEXTROW);
    ui->statisticsFrame->move(width_ + 0.8*PADDING, 7*NEXTROW);


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
    if (type == 1) {
        std::shared_ptr<CourseSide::Nysse> nysse =
                       std::dynamic_pointer_cast<CourseSide::Nysse> (actor);
        buses_.insert( {nysse, nActor} );
    } else if (type == 2) {

        std::shared_ptr<CourseSide::Passenger> passenger =
                       std::dynamic_pointer_cast<CourseSide::Passenger> (actor);

        passengers_.insert( {passenger, nActor} );

        if (passenger->getStop() != nullptr || passenger->isInVehicle()) {
            return;
        }

    } else if (type == 3) {
        player1_.first = actor;
        player1_.second = nActor;
        player1_.second->setTransformOriginPoint(WIDTH/2, WIDTH/2);
    }

    map->addItem(nActor);
    last_ = nActor;
}

void MainWindow::addStop(int locX, int locY, int type, std::shared_ptr<Interface::IStop> stop)
{
    std::shared_ptr<CourseSide::Stop> stop2 =
                   std::dynamic_pointer_cast<CourseSide::Stop> (stop);
    ActorItem* nActor = new ActorItem(locX, locY, type);
    map->addItem(nActor);
    stops_.insert({stop2, nActor});

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
        std::map<std::shared_ptr<CourseSide::Nysse>,ActorItem*>::iterator it;
        std::shared_ptr<CourseSide::Nysse> nysse =
                       std::dynamic_pointer_cast<CourseSide::Nysse> (actor);
        it = buses_.find(nysse);
        if (it != buses_.end())
          it->second->setCoord(nX, nY);

    } else if (type == 2) {
        std::shared_ptr<CourseSide::Passenger> passenger =
                       std::dynamic_pointer_cast<CourseSide::Passenger> (actor);
        std::map<std::shared_ptr<CourseSide::Passenger>,ActorItem*>::iterator it;
        it = passengers_.find(passenger);
        if (it != passengers_.end())
            //if (!it->first->isInVehicle()) {
              //  ActorItem* nActor = new ActorItem(it->first->giveLocation().giveX(),
                //                                  it->first->giveLocation().giveY(), type);
                //map->addItem(nActor);
            //}

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

void MainWindow::nysseCount(int count, int delta)
{
    ui->busCount->setText(QString::number(count));
    if (delta > 0) {
        ui->busesAdded->setText(QString::number(delta)+ " new buses added");
    }
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
    map->addItem(bullet2_);
    bullet2_->setPos(x2, y2);
    checkCollision(bullet2_);

    if (bullet2_->x() < MAP_LEFT_SIDE_XCOORD -30  || bullet2_->y() < MAP_UPPER_YCOORD -20
            || bullet2_->x() > MAP_RIGHT_SIDE_XCOORD + 10 || bullet2_->y() > MAP_LOWER_YCOORD + 10) {
        bullet2_->stopTimer();
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
    std::cout << passengers_.size() << std::endl;

}

void MainWindow::checkCollision(QGraphicsItem* actorItem)
{

    QList<QGraphicsItem *> collidingActors = actorItem->collidingItems();
    if (collidingActors.size() != 0) {
        for (QGraphicsItem* actor: collidingActors) {
            if (actor == bullet2_) {
                continue;
            } else if (actor == player1_.second) {
                continue;
            }

            for(auto nysse: buses_) {
                if (nysse.second->x() == actor->x() && nysse.second->y() == actor->y()) {

                    map->removeItem(nysse.second);
                    bullet2_->stopTimer();
                    map->removeItem(bullet2_);
                    std::vector<std::shared_ptr<Interface::IPassenger>> passengersInNysse =
                            nysse.first->getPassengers();
                    for (auto passenger: passengersInNysse) {
                        passenger->remove();

                    }
                }
            }
            for(auto stop: stops_) {
                if (stop.second->x() == actor->x() && stop.second->y() == actor->y()) {
                    bullet2_->stopTimer();
                    map->removeItem(bullet2_);
                    std::vector<std::shared_ptr<Interface::IPassenger>> passengersInNysse =
                            stop.first->getPassengers();
                    for (auto passenger: passengersInNysse) {
                        passenger->remove();

                    }
                }
            }
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

