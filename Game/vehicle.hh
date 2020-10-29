#ifndef VEHICLE_HH
#define VEHICLE_HH
#include "interfaces/ivehicle.hh"

namespace StudentSide
{

class Vehicle : public Interface::IVehicle
{
public:
    Vehicle();
    ~Vehicle();

    std::string getName() const override;
    std::vector<std::shared_ptr<Interface::IPassenger> > getPassengers() const override;
    void addPassenger(std::shared_ptr<Interface::IPassenger> passenger) override;
    void removePassenger(std::shared_ptr<Interface::IPassenger> passenger) override;
};
}

#endif // VEHICLE_HH
