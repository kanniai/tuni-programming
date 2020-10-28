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
    Q_OBJECT
public:
    Engine();
    ~Engine();


public slots:
    void gameStarted();

private:
    CourseSide::Logic logic_;
    CourseSide::SimpleMainWindow* window_;
};

}

#endif // ENGINE_HH
