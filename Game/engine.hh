#ifndef ENGINE_HH
#define ENGINE_HH
#include "../Course/CourseLib/core/logic.hh"

#include <QObject>

#include "city.hh"
#include "mainwindow.hh"
#include "player.hh"

#include <ostream>

namespace StudentSide
{

class Engine : public QObject
{
    Q_OBJECT

public:
    Engine();
    ~Engine();


public slots:
    void movePlayer(char button);
    void engineGameStarted();

private:
    void createGame();

    std::shared_ptr<StudentSide::Player> player1_;
    StudentSide::MainWindow* mainWindow_;
    CourseSide::Logic logic_;

};

}

#endif // ENGINE_HH
