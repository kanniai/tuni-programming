#ifndef ENGINE_HH
#define ENGINE_HH
#include "../Course/CourseLib/core/logic.hh"

#include <QObject>

#include "city.hh"
#include "mainwindow.hh"
#include "player.hh"
#include "dialog.hh"
#include "actoritem.hh"

#include <ostream>

namespace StudentSide
{

class Engine : public QObject
{
    Q_OBJECT

public:
    Engine();
    ~Engine();


public slots:
    void movePlayer(char button);
    void engineGameStarted();
    void gameHelicopter();
    void gameFighter();
    void gameSpaceShip();
    void gameOver();

private:
    void createGame();

    int HELICOPTER_NUM = 1;
    int FIGHTER_NUM = 2;
    int SPACESHIP_NUM = 3;

    std::shared_ptr<StudentSide::Player> player1_;
    StudentSide::MainWindow* mainWindow_;
    StudentSide::Dialog* dialog_;
    CourseSide::Logic logic_;
    StudentSide::ActorItem *actoritem_;


};

}

#endif // ENGINE_HH
