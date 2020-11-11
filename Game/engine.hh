#ifndef ENGINE_HH
#define ENGINE_HH
#include "../Course/CourseLib/core/logic.hh"
#include <QObject>

#include "city.hh"
#include "mainwindow.hh"
#include "player.hh"

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
    void createGame(StudentSide::MainWindow* window);

    std::shared_ptr<StudentSide::Player> player1_;
    StudentSide::MainWindow* window_;

};

}

#endif // ENGINE_HH
