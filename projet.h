#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H

#include <QMainWindow>
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <iostream>
#include <QFileDialog>
#include <cstdlib>
#include <QApplication>


QT_BEGIN_NAMESPACE
namespace Ui { class sauvegarde; }
QT_END_NAMESPACE

class sauvegarde : public QMainWindow
{
    Q_OBJECT

public:
    sauvegarde(QWidget *parent = nullptr);
    ~sauvegarde();
    int compteur;

private slots:
    void on_RSA_stateChanged(int arg1);

    void on_AES_stateChanged(int arg1);

    void on_SHA_stateChanged(int arg1);

    void on_parcourir_clicked();

    void on_string_cursorPositionChanged(int arg1, int arg2);


    void on_chiffre_clicked();

    void on_dechiffre_clicked();

    void on_clear_clicked();

private:
    Ui::sauvegarde *ui;
};
#endif // SAUVEGARDE_H
