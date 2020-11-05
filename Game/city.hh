#ifndef CITY_HH
#define CITY_HH
#include "interfaces/icity.hh"
#include "simplemainwindow.hh"
#include "mainwindow.hh"
#include <QTime>

namespace StudentSide
{

class City : public Interface::ICity
{
public:
    City();
    City(StudentSide::MainWindow* simpleMainWindow);
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

private:
    StudentSide::MainWindow* simpleMainWindow_;
    QVector<std::shared_ptr<Interface::IActor>> actors_;
    QVector<std::shared_ptr<Interface::IStop>> stops_;
    StudentSide::MainWindow window_;
    QTime time_;


};

}

#endif // CITY_HH
