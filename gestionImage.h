#ifndef GESTIONIMAGE_H
#define GESTIONIMAGE_H

#include <QMainWindow>
#include <iostream>
#include <Qstring>

QT_BEGIN_NAMESPACE
namespace Ui { class gestionImage; }
QT_END_NAMESPACE

class gestionImage : public QMainWindow
{
    Q_OBJECT

public:
    gestionImage(QWidget *parent = nullptr);
    ~gestionImage();

private slots:




    void on_btnShow_clicked();

    void on_pushButton_2_clicked();



    void on_hide_clicked();







    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_SHA_clicked();

    void on_pushButton_5_clicked();

    void on_cin_2_editingFinished();

    void on_RSAchiff_clicked();

    void on_AES_clicked();

    void on_AESdechiff_clicked();

    void on_RSAdechiff_clicked();

private:
    Ui::gestionImage *ui;
    int compteur = 0;
    int compteure = 0;
    int barreEdit = 0;
    int compB = 0 ;
    int barreEdite = 0;
    int comptB = 0 ;
    bool fichier = 0;
    char NomFichier = 0;
};
#endif // GESTIONIMAGE_H
