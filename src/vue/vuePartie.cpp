#include "vuePartie.h"
#include "ui_vuePartie.h"
#include "vueScore1Joueur.h"

VuePartie::VuePartie(Tuile& tuile, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VuePartie),
    tuilePlace(tuile)
{
    ui->setupUi(this);


    setAffichageScore();
    setAffichageTuile(tuilePlace);

}

VuePartie::~VuePartie()
{
    delete ui;
}


void VuePartie::setAffichageScore() {
    VueScore1Joueur* vueScore1 = new VueScore1Joueur();
    VueScore1Joueur* vueScore2 = new VueScore1Joueur();
    VueScore1Joueur* vueScore3 = new VueScore1Joueur();
    VueScore1Joueur* vueScore4 = new VueScore1Joueur();
    ui->affichageScore->addWidget(vueScore1);
    ui->affichageScore->addWidget(vueScore2);
    ui->affichageScore->addWidget(vueScore3);
    ui->affichageScore->addWidget(vueScore4);
}


void VuePartie::setAffichageTuile(Tuile& tuilePlace){
    VueTuile* vueTuilePlace = new VueTuile(tuilePlace);
    ui->espaceTuilePlace->addWidget(vueTuilePlace);
}
