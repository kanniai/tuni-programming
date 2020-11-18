#include "engine.hh"

#include <QDebug>

int PLAYER_X_COORD = 30;
int PLAYER_Y_COORD = 0;


namespace StudentSide
{
Engine::Engine()
{
    window_ = new StudentSide::MainWindow();

    connect(window_, &StudentSide::MainWindow::gameStarted, this, &StudentSide::Engine::engineGameStarted);
    connect(window_, &StudentSide::MainWindow::buttonPressed, this, &Engine::movePlayer);

    window_->show();
    window_->setTick(1000/30);
    createGame();

}

Engine::~Engine()
{


}

void Engine::movePlayer(char button)
{
    if (button == 'w') {
        player1_->moveUp();
    } else if (button == 'd') {
        player1_->moveRight();
    } else if (button == 's') {
        player1_->moveDown();
    } else if (button == 'a') {
        player1_->moveLeft();
    }

    window_->updateCoords(player1_->giveLocation().giveX(), player1_->giveLocation().giveY());
}

void Engine::engineGameStarted()
{
    std::cout << "gamestartedengine" << std::endl;
}

void Engine::createGame()
{


    std::shared_ptr<StudentSide::City> city = std::make_shared<StudentSide::City>(window_);

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

