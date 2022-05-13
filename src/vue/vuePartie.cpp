#include "vuePartie.h"
#include "ui_vuePartie.h"
#include "vueScore1Joueur.h"

VuePartie::VuePartie(QWidget *parent) :
    QMainWindow(parent),


    ui(new Ui::VuePartie)
{
    ui->setupUi(this);
    // On resize la fenetre de la partie à 1280x720
    resize(1280,720);
    setAffichageScore();

}

VuePartie::~VuePartie()
{
    delete ui;
}


void VuePartie::setAffichageScore() {
    VueScore1Joueur* vueScore = new VueScore1Joueur();
    ui->affichageScore->addWidget(vueScore);

}
