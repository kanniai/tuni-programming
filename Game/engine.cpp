#include "engine.hh"

#include <QDebug>

const int PLAYER_X_COORD = 30;
const int PLAYER_Y_COORD = 0;

const int MAP_LEFT_SIDE_XCOORD = 20;
const int MAP_UPPER_YCOORD = 20;
const int MAP_RIGHT_SIDE_XCOORD = 469;
const int MAP_LOWER_YCOORD = 469;

namespace StudentSide
{
Engine::Engine()
{
    mainWindow_ = new StudentSide::MainWindow();

    connect(mainWindow_, &StudentSide::MainWindow::gameStarted, this, &StudentSide::Engine::engineGameStarted);
    connect(mainWindow_, &StudentSide::MainWindow::buttonPressed, this, &Engine::movePlayer);
    connect(mainWindow_, &StudentSide::MainWindow::gameOver, this, &Engine::gameOver);

    mainWindow_->setTick(1000/30);
    mainWindow_->show();

    createGame();

}

Engine::~Engine()
{


}

void Engine::movePlayer(char button)
{
    if (button == 'w') {
        if (player1_->giveLocation().giveY() < MAP_UPPER_YCOORD) {
            return;
        }
        player1_->moveUp();
    } else if (button == 'd') {
        if (player1_->giveLocation().giveX() > MAP_RIGHT_SIDE_XCOORD) {
            return;
        }
        player1_->moveRight();
    } else if (button == 's') {
        if (player1_->giveLocation().giveY() > MAP_LOWER_YCOORD) {
            return;
        }
        player1_->moveDown();
    } else if (button == 'a') {
        if (player1_->giveLocation().giveX() < MAP_LEFT_SIDE_XCOORD) {
            return;
        }
        player1_->moveLeft();
    }

    mainWindow_->updateCoords(player1_->giveLocation().giveX(), player1_->giveLocation().giveY());
}

void Engine::engineGameStarted()
{
    std::cout << "gamestartedengine" << std::endl;
}

void Engine::gameOver()
{
    std:: cout << "gameover" << std::endl;
}

void Engine::createGame()
{


    std::shared_ptr<StudentSide::City> city = std::make_shared<StudentSide::City>(mainWindow_);

    QImage img_small(":/offlinedata/offlinedata/kartta_pieni_500x500.png");
    QImage img_large(":/offlinedata/offlinedata/kartta_iso_1095x592.png");

    city->setBackground(img_small, img_large);

    logic_.fileConfig();

    logic_.takeCity(city);

    player1_ = std::make_shared<StudentSide::Player>();
    Interface::Location loc;
    loc.setXY(PLAYER_X_COORD, PLAYER_Y_COORD);
    player1_->move(loc);
    city->addActor(player1_);

    logic_.finalizeGameStart();
}
}
