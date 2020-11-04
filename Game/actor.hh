#ifndef ACTOR_HH
#define ACTOR_HH
#include "interfaces/iactor.hh"
#include "graphics/simplemainwindow.hh"
#include <QTime>
#include "core/location.hh"

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

};
}

#endif // ACTOR_HH
