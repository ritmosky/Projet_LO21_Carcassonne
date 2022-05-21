#include "vuePartie.h"
#include "ui_vuePartie.h"
#include "vueScore1Joueur.h"

VuePartie::VuePartie(QWidget *parent) :
    QMainWindow(parent),


    ui(new Ui::VuePartie)
{
    ui->setupUi(this);


    setAffichageScore();

}

VuePartie::~VuePartie()
{
    delete ui;
}


void VuePartie::setAffichageScore() {
    VueScore1Joueur* vueScore1 = new VueScore1Joueur();
    VueScore1Joueur* vueScore2 = new VueScore1Joueur();
    ui->affichageScore->addWidget(vueScore1);
    ui->affichageScore->addWidget(vueScore2);
}
