#ifndef STATISTICS_HH
#define STATISTICS_HH
#include "interfaces/istatistics.hh"
#include "mainwindow.hh"

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

    int returnNysses();



private:
    int nysses_ = 0;
    StudentSide::MainWindow* mainWindow_;

};
}
#endif // STATISTICS_HH
