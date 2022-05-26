#include "vuePartie.h"
#include "ui_vuePartie.h"
#include "vueScore1Joueur.h"

VuePartie::VuePartie(Controller* c, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VuePartie),
    controller(c)
{
    ui->setupUi(this);


    setAffichageScore();
    setAffichageTuile();

}

VuePartie::~VuePartie()
{
    delete ui;
}


void VuePartie::setAffichageScore() {
     int nbrJ = this->controller->getNbJoueur();
     vector<Joueur*> vectJoueur = this->controller->getJoueurs();
     vector<VueScore1Joueur*> vectVueScore;
     std::cout<<nbrJ;
     for (int i = 0; i < nbrJ; i++){
         VueScore1Joueur* vueScore = new VueScore1Joueur(vectJoueur[i]->getName());
         ui->affichageScore->addWidget(vueScore);
     }

}

void VuePartie::setAffichageTuile(){
    const Tuile tuilePlace= this->controller->getPioche()->piocher();
    VueTuile* vueTuilePlace = new VueTuile(tuilePlace);
    ui->espaceTuilePlace->addWidget(vueTuilePlace);
}

//void VuePartie::ajout1Score(){
//    this.
//}
