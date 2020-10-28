#include "engine.hh"
#include "city.hh"

#include "simplemainwindow.hh"
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(offlinedata);

    StudentSide::Engine();

    return a.exec();
}
