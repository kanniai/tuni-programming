#include "player.hh"

namespace StudentSide
{

Player::Player()
{

}

StudentSide::Player::~Player()
{}

void StudentSide::Player::move(Interface::Location loc)
{
    playerLocation_ = loc;
}

Interface::Location StudentSide::Player::giveLocation() const
{
    return playerLocation_;

}

<<<<<<< HEAD
void Player::addPlayer()
{

    // passengers_.push_back(newPassenger);
}
=======
>>>>>>> 25aa94cdc16619dd3edf8810b688ee96eca00267

}
