#include "Qt_do_it.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qt_do_it w;
    w.show();
    return a.exec();
}
