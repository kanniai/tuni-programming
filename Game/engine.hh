#ifndef ENGINE_HH
#define ENGINE_HH
#include "../Course/CourseLib/core/logic.hh"
#include <QObject>
#include <QMainWindow>
#include "simplemainwindow.hh"

namespace StudentSide
{

class Engine : public QMainWindow
{
public:
    Engine();
    ~Engine();


public slots:
    void gameStarted();
    void drawMap();

private:
    CourseSide::Logic logic_;
    CourseSide::SimpleMainWindow window_;
};

}

#endif // ENGINE_HH
