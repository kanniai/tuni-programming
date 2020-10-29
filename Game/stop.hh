#ifndef STOP_HH
#define STOP_HH
#include "interfaces/istop.hh"

namespace StudentSide
{
class Stop : public Interface::IStop
{
public:
    Stop();
    ~Stop();

    Interface::Location getLocation() const override;
    QString getName() const override;
    unsigned int getId() const override;
    std::vector<std::shared_ptr<Interface::IPassenger> > getPassengers() const override;
};
}
#endif // STOP_HH
