#include "vueAccueil.h"
#include "ui_vueAccueil.h"
#include "vueFormNom.h"
#include <iostream>
#include <vector>
using namespace std;


VueAccueil::VueAccueil(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VueAccueil)
{
    ui->setupUi(this);
    ui->spinBox->setMaximum(4);
    ui->spinBox->setMinimum(2);
    this->setWindowTitle("Bienvenue sur le Jeu Carcassonne");
}


VueAccueil::~VueAccueil()
{
    delete ui;
}


void VueAccueil::setNbrJoueur(){
    this->nbJoueur = ui->spinBox->value();
}

void VueAccueil::on_pushButton_clicked()
{
    vector<int> listNumExtension;
    /*
    1 correspond à mode de Jeu classique
    2 correspond à mode de Jeu Paysans
    3 correspond à mode de Jeu Abbe
    4 correspond à mode de Jeu Riviere
    5 correspond à mode de Jeu Auberge et cathédrales
    */
    int nbrExtension = 0;
    if (ui->checkBClassique->isChecked()){
        nbrExtension++;
        listNumExtension.push_back(1);
    }
    if (ui->checkBPaysans->isChecked()){
        nbrExtension++;
        listNumExtension.push_back(2);
    }
    if (ui->checkBAbbe->isChecked()){
        nbrExtension++;
        listNumExtension.push_back(3);
    }
    if (ui->checkBRiviere->isChecked()){
        nbrExtension++;
        listNumExtension.push_back(4);
    }
    if (ui->checkBAuberge->isChecked()){
        nbrExtension++;
        listNumExtension.push_back(5);
    }

    // Donc listNUmExtension est un vector qui contient tous les numéros des extensions choisi par l'utilisateur

    setNbrJoueur();
    int nJoueur = getNbrJoueur();
    VueFormNom* fenetreFormNom = new VueFormNom(nJoueur, listNumExtension);
    fenetreFormNom->show();
}



