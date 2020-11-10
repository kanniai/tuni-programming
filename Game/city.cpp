#include "city.hh"
#include "actor.hh"
#include <QTime>
#include "../Course/CourseLib/actors/nysse.hh"

namespace StudentSide
{
City::City() :
    mainWindow_(nullptr){
    {
    }

}

<<<<<<< HEAD
City::City(StudentSide::MainWindow* simpleMainWindow) :
    mainWindow_(simpleMainWindow)
=======
City::City(StudentSide::MainWindow* mainWindow) :
    mainWindow_(mainWindow)
>>>>>>> 25aa94cdc16619dd3edf8810b688ee96eca00267
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
    time_ = clock;
}

void City::startGame()
{

    for (int i = 0; i < stops_.size(); ++i) {
        Interface::Location location = stops_.at(i)->getLocation();
<<<<<<< HEAD
        mainWindow_->addActor(location.giveX(), location.giveY(), 0);
=======
        int locX = location.giveX();
        int locY = location.giveY();
        mainWindow_->addActor(locX, locY, 0);
>>>>>>> 25aa94cdc16619dd3edf8810b688ee96eca00267
    }

    for (int i = 0; i < passengers_.size(); ++i) {
        Interface::Location location = passengers_.at(i)->giveLocation();
        mainWindow_->addActor(location.giveX(), location.giveY(), 2);
    }

    for (int i = 0; i < nysses_.size(); ++i) {
        Interface::Location location = nysses_.at(i)->giveLocation();
<<<<<<< HEAD
        mainWindow_->addActor(location.giveX(), location.giveY(), 1);
    }

    for (auto player: players_) {
        Interface::Location location = player->giveLocation();
        mainWindow_->addActor(location.giveX(), location.giveY(), 3);
=======
        int locX = location.giveX();
        int locY = location.giveY();
        mainWindow_->addActor(locX, locY, 1);
>>>>>>> 25aa94cdc16619dd3edf8810b688ee96eca00267
    }

}

void City::addActor(std::shared_ptr<Interface::IActor> newactor)
{
    std::shared_ptr<CourseSide::Nysse> nysse = std::dynamic_pointer_cast<CourseSide::Nysse>(newactor);

    if (nysse != 0) {
        nysses_.push_back(newactor);
    }
    std::shared_ptr<CourseSide::Passenger> passenger = std::dynamic_pointer_cast<CourseSide::Passenger>(newactor);
    if (passenger != 0) {
        passengers_.push_back(newactor);
    }
    std::shared_ptr<StudentSide::Player> player = std::dynamic_pointer_cast<StudentSide::Player>(newactor);
    if (player != 0) {
        players_.push_back(newactor);
    }
}

void City::removeActor(std::shared_ptr<Interface::IActor> actor)
{
    QVector<std::shared_ptr<Interface::IActor>>::iterator it = actors_.begin();
    for ( ; it != actors_.end(); ) {
      if (*it == actor) {
        it = actors_.erase(it);
        actor->remove();
        // actorRemoved(actor);
      } else {
        ++it;
      }
    }
}

void City::actorRemoved(std::shared_ptr<Interface::IActor> actor)
{

}

bool City::findActor(std::shared_ptr<Interface::IActor> actor) const
{
    if ( std::find(actors_.begin(), actors_.end(), actor) != actors_.end() )
       return true;
    else
       return false;
}
// Logic::advance calls this function
void City::actorMoved(std::shared_ptr<Interface::IActor> actor)
{

}

std::vector<std::shared_ptr<Interface::IActor> > City::getNearbyActors(Interface::Location loc) const
{

}

bool City::isGameOver() const
{

}
}
