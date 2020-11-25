#include "CharacterCreator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CharacterCreator w;
    w.show();
    return a.exec();
}
