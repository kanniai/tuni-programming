#include "city.hh"
#include "actor.hh"
#include <QTime>
#include <iostream>
#include "../Course/CourseLib/actors/nysse.hh"

int STOP = 0;
int NYSSE = 1;
int PASSENGER = 2;
int HELICOPTER= 3;
int FIGHTER = 4;
int SPACESHIP = 5;

namespace StudentSide
{
City::City() :
    mainWindow_(nullptr){
    {
    }
}

City::City(StudentSide::MainWindow* mainWindow) :
    mainWindow_(mainWindow)
{

}

StudentSide::City::~City()
{

}

void City::setBackground(QImage &basicbackground, QImage &bigbackground)
{
    mainWindow_->setPicture(basicbackground);
}

void City::addStop(std::shared_ptr<Interface::IStop> stop)
{
    stops_.push_back(stop);
}

void City::setClock(QTime clock)
{
    if (isGameOver()) {
        return;
    }
    mainWindow_->setTime(clock.hour(), clock.minute());
    mainWindow_->showTime();

    int delta = 0;
    int nysses = statistics_.returnNysses();
    if (old_nysses_ == 0) {
        old_nysses_ = nysses;
    } else {
        delta = nysses - old_nysses_;
        old_nysses_ = nysses;
    }
    mainWindow_->nysseCount(nysses, delta);
}

void City::startGame()
{

    for (int i = 0; i < stops_.size(); ++i) {
        Interface::Location location = stops_.at(i)->getLocation();
        mainWindow_->addStop(location.giveX(), location.giveY(), STOP, stops_.at(i));
    }

    for (int i = 0; i < passengers_.size(); ++i) {
        Interface::Location location = passengers_.at(i)->giveLocation();
        mainWindow_->addActor(location.giveX(), location.giveY(), PASSENGER, passengers_.at(i));
    }

    for (int i = 0; i < nysses_.size(); ++i) {
        Interface::Location location = nysses_.at(i)->giveLocation();
        mainWindow_->addActor(location.giveX(), location.giveY(), NYSSE, nysses_.at(i));
    }

    for (auto player: players_) {
        Interface::Location location = player->giveLocation();
        if (helicopter_) {
            mainWindow_->addActor(location.giveX(), location.giveY(), HELICOPTER, player);
            helicopter_ = false;
        } else if (fighter_) {
            mainWindow_->addActor(location.giveX(), location.giveY(), FIGHTER, player);
            fighter_ = false;
        } else if (spaceShip_) {
            mainWindow_->addActor(location.giveX(), location.giveY(), SPACESHIP, player);
            spaceShip_ = false;
        }

    }

}

void City::addActor(std::shared_ptr<Interface::IActor> newactor)
{
    if (isGameOver()) {
        return;
    }
    std::shared_ptr<CourseSide::Nysse> nysse = std::dynamic_pointer_cast<CourseSide::Nysse>(newactor);
    if (nysse != 0) {
        nysses_.push_back(newactor);
        statistics_.newNysse();
    }
    std::shared_ptr<CourseSide::Passenger> passenger = std::dynamic_pointer_cast<CourseSide::Passenger>(newactor);
    if (passenger != 0) {
        passengers_.push_back(newactor);
        statistics_.morePassengers(1);
    }
    std::shared_ptr<StudentSide::Player> player = std::dynamic_pointer_cast<StudentSide::Player>(newactor);
    if (player != 0) {
        players_.push_back(newactor);
    }
}

void City::removeActor(std::shared_ptr<Interface::IActor> actor)
{
    if (isGameOver()) {
        return;
    }
    std::shared_ptr<CourseSide::Nysse> nysse = std::dynamic_pointer_cast<CourseSide::Nysse>(actor);
    if (nysse != 0) {
        QVector<std::shared_ptr<Interface::IActor>>::iterator it = nysses_.begin();
        for ( ; it != nysses_.end(); ++it) {
          if (*it == nysse) {
            it = nysses_.erase(it);
            statistics_.nysseRemoved();
            return;
          }
        }
    }
    std::shared_ptr<CourseSide::Passenger> passenger = std::dynamic_pointer_cast<CourseSide::Passenger>(actor);
    if (passenger != 0) {
        QVector<std::shared_ptr<Interface::IActor>>::iterator it = passengers_.begin();
        for ( ; it != passengers_.end(); ++it) {
          if (*it == passenger) {
            it = passengers_.erase(it);
            return;
          }
        }
    }

}

void City::actorRemoved(std::shared_ptr<Interface::IActor> actor)
{

}
bool City::findActor(std::shared_ptr<Interface::IActor> actor) const
{

    std::shared_ptr<CourseSide::Nysse> nysse = std::dynamic_pointer_cast<CourseSide::Nysse>(actor);
    if (nysse != 0) {
        if ( std::find(nysses_.begin(), nysses_.end(), nysse) != nysses_.end() ) {
           return true;
        } else {
           return false;
        }
    }
    std::shared_ptr<CourseSide::Passenger> passenger = std::dynamic_pointer_cast<CourseSide::Passenger>(actor);
    if (passenger != 0) {
        if ( std::find(passengers_.begin(), passengers_.end(), passenger) != passengers_.end() ) {
           return true;
        } else {
           return false;
        }
    }

}
void City::actorMoved(std::shared_ptr<Interface::IActor> actor)
{
    if (isGameOver()) {
        return;
    }
    std::shared_ptr<CourseSide::Nysse> nysse = std::dynamic_pointer_cast<CourseSide::Nysse>(actor);

    if (nysse != 0) {
        mainWindow_->updateActorCoords(actor->giveLocation().giveX(),
                                       actor->giveLocation().giveY(), actor, NYSSE);
    }
    std::shared_ptr<CourseSide::Passenger> passenger = std::dynamic_pointer_cast<CourseSide::Passenger>(actor);
    if (passenger != 0) {
        mainWindow_->updateActorCoords(actor->giveLocation().giveX(),
                                       actor->giveLocation().giveY(), actor, PASSENGER);
    }
}

std::vector<std::shared_ptr<Interface::IActor> > City::getNearbyActors(Interface::Location loc) const
{

}

bool City::isGameOver() const
{
    return gameOver_;
}

void City::gameOver()
{
    gameOver_ = true;
}

void City::selectVehicle(int num)
{
    if (num == 1) {
        helicopter_ = true;
    } else if (num == 2) {
        fighter_ = true;
    } else if (num == 3) {
        spaceShip_ = true;
    }
}

void City::nysseDestroyed()
{
    statistics_.nysseRemoved();
}

MainWindow* City::returnMainwindow()
{
    return mainWindow_;
}
}
