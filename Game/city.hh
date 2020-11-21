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
    void setBackground(QImage& basicbackground, QImage& bigbackground);
    void addStop(std::shared_ptr<Interface::IStop> stop);
    void setClock(QTime clock);
    void startGame();
    void addActor(std::shared_ptr<Interface::IActor> newactor);
    void removeActor(std::shared_ptr<Interface::IActor> actor);
    void actorRemoved(std::shared_ptr<Interface::IActor> actor);
    bool findActor(std::shared_ptr<Interface::IActor> actor) const;
    void actorMoved(std::shared_ptr<Interface::IActor> actor);
    std::vector<std::shared_ptr<Interface::IActor>> getNearbyActors(Interface::Location loc) const;
    bool isGameOver() const;
    void gameOver();
    void selectVehicle(int num);
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
    int old_nysses_ = 0;
    QVector<std::shared_ptr<Interface::IActor>> nysses_;
    QVector<std::shared_ptr<Interface::IActor>> passengers_;
    QVector<std::shared_ptr<Interface::IStop>> stops_;
    QVector<std::shared_ptr<Interface::IActor>> players_;
    QTime time_;
    bool helicopter_ = false;
    bool fighter_ = false;
    bool spaceShip_ = false;
    bool gameOver_ = false;


};

}

#endif // CITY_HH
