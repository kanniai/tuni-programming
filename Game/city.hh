#ifndef CITY_HH
#define CITY_HH
#include "interfaces/icity.hh"
#include "mainwindow.hh"
#include "player.hh"
#include "statistics.hh"

#include <QTime>



namespace StudentSide
{

class City : public Interface::ICity
{
public:
    City();
    City(StudentSide::MainWindow* mainWindow);
    ~City();
    /**
     * @brief Call MainWindow to print background
     */
    void setBackground(QImage& basicbackground, QImage& bigbackground);
    void addStop(std::shared_ptr<Interface::IStop> stop);

    /**
     * @brief Set time in MainWindow
     * Updates statistics about how many are buses in traffic
     */
    void setClock(QTime clock);

    /**
     * @brief Calls MainWindow to add actors on map
     */
    void startGame();

    /**
     * @brief Add actors in vectors nysses_, passengers_, stops_ or players_
     *  Add statistics information about nysses and passengers.
     */
    void addActor(std::shared_ptr<Interface::IActor> newactor);

    /**
     * @brief Removes passenger or nysse from nysses_ or passengers_
     * Update statistics about number of nysses
     */
    void removeActor(std::shared_ptr<Interface::IActor> actor);

    // empty method in our project
    void actorRemoved(std::shared_ptr<Interface::IActor> actor);

    /**
     * @brief Return true if actor is found in nysses_ or passengers_
     */
    bool findActor(std::shared_ptr<Interface::IActor> actor) const;

    /**
     * @return true if actor is found in nysses_ or passengers_
     */
    void actorMoved(std::shared_ptr<Interface::IActor> actor);

    // empty method in our project
    std::vector<std::shared_ptr<Interface::IActor>> getNearbyActors(Interface::Location loc) const;

    bool isGameOver() const;
    
    /**
     * @Brief Change gameOver_ = true
     */
    void gameOver();

    /**
     * @Brief Select vehicle for player
     * * @param 1 = helicopter, 2 = fighter, 3 = spaceship
     */
    void selectVehicle(int num);

    /**
     * @Brief remove nysse from statistics
     * @return Select vehicle for player
     * * @param 1 = helicopter, 2 = fighter, 3 = spaceship
     */
    void nysseDestroyed();

    StudentSide::MainWindow* returnMainwindow();

    int STOP = 0;
    int NYSSE = 1;
    int PASSENGER = 2;
    int HELICOPTER= 3;
    int FIGHTER = 4;
    int SPACESHIP = 5;

private:
    StudentSide::MainWindow* mainWindow_;
    StudentSide::Statistics statistics_;
    QVector<std::shared_ptr<Interface::IActor>> nysses_;
    QVector<std::shared_ptr<Interface::IActor>> passengers_;
    QVector<std::shared_ptr<Interface::IStop>> stops_;
    QVector<std::shared_ptr<Interface::IActor>> players_;
    bool helicopter_ = false;
    bool fighter_ = false;
    bool spaceShip_ = false;
    bool gameOver_ = false;

    int old_nysses_ = 0;

};
}

#endif // CITY_HH
