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
    playerLocation_.setXY(playerLocation_.giveX(), playerLocation_.giveY() - speed_);
}

void Player::moveDown()
{
    playerLocation_.setXY(playerLocation_.giveX(), playerLocation_.giveY() + speed_);
}

void Player::moveRight()
{
    playerLocation_.setXY(playerLocation_.giveX() + speed_, playerLocation_.giveY());
}

void Player::moveLeft()
{
    playerLocation_.setXY(playerLocation_.giveX() - speed_, playerLocation_.giveY());
}

void Player::determineSpeed(int num)
{
    if (num == 1) {
        speed_ = HELICOPTER_SPEED;
    } else if (num == 2) {
        speed_ = FIGHTER_SPEED;
    } else if (num == 3) {
        speed_ = SPACESHIP_SPEED;
    }
}

Interface::Location StudentSide::Player::giveLocation() const
{
    return playerLocation_;

}

}
