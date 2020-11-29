#include "engine.hh"

#include <QDebug>

namespace StudentSide
{
Engine::Engine()
{
    dialog_ = new StudentSide::Dialog();
    mainWindow_ = new StudentSide::MainWindow();
    city_ = std::make_shared<StudentSide::City>(mainWindow_);

    connect(mainWindow_, &StudentSide::MainWindow::buttonPressed,
            this, &Engine::movePlayer);
    connect(mainWindow_, &StudentSide::MainWindow::gameOverSignal,
            this, &Engine::gameOver);
    connect(mainWindow_, &StudentSide::MainWindow::nysseDestroyedSignal,
            this, &Engine::nysseDestroyed);

    dialog_->show();
    connect(dialog_, &StudentSide::Dialog::helicopterSelected,
            this, &StudentSide::Engine::gameHelicopter);
    connect(dialog_, &StudentSide::Dialog::fighterSelected,
            this, &StudentSide::Engine::gameFighter);
    connect(dialog_, &StudentSide::Dialog::spaceShipSelected,
            this, &StudentSide::Engine::gameSpaceShip);

    connect(dialog_, &StudentSide::Dialog::player1Name,
            this, &StudentSide::Engine::setName1);
    connect(dialog_, &StudentSide::Dialog::player2Name,
            this, &StudentSide::Engine::setName2);

    dialog_->exec();

    mainWindow_->show();

    createGame();
}

Engine::~Engine()
{}

void Engine::gameHelicopter()
{
    city_->selectVehicle(HELICOPTER_NUM);
    helicopter_ = true;
    mainWindow_->setTickAndStartTimer(1000);
}

void Engine::gameFighter()
{  
    city_->selectVehicle(FIGHTER_NUM);
    fighter_ = true;
    mainWindow_->setTickAndStartTimer(1000);
}

void Engine::gameSpaceShip()
{
    city_->selectVehicle(SPACESHIP_NUM);
    spaceShip_ = true;
    mainWindow_->setTickAndStartTimer(1000);
}

void Engine::gameOver()
{
    //delete mainWindow_;
    mainWindow_->hide();
    city_->gameOver();
}

void Engine::nysseDestroyed()
{
    city_->nysseDestroyed();
}

void Engine::setName1(QString name)
{
    name1_ = name;
}

void Engine::setName2(QString name)
{
    name2_ = name;
}

void Engine::updateNames()
{
    mainWindow_->setName1(name1_);
    mainWindow_->setName2(name2_);
}

void Engine::movePlayer(char button)
{
    if (helicopter_) {
        player1_->determineSpeed(HELICOPTER_NUM);
    } else if (fighter_) {
        player1_->determineSpeed(FIGHTER_NUM);
    } else if (spaceShip_) {
        player1_->determineSpeed(SPACESHIP_NUM);
    }

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

    mainWindow_->updatePlayerCoords(player1_->giveLocation().giveX(),
                                    player1_->giveLocation().giveY());
}

void Engine::createGame()
{

    QImage img_small(":/offlinedata/offlinedata/kartta_pieni_500x500.png");
    QImage img_large(":/offlinedata/offlinedata/kartta_iso_1095x592.png");

    city_->setBackground(img_small, img_large);

    logic_.fileConfig();

    logic_.takeCity(city_);

    player1_ = std::make_shared<StudentSide::Player>();
    player2_ = std::make_shared<StudentSide::Player>();

    Interface::Location loc;
    loc.setXY(PLAYER_X_COORD, PLAYER_Y_COORD);
    player1_->move(loc);

    Interface::Location loc2;
    loc2.setXY(PLAYER2_X_COORD, PLAYER2_Y_COORD);
    player2_->move(loc2);

    city_->addActor(player1_);
    city_->addActor(player2_);

    logic_.finalizeGameStart();
    updateNames();
}
}

