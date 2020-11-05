#include "city.hh"
#include "actor.hh"
#include <QTime>
#include "simplemainwindow.hh"


namespace StudentSide
{
City::City() :
    simpleMainWindow_(nullptr){
    {
    }

}

City::City(StudentSide::MainWindow* simpleMainWindow) :
    simpleMainWindow_(simpleMainWindow)
{

}

StudentSide::City::~City()
{

}

void City::setBackground(QImage &basicbackground, QImage &bigbackground)
{
    simpleMainWindow_->setPicture(basicbackground);
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
        int locX = location.giveX();
        int locY = location.giveY();
        // if actor == bus
        // if actor == passenger
        simpleMainWindow_->addActor(locX, locY);

    }
}

void City::addActor(std::shared_ptr<Interface::IActor> newactor)
{

    actors_.push_back(newactor);
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
