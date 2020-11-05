#include "engine.hh"
#include "city.hh"

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

    CourseSide::SimpleMainWindow* window = new CourseSide::SimpleMainWindow;
    CourseSide::Logic logic;

    std::shared_ptr<StudentSide::City> city = std::make_shared<StudentSide::City>(window);

    QImage img_small(":/offlinedata/offlinedata/kartta_pieni_500x500.png");
    QImage img_large(":/offlinedata/offlinedata/kartta_iso_1095x592.png");

    city->setBackground(img_small, img_large);
    window->show();

    window->addActor(150, 150, 0);

    logic.fileConfig();

    logic.takeCity(city);

    logic.finalizeGameStart();

}
}

