#include <QtGui/QApplication>
#include "students.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::addLibraryPath( "/data/data/org.kde.necessitas.ministro/files/qt/plugins/" );
    students w;
    w.show();

    return a.exec();
}
