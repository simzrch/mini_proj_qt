#include "gestionImage.h"
#include "ui_gestionImage.h"
#include "QFile"
#include "QDir"
#include "HashGestion.h"
#include "RsaGestion.h"
#include "AesGestion.h"
#include <filesystem>
using namespace std ;

gestionImage::gestionImage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::gestionImage)
{

    ui->setupUi(this);
    ui->lblImage->hide();
    ui->lblImage2->hide();
    this->compteur = 0;
    this->compteure = 0;
    this->barreEdit = 0;
    this->compB = 0 ;
    this->barreEdite = 0;
    this->comptB = 0 ;
    this->fichier = 0;
    this->NomFichier = 0;
}

gestionImage::~gestionImage()
{
    delete ui;
}



void gestionImage::on_btnShow_clicked()
{
    this->compteure = compteure +1;
    ui->btnShow->setStyleSheet("background-color: red;");
    if(compteure%2 == 1 )
    {
        ui->lblImage->show();
    }
    else
    {
        ui->lblImage->hide();
    }
}


void gestionImage::on_pushButton_2_clicked()
{
    this->compteur = compteur +1;
    ui->pushButton_2->setStyleSheet("background-color: yellow;");
    if(compteur%2 == 1 )
    {
        ui->lblImage2->show();
    }
    else
    {
        ui->lblImage2->hide();
    }
}


void gestionImage::on_hide_clicked()
{
    ui->lblImage->hide();
    ui->lblImage2->hide();
    ui->hide->setStyleSheet("background-color: green;");
}


void gestionImage::on_pushButton_clicked()
{
    this->barreEdit = this->barreEdit -2 ;
    //this->compB = this->compB -2;
    if(barreEdit%2 == 1 )
    {
        //ui->progressBar->setValue(compB);
        ui->progressBar->setValue(barreEdit);
    }
    else
    {
        ui->progressBar->setValue(barreEdit);
    }

}



void gestionImage::on_pushButton_3_clicked()
{
    this->barreEdite = barreEdite +1 ;
    //this->comptB = this->comptB +2;
    if(barreEdite%2 == 1 )
    {
    //ui->progressBar->setValue(comptB);
    ui->progressBar->setValue(barreEdite);
    }
    else
    {

    ui->progressBar->setValue(barreEdite);
    }
}



void gestionImage::on_pushButton_4_clicked()
{
    //bool valid  = QFile::copy ("./proj/test/rep_non_secu/p.txt", "./proj/test/rep_secu/p2.txt>> NomFichier");
    //QDir().rename("./proj/test/rep_secu/p2.txt", "./proj/test/rep_secu/fichierTest.txt");
}


void gestionImage::on_RSAchiff_clicked()
{
    RsaGestion clef = RsaGestion();

    if(std::filesystem::exists("../mesClefs/celfPub.pem, ../mesClefs/celfPrive.pem ") == 0){
    std::cout << "Creation des nouvelles clefs"<< std::endl;
    clef.generationClef("../mesClefs/celfPub.pem","../mesClefs/celfPrive.pem",1024);
    clef.chargementClefs("../mesClefs/celfPub.pem", "../mesClefs/celfPrive.pem");
    clef.chiffrementFichier("../nonChiffre/p.txt", "../Chiffre/p_chiffre.txt",true);
    }
    else
    {

    }
    std::cout << "Chargement des anciennes clefs"<< std::endl;
    clef.chargementClefs("../mesClefs/celfPub.pem", "../mesClefs/celfPrive.pem");
    clef.chiffrementFichier("../nonChiffre/p.txt", "../Chiffre/p_chiffre.txt",true);

}

void gestionImage::on_SHA_clicked()
{
    HashGestion integrit ;
    std::cout<<"le Hachage du fichier est: " << integrit.CalculateSHA256("../mesClefs/Abeille_secrete")<< std::endl;
}

void gestionImage::on_AES_clicked()
{
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


void gestionImage::on_cin_2_editingFinished()
{

}


void gestionImage::on_pushButton_5_clicked()
{

   // QString fichier = "./proj/test/rep_non_secu/p.txt";


    ui->label->setText( ui->cin_2->text());



}









