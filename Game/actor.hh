/**
  * Ohjelmointi 3 projekti - The Last of Bus II
  * Syksy 2020, vastuuopettaja Terhi Kilamo
  *
  * olli.luukkonen@tuni.fi
  * matias.kanniainen@tuni.fi
  */


#ifndef ACTOR_HH
#define ACTOR_HH
#include "interfaces/iactor.hh"
#include <QTime>
#include "core/location.hh"

/**
  * @brief Base class for class Player
  */

namespace StudentSide
{

class Actor : public Interface::IActor
{
public:
    Actor();
    ~Actor();

    Interface::Location giveLocation() const override;
    void move(Interface::Location loc) override;
    bool isRemoved() const override;
    void remove() override;

private:
    Interface::Location location_;
    bool isRemoved_ = false;

};
}

#endif // ACTOR_HH
