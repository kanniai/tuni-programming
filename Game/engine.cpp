#include "engine.hh"

int PLAYER_X_COORD = 30;
int PLAYER_Y_COORD = 0;


namespace StudentSide
{
Engine::Engine()
{
    createGame();

}

Engine::~Engine()
{}

void Engine::createGame()
{

    StudentSide::MainWindow* window = new StudentSide::MainWindow();
    CourseSide::Logic logic;

    std::shared_ptr<StudentSide::City> city = std::make_shared<StudentSide::City>(window);

    QImage img_small(":/offlinedata/offlinedata/kartta_pieni_500x500.png");
    QImage img_large(":/offlinedata/offlinedata/kartta_iso_1095x592.png");

    city->setBackground(img_small, img_large);
    window->show();

    logic.fileConfig();

    logic.takeCity(city);

    std::shared_ptr<StudentSide::Player> player1 = std::make_shared<StudentSide::Player>();
    Interface::Location loc;
    loc.setXY(PLAYER_X_COORD, PLAYER_Y_COORD);
    player1->move(loc);
    city->addActor(player1);

    logic.finalizeGameStart();


}
}

