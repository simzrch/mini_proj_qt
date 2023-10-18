#include "gestionImage.h"
#include "HashGestion.h"
#include <QApplication>
#include <fstream>
#include <iostream>
#include <filesystem>


int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    gestionImage w;
    w.show();


//     fstream outfile;


//     string filename("tmp.txt");
//     fstream file_out;

//     file_out.open(filename, std::ios_base::out);
//     if (!file_out.is_open()) {
//         cout << "failed to open " << filename << '\n';
//     } else {
//         file_out << "Some random text to write." << endl;
//         cout << "Done Writing!" << endl;
//     }




    return a.exec();


}
