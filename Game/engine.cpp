#include "engine.hh"
#include "city.hh"

namespace StudentSide
{
Engine::Engine()
{
    std::shared_ptr<Interface::ICity> city = createGame();

    CourseSide::Logic logic;
    logic.fileConfig();

    logic.takeCity(city);
    unsigned short hr = 12;
    unsigned short min = 30;
    logic.setTime(hr, min);
    //logic.addNewPassengers()
    logic.finalizeGameStart();

    // logic tarvii
    //std::shared_ptr<Interface::ICity> city
    // kutua add new passengers

}

Engine::~Engine()
{}

std::shared_ptr<Interface::ICity> Engine::createGame()
{

    CourseSide::SimpleMainWindow* window = new CourseSide::SimpleMainWindow;


    StudentSide::City city(window);

    QImage img_small(":/offlinedata/offlinedata/kartta_pieni_500x500.png");
    QImage img_large(":/offlinedata/offlinedata/kartta_iso_1095x592.png");

    city.setBackground(img_small, img_large);
    window->show();

    window->addActor(150, 150, 0);

    return std::shared_ptr<Interface::ICity> (&city);

}
}

