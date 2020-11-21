#ifndef PLAYER_HH
#define PLAYER_HH
#include "core/location.hh"
#include "interfaces/icity.hh"
#include "actor.hh"
#include "city.hh"


#include <QTime>
#include <memory>
#include <set>
#include <map>
#include <vector>

namespace StudentSide
{

const int MOVING_DISTANCE = 10;

/**
 * @brief The Player class is used to locate the player in the game grid
 * The class keeps track on the player location and moves it when requested.
 * Class is inherited from Actor-class
 */
class Player : public StudentSide::Actor
{
public:
    /**
     * @brief Default constructor
     */
    Player();
    ~Player();

    /**
     * @brief move sets the player to desired location
     * @param loc: input location of player
     */
    void move(Interface::Location loc) override;

    // Methods move the player to desired direction by constant value
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();

    /**
     * @brief giveLocation
     * @return location of the player
     */
    Interface::Location giveLocation() const override;

private:
    Interface::Location playerLocation_;
    std::shared_ptr<IActor> player1;
};
}

#endif // PLAYER_HH
