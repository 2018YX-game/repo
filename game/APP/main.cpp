#include "../WINDOW/startpage.h"
#include <QApplication>

int main(int argc, char *argv[])//this is submitted by productor
{
    QApplication a(argc, argv);
    startpage w;
    w.show();

    return a.exec();
}
