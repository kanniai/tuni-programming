#include "simplemainwindow.hh"
#include "city.hh"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(offlinedata);
    CourseSide::SimpleMainWindow w;
    w.show();

    StudentSide::City city(w);


    return a.exec();
}
