#include "engine.hh"
#include "city.hh"
#include "simplemainwindow.hh"

const QImage *MAP_BIG2 = new QImage(":/../Course/CourseLib/offlinedata/offlinedata/kartta_iso_1095x592");
const QImage *MAP_BASIC1 = new QImage(":/../Course/CourseLib/offlinedata/offlinedata/kartta_small_500x500");
QImage MAP_BASIC(":/../Course/CourseLib/offlinedata/offlinedata/kartta_small_500x500");
QImage MAP_BIG(":/../Course/CourseLib/offlinedata/offlinedata/kartta_iso_1095x592");

namespace StudentSide
{
Engine::Engine()
{
    CourseSide::SimpleMainWindow* w = new CourseSide::SimpleMainWindow();


    StudentSide::City city(w);
    city.setBackground(MAP_BASIC, MAP_BIG);
    w->show();
}

Engine::~Engine()
{

}

}
