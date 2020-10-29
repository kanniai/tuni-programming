#include "vehicle.hh"
#include <string>

namespace StudentSide
{

Vehicle::Vehicle()
{}

StudentSide::Vehicle::~Vehicle()
{}

std::string StudentSide::Vehicle::getName() const
{

}

std::vector<std::shared_ptr<Interface::IPassenger> > StudentSide::Vehicle::getPassengers() const
{

}

void StudentSide::Vehicle::addPassenger(std::shared_ptr<Interface::IPassenger> passenger)
{

}

void StudentSide::Vehicle::removePassenger(std::shared_ptr<Interface::IPassenger> passenger)
{

}
}
