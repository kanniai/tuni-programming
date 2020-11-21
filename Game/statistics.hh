#ifndef STATISTICS_HH
#define STATISTICS_HH
#include "interfaces/istatistics.hh"
#include "mainwindow.hh"
#include <cassert>

namespace StudentSide
{

/**
 * @brief The Statistics class is a class which provides information
 * of the numbers of statistics ingame. Class deals with counting the buses
 * in traffic. Class is inherited from Interface::IStatistics
 */
class Statistics : public Interface::IStatistics
{
public:
    /**
     * @brief Default constructor and destructor
     */
    Statistics();
    ~Statistics();

    /**
     * @brief newNysse
     * Add new Nysse to statistics
     */
    void newNysse() override;

    /**
     * @brief nysseLeft
     * Removes nysse from the statistics when Nysse arrives to final stop
     */
    void nysseLeft() override;

    /**
     * @brief morePassengers adds new passengers to statistics
     * @param num: number of passengers
     */
    void morePassengers(int num) override;

    /**
     * @brief nysseRemoved
     * Removes Nysse from game if destroyed by player
     */
    void nysseRemoved() override;

    /**
     * @brief returnNysses
     * @return number of Nysses in traffic
     */
    int returnNysses();

    /**
     * @brief returnPassengers
     * @return number of passengers ingame
     */
    int returnPassengers();



private:
    // Statistics for Nysses or passengers
    int nysses_ = 0;
    int passengers_ = 0;
    StudentSide::MainWindow* mainWindow_;

};
}
#endif // STATISTICS_HH
