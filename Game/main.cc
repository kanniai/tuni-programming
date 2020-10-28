#include "simplemainwindow.hh"
#include "city.hh"

#include <QApplication>

int main(int argc, char *argv[])
{
    QImage MAP_BIG = QImage(":/../Course/CourseLib/offlinedata/offlinedata/kartta_iso_1095x592");
    const QImage *MAP_BASIC = new QImage(":/../Course/CourseLib/offlinedata/offlinedata/kartta_small_500x500");

    QApplication a(argc, argv);
    Q_INIT_RESOURCE(offlinedata);
    CourseSide::SimpleMainWindow w;
    w.setPicture(MAP_BIG);
    w.show();


    return a.exec();
}
