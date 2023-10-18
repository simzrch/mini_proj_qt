#include "projet.h"
#include "ui_interface.h"
#include "AesGestion.h"
#include "RsaGestion.h"
#include "HashGestion.h"
using namespace std ;
sauvegarde::sauvegarde(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::sauvegarde)
{
    ui->setupUi(this);
}

sauvegarde::~sauvegarde()
{
    delete ui;
}


void sauvegarde::on_RSA_stateChanged(int arg1)
{
    std::cout << "RSA " << arg1 << std::endl;
    ui->SHA->setChecked(false);
    ui->AES->setChecked(false);
    ui->dechiffre->show();
}


void sauvegarde::on_AES_stateChanged(int arg1)
{
    std::cout << "AES " << arg1 << std::endl;
    ui->SHA->setChecked(false);
    ui->RSA->setChecked(false);
    ui->dechiffre->show();
}


void sauvegarde::on_SHA_stateChanged(int arg1)
{
    string i =  ui->string->text();
    std::cout << i << arg1 << std::endl;
    ui->RSA->setChecked(false);
    ui->AES->setChecked(false);
    ui->dechiffre->hide();

}


void sauvegarde::on_parcourir_clicked()
{

    // Afficher la boîte de dialogue de sélection de fichier
    QString filePath = QFileDialog::getOpenFileName(nullptr, "Sélectionnez un fichier", "", "Tous les fichiers (*.*)");

    if (!filePath.isEmpty()) {
        // Utilisez filePath comme le chemin du fichier sélectionné
             qDebug() << "Chemin du fichier sélectionné : " << filePath;
            ui->string->setText(filePath);
             }

    else
    {
        qDebug() << "Aucun fichier sélectionné.";
                  }

}


void sauvegarde::on_string_cursorPositionChanged(int arg1, int arg2)
{
    QString text = ui->string->text();


}


void sauvegarde::on_chiffre_clicked()
{
    if(ui->SHA->isChecked() == true ){
        std::cout<<"c'est le sha qui est appuyee"<<std::endl;


        string const nomFichier("../SHA/Hachage_fichier.txt");
        ofstream monFlux(nomFichier.c_str());

        if(monFlux)
        {
            HashGestion integrite ;
            monFlux << "Bonjour voici e hachage du fichier demande: " << endl;
            monFlux << "SHA : " <<integrite.CalculateFileSHA256(ui->string->text()) << endl;
        }
        else
        {
            cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
        }



    }


    else if(ui->RSA->isChecked() == true ){
        std::cout<<"c'est le sha qui est appuyee"<<std::endl;


        RsaGestion clef = RsaGestion();

        if(std::filesystem::exists("../mesClefs/celfPub.pem") == 0  && std::filesystem::exists("../mesClefs/celfPrive.pem ") == 0 )
        {
            std::cout << "Creation des nouvelles clefs"<< std::endl;
            clef.generationClef("../mesClefs/celfPub.pem","../mesClefs/celfPrive.pem",1024);
            clef.chargementClefs("../mesClefs/celfPub.pem", "../mesClefs/celfPrive.pem");
            clef.chiffrementFichier("../nonChiffre/p.txt", "../Chiffre/p_chiffre.txt",true);
        }
        else
        {
            std::cout << "Chargement des anciennes clefs"<< std::endl;
            clef.chargementClefs("../mesClefs/celfPub.pem", "../mesClefs/celfPrive.pem");
            clef.chiffrementFichier("../nonChiffre/p.txt", "../Chiffre/p_chiffre.txt",true);
        }




    }


    else if(ui->AES->isChecked() == true ){
        std::cout<<"c'est le sha qui est appuyee"<<std::endl;



        AesGestion clef_secrete ;
        if(std::filesystem::exists("../mesClefs/Abeille_secrete") == 0)
        {
            std::cout << "Creation d'une nouvelle clef"<< std::endl;
            clef_secrete.GenerateAESKey();
            clef_secrete.SaveAESKeyToFile("../mesClefs/Abeille_secrete");
            clef_secrete.LoadAESKeyFromFile("../mesClefs/Abeille_secrete");
            clef_secrete.EncryptFileAES256("../nonChiffre/pA.txt", "../chiffre/pA_crypte.txt");
        }
        else
        {
            std::cout << "Chargement de l'ancienne clef"<< std::endl;
            clef_secrete.LoadAESKeyFromFile("../mesClefs/Abeille_secrete");
            clef_secrete.EncryptFileAES256("../nonChiffre/pA.txt", "../chiffre/pA_crypte.txt");
        }


    }

}



void sauvegarde::on_dechiffre_clicked()
{
    if(ui->AES->isChecked()){


        AesGestion clef_secrete ;
        if(std::filesystem::exists("../mesClefs/Abeille_secrete") == 0)
        {
            std::cout << "Creation d'une nouvelle clef"<< std::endl;
            clef_secrete.GenerateAESKey();
            clef_secrete.SaveAESKeyToFile("../mesClefs/Abeille_secrete");
            clef_secrete.LoadAESKeyFromFile("../mesClefs/Abeille_secrete");
            clef_secrete.DecryptFileAES256("../chiffre/pA_crypte.txt", "../chiffre/pA_decrypte.txt");
        }
        else
        {
            std::cout << "Chargement de l'ancienne clef"<< std::endl;
            clef_secrete.LoadAESKeyFromFile("../mesClefs/Abeille_secrete");
            clef_secrete.DecryptFileAES256("../chiffre/pA_crypte.txt", "../chiffre/pA_decrypte.txt");
        }


    }
    if(ui->RSA->isChecked()){
        RsaGestion clef = RsaGestion();

        if(std::filesystem::exists("../mesClefs/celfPub.pem") == 0  && std::filesystem::exists("../mesClefs/celfPrive.pem ") == 0 )
        {
            std::cout << " erreur les clefs n'existe pas "<< std::endl;

        }
        else
        {
            std::cout << "Chargement des clefs"<< std::endl;
            clef.chargementClefs("../mesClefs/celfPub.pem", "../mesClefs/celfPrive.pem");
            clef.dechiffrementFichier("../Chiffre/p_chiffre.txt","../Chiffre/p_dechiffre.txt", true);
        }

    }
    if(ui->SHA->isChecked()){

    }
}


void sauvegarde::on_clear_clicked()
{
    ui->string->setText("");
}




