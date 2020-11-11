#include "player.hh"

const int MOVING_DISCANCE = 10;

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
    playerLocation_.setXY(playerLocation_.giveX(), playerLocation_.giveY() - MOVING_DISCANCE);
}

void Player::moveDown()
{
    playerLocation_.setXY(playerLocation_.giveX(), playerLocation_.giveY() + MOVING_DISCANCE);
}

void Player::moveRight()
{
    playerLocation_.setXY(playerLocation_.giveX() + MOVING_DISCANCE, playerLocation_.giveY());
}

void Player::moveLeft()
{
    playerLocation_.setXY(playerLocation_.giveX() - MOVING_DISCANCE, playerLocation_.giveY());
}

Interface::Location StudentSide::Player::giveLocation() const
{
    return playerLocation_;

}

}
