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
    dialog_ = new StudentSide::Dialog();
    mainWindow_ = new StudentSide::MainWindow();
    city_ = std::make_shared<StudentSide::City>(mainWindow_);

    connect(mainWindow_, &StudentSide::MainWindow::gameStarted, this, &StudentSide::Engine::engineGameStarted);
    connect(mainWindow_, &StudentSide::MainWindow::buttonPressed, this, &Engine::movePlayer);
    connect(mainWindow_, &StudentSide::MainWindow::gameOverSignal, this, &Engine::gameOver);
    connect(mainWindow_, &StudentSide::MainWindow::nysseDestroyedSignal, this, &Engine::nysseDestroyed);


    dialog_->show();
    connect(dialog_, &StudentSide::Dialog::helicopterSelected, this, &StudentSide::Engine::gameHelicopter);
    connect(dialog_, &StudentSide::Dialog::fighterSelected, this, &StudentSide::Engine::gameFighter);
    connect(dialog_, &StudentSide::Dialog::spaceShipSelected, this, &StudentSide::Engine::gameSpaceShip);
    dialog_->exec();

    //connect(dialog_, &StudentSide::Dialog::helicopterSelected, this, &StudentSide::Engine::gameHelicopter);
    mainWindow_->setTick(1000);
    mainWindow_->show();
    createGame();
}

Engine::~Engine()
{


}

void Engine::gameHelicopter()
{
    city_->selectVehicle(HELICOPTER_NUM);
}

void Engine::gameFighter()
{  
    city_->selectVehicle(FIGHTER_NUM);

}

void Engine::gameSpaceShip()
{
    city_->selectVehicle(SPACESHIP_NUM);
}

void Engine::gameOver()
{
    city_->gameOver();
}

void Engine::nysseDestroyed()
{
    city_->nysseDestroyed();
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

    mainWindow_->updatePlayerCoords(player1_->giveLocation().giveX(), player1_->giveLocation().giveY());
}

void Engine::engineGameStarted()
{
    std::cout << "gamestartedengine" << std::endl;
}


void Engine::createGame()
{

    QImage img_small(":/offlinedata/offlinedata/kartta_pieni_500x500.png");
    QImage img_large(":/offlinedata/offlinedata/kartta_iso_1095x592.png");

    city_->setBackground(img_small, img_large);

    logic_.fileConfig();

    logic_.takeCity(city_);

    player1_ = std::make_shared<StudentSide::Player>();
    Interface::Location loc;
    loc.setXY(PLAYER_X_COORD, PLAYER_Y_COORD);
    player1_->move(loc);
    city_->addActor(player1_);

    logic_.finalizeGameStart();
}
}

