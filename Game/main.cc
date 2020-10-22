#include <QApplication>

int main(int argc, char *argv[])
{
    // Kommentti
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(offlinedata);

    return a.exec();
}
