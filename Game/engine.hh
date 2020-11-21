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

/**
 * @brief The Engine class starts the game and sets up main window and dialog.
 * Emits the necessary signals for other classes from
 */
class Engine : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Default constructor
     */
    Engine();
    ~Engine();


public slots:

    /**
     * @brief movePlayer tracks which direction player is to be moved
     * @param button (w,a,s,d)
     */
    void movePlayer(char button);

    /**
     * @brief gameHelicopter: player selects helicopter as vehicle
     */
    void gameHelicopter();

    /**
     * @brief gameFighter: player selects fighter as vehicle
     */
    void gameFighter();

    /**
     * @brief gameSpaceShip: player selects spaceship as vehicle
     */
    void gameSpaceShip();

    void engineGameStarted();
    void gameOver();

private:
    /**
     * @brief createGame calls the necessary functions to start the game
     */
    void createGame();

    int HELICOPTER_NUM = 1;
    int FIGHTER_NUM = 2;
    int SPACESHIP_NUM = 3;

    std::shared_ptr<StudentSide::Player> player1_;
    StudentSide::MainWindow* mainWindow_;
    StudentSide::Dialog* dialog_;
    CourseSide::Logic logic_;
    StudentSide::ActorItem *actoritem_;
    std::shared_ptr<StudentSide::City> city_;

};

}

#endif // ENGINE_HH
