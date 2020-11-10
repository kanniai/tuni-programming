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

class Player : public StudentSide::Actor
{
public:
    Player();
    ~Player();

    void move(Interface::Location loc) override;
    Interface::Location giveLocation() const override;
    void addPlayer();

private:
    Interface::Location playerLocation_;
    std::shared_ptr<IActor> player1;
};
}

#endif // PLAYER_HH
