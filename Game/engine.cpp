#include "engine.hh"
#include "city.hh"

namespace StudentSide
{
Engine::Engine()
{

    CourseSide::SimpleMainWindow* window = new CourseSide::SimpleMainWindow;
    CourseSide::Logic logic;
    City city(window);

    QImage img_small(":/offlinedata/offlinedata/kartta_pieni_500x500.png");
    QImage img_large(":/offlinedata/offlinedata/kartta_iso_1095x592.png");

    city.setBackground(img_small, img_large);
    //window->setPicture(img_large);
    window->show();

    window->addActor(150, 150, 0);

    logic.fileConfig();
    logic.finalizeGameStart();


}

Engine::~Engine()
{}
}

