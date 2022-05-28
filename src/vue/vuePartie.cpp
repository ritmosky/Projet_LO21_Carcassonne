#include "vuePartie.h"
#include "ui_vuePartie.h"
#include "vueScore1Joueur.h"
#include <QString>
#include <iostream>

VuePartie::VuePartie(Controller* c, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VuePartie),
    controller(c)
{
    ui->setupUi(this);


    setAffichageScore();
    setAffichageTuile();
    setJoueurActu();



}

VuePartie::~VuePartie()
{
    delete ui;
}


void VuePartie::setAffichageScore() {
     int nbrJ = this->controller->getNbJoueur();
     vector<Joueur*> vectJoueur = this->controller->getJoueurs();
     vector<VueScore1Joueur*> vectVueScore;
     for (int i = 0; i < nbrJ; i++){
         VueScore1Joueur* vueScore = new VueScore1Joueur(vectJoueur[i]->getName());
         ui->affichageScore->addWidget(vueScore);
     }
     ui->numTour->display(controller->getTour());

}

void VuePartie::setAffichageTuile(){
    const Tuile tuilePlace= this->controller->getPioche()->piocher();
    VueTuile* vueTuilePlace = new VueTuile(tuilePlace);
    ui->espaceTuilePlace->addWidget(vueTuilePlace);
}

void VuePartie::setJoueurActu(){
    ui->labelNomJ->setText(QString::fromStdString(controller->getJoueurs()[controller->getNumJoueurActu()]->getName()));
    ui->nbrMeepleRestant->display(controller->getJoueurs()[controller->getNumJoueurActu()]->getNbrMeeples());
}
