#ifndef PASSENGER_HH
#define PASSENGER_HH
#include "interfaces/ipassenger.hh"
#include "interfaces/ivehicle.hh"

namespace StudentSide
{

class Passenger : public Interface::IPassenger
{
public:
    Passenger();
    ~Passenger();

    bool isInVehicle() const override;
    std::shared_ptr<Interface::IVehicle> getVehicle() const override;

};
}

#endif // PASSENGER_HH
