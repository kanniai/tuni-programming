#ifndef ENGINE_HH
#define ENGINE_HH
#include "../Course/CourseLib/core/logic.hh"

#include <QObject>

#include "city.hh"
#include "mainwindow.hh"
#include "player.hh"
#include "dialog.hh"
#include "actoritem.hh"
#include "bullet.hh"

#include <ostream>

namespace StudentSide
{
const int PLAYER_X_COORD = 0;
const int PLAYER_Y_COORD = 0;
const int PLAYER2_X_COORD = 240;
const int PLAYER2_Y_COORD = 300;

const int MAP_LEFT_SIDE_XCOORD = 8;
const int MAP_UPPER_YCOORD = 8;
const int MAP_RIGHT_SIDE_XCOORD = 480;
const int MAP_LOWER_YCOORD = 480;

const int HELICOPTER_NUM = 1;
const int FIGHTER_NUM = 2;
const int SPACESHIP_NUM = 3;

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
    void nysseDestroyed();

    void setName1(QString name);
    void setName2(QString name);

    void updateLeaderboard();


private:
    /**
     * @brief createGame calls the necessary functions to start the game
     */
    void createGame();

    std::shared_ptr<StudentSide::Player> player1_;
    std::shared_ptr<StudentSide::Player> player2_;
    StudentSide::MainWindow* mainWindow_;
    StudentSide::Dialog* dialog_;
    CourseSide::Logic logic_;
    std::shared_ptr<StudentSide::City> city_;


    bool helicopter_ = false;
    bool fighter_ = false;
    bool spaceShip_ = false;

    QString name1_;
    QString name2_;

};

}

#endif // ENGINE_HH
