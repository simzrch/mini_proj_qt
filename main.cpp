#include "inter_chiff.h"

#include <QApplication>
#include "projet.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    sauvegarde w;
    w.show();
    return a.exec();
}
