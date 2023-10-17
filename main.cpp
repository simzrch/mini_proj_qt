#include "gestionImage.h"
#include "HashGestion.h"
#include <QApplication>

#include <iostream>
#include <filesystem>


int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    gestionImage w;
    w.show();
    std::string test ="dsds";

    HashGestion integrite ;
    std::cout<< integrite.CalculateSHA256("test sha")<< std::endl;








    return a.exec();


}
