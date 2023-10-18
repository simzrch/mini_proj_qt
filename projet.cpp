#include "projet.h"
#include "ui_interface.h"
#include "AesGestion.h"

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
}


void sauvegarde::on_AES_stateChanged(int arg1)
{
    std::cout << "AES " << arg1 << std::endl;
    ui->SHA->setChecked(false);
    ui->RSA->setChecked(false);
}


void sauvegarde::on_SHA_stateChanged(int arg1)
{
    std::cout << "SHA " << arg1 << std::endl;
    ui->RSA->setChecked(false);
    ui->AES->setChecked(false);
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


    }


    else if(ui->RSA->isChecked() == true ){
        std::cout<<"c'est le sha qui est appuyee"<<std::endl;


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

}


void sauvegarde::on_clear_clicked()
{
    ui->string->setText("");
}

