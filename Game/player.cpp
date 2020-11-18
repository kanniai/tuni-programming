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

void Player::moveUp()
{
    playerLocation_.setXY(playerLocation_.giveX(), playerLocation_.giveY() - MOVING_DISTANCE);
}

void Player::moveDown()
{
    playerLocation_.setXY(playerLocation_.giveX(), playerLocation_.giveY() + MOVING_DISTANCE);
}

void Player::moveRight()
{
    playerLocation_.setXY(playerLocation_.giveX() + MOVING_DISTANCE, playerLocation_.giveY());
}

void Player::moveLeft()
{
    playerLocation_.setXY(playerLocation_.giveX() - MOVING_DISTANCE, playerLocation_.giveY());
}

Interface::Location StudentSide::Player::giveLocation() const
{
    return playerLocation_;

}

}
