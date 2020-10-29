#include "engine.hh"
#include "city.hh"
#include "../Course/CourseLib/core/logic.hh"
#include "simplemainwindow.hh"
#include <QObject>
#include <QMainWindow>

namespace StudentSide
{
Engine::Engine()
{
    CourseSide::SimpleMainWindow window_;
    CourseSide::Logic logic_;

}

Engine::~Engine()
{}


void Engine::gameStarted()
{
    logic_.fileConfig();

}
void Engine::drawMap()
{
    QImage img(":/offlinedata/offlinedata/kartta_pieni_500x500.png");

    window_.setPicture(img);
    window_.show();
}

}
