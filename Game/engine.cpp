#include "engine.hh"
#include "city.hh"
#include "mainwindow.hh"
#include "time.h"

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

    logic.finalizeGameStart();


}
}

