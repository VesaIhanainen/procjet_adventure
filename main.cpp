#include "procjetadventure.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ProcjetAdventure w;
    w.show();
    return a.exec();
}
