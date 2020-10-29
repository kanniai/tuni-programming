#ifndef STATISTICS_HH
#define STATISTICS_HH
#include "interfaces/istatistics.hh"

namespace StudentSide
{
class Statistics : public Interface::IStatistics
{
public:
    Statistics();
    ~Statistics();

    void newNysse() override;
    void nysseDestroyed() override;
    void nysseLeft() override;
    void passengerDied(int num) override;
    void morePassengers(int num) override;
    int givePoints() const override;
};
}
#endif // STATISTICS_HH
