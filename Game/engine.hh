#ifndef ENGINE_HH
#define ENGINE_HH
#include "../Course/CourseLib/core/logic.hh"
#include <QObject>
#include <QMainWindow>
#include "city.hh"
#include "mainwindow.hh"
#include "player.hh"

namespace StudentSide
{

class Engine
{
public:
    Engine();
    ~Engine();

public slots:

private:
    void createGame();

};

}

#endif // ENGINE_HH
