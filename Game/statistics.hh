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
    void nysseLeft() override;
    void morePassengers(int num) override;
    void nysseRemoved() override;


private:
    int nysses_ = 0;

};
}
#endif // STATISTICS_HH
