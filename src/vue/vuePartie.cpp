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
    setJoueurActu();
    setPlateau();
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
     for (int i = 0; i < nbrJ; i++){
         VueScore1Joueur* vueScore = new VueScore1Joueur(vectJoueur[i]->getName());
         ui->affichageScore->addWidget(vueScore);
     }
     ui->numTour->display(controller->getTour());
}

void VuePartie::setAffichageTuile(){
    const Tuile tuilePlace= this->controller->getPioche()->piocher();
    VueTuile* vueTuilePlace = new VueTuile(tuilePlace); // vueTuilePlace est un Widget
    ui->espaceTuilePlace->addWidget(vueTuilePlace);
}

void VuePartie::setJoueurActu(){

    ui->labelNomJ->setText(QString::fromStdString(controller->getJoueurs()[controller->getNumJoueurActu()]->getName()));
    ui->nbrMeepleRestant->display(controller->getJoueurs()[controller->getNumJoueurActu()]->getNbrMeeples());
}

void VuePartie::setPlateau(){
    ui->plateau->setCurrentCell(76,77);
    ui->plateau->horizontalHeader()->setDefaultSectionSize(100);
    ui->plateau->verticalHeader()->setDefaultSectionSize(100);
    // A decommenter pour ne pas voir les numeros de ligne du dessus
//    ui->plateau->horizontalHeader()->setVisible(false);
//    ui->plateau->verticalHeader()->setVisible(false);
    const Tuile tuilePlace= this->controller->getPioche()->piocher();
    placerTuile(72,72, tuilePlace);
}



void VuePartie::placerTuile(const int Nligne, const int NCol, const Tuile& tuile){
    VueTuile* vueTuilePlace = new VueTuile(tuile);
    ui->plateau->setCellWidget(Nligne,NCol, vueTuilePlace);
}






void VuePartie::on_zoomIn_clicked()
{
    int tailleHori = ui->plateau->horizontalHeader()->defaultSectionSize();
    int tailleVert = ui->plateau->verticalHeader()->defaultSectionSize();
    ui->plateau->horizontalHeader()->setDefaultSectionSize(tailleHori + 20);
    ui->plateau->verticalHeader()->setDefaultSectionSize(tailleVert + 20);

}


void VuePartie::on_zoomOut_clicked()
{
    int tailleHori = ui->plateau->horizontalHeader()->defaultSectionSize();
    int tailleVert = ui->plateau->verticalHeader()->defaultSectionSize();
    ui->plateau->horizontalHeader()->setDefaultSectionSize(tailleHori - 20);
    ui->plateau->verticalHeader()->setDefaultSectionSize(tailleVert - 20);
}


void VuePartie::on_bouttonValiderTuile_clicked()
{
    cout<<ui->plateau->currentColumn();
    cout<<ui->plateau->currentRow();// renvoie x

    // Action à faire quand on appuie sur le boutton valider placement tuile
}


void VuePartie::on_bouttonRotation_clicked()
{

   // Appel modele pour rotationner tuile
   // recup la nouvelle tuile rotationner
    // appeler la fonction  affichage tuile avec la nouvelle tuile rotationner

}




