#include "city.hh"
#include "graphics/simplemainwindow.hh"

namespace StudentSide
{

City::City(CourseSide::SimpleMainWindow* simpleMainWindow) :
    simpleMainWindow_(simpleMainWindow)
{

}

StudentSide::City::~City()
{

}

void StudentSide::City::setBackground(QImage &basicbackground, QImage &bigbackground)
{
    simpleMainWindow_->setPicture(basicbackground);
}

void City::addStop(std::shared_ptr<Interface::IStop> stop)
{

}

void City::startGame()
{

}

void City::addActor(std::shared_ptr<Interface::IActor> newactor)
{

}

void City::removeActor(std::shared_ptr<Interface::IActor> actor)
{

}

void City::actorRemoved(std::shared_ptr<Interface::IActor> actor)
{

}

bool City::findActor(std::shared_ptr<Interface::IActor> actor) const
{

}

void City::actorMoved(std::shared_ptr<Interface::IActor> actor)
{

}

std::vector<std::shared_ptr<Interface::IActor> > City::getNearbyActors(Interface::Location loc) const
{

}

bool City::isGameOver() const
{
    return false;
}
}



