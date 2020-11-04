#ifndef ENGINE_HH
#define ENGINE_HH
#include "../Course/CourseLib/core/logic.hh"
#include <QObject>
#include <QMainWindow>
#include "city.hh"
#include "simplemainwindow.hh"

namespace StudentSide
{

class Engine
{
public:
    Engine();
    ~Engine();

public slots:

private:
    std::shared_ptr<Interface::ICity> createGame();

};

}

#endif // ENGINE_HH
