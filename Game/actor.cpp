#include "actor.hh"


namespace StudentSide
{
Actor::Actor()
{}

StudentSide::Actor::~Actor()
{}

Interface::Location StudentSide::Actor::giveLocation() const
{
    return location_;
}

void StudentSide::Actor::move(Interface::Location loc)
{
    location_ = loc;
}

bool StudentSide::Actor::isRemoved() const
{
    return isRemoved_;
}

void StudentSide::Actor::remove()
{
    isRemoved_ = true;
}
}
