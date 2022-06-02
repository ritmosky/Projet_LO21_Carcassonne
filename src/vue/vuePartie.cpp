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
    tuilePlace= this->controller->getPioche()->piocher();
    vueTuilePlace = new VueTuile(*tuilePlace);
    ui->espaceTuilePlace->addWidget(vueTuilePlace);
}

void VuePartie::setJoueurActu(){
    ui->labelNomJ->setText(QString::fromStdString(controller->getJoueurs()[controller->getNumJoueurActu()]->getName()));
    ui->nbrMeepleRestant->display(controller->getJoueurs()[controller->getNumJoueurActu()]->getNbrMeeples());
}

void VuePartie::piocherCarte(){
    vueTuilePlace->hide();s
    tuilePlace= this->controller->getPioche()->piocher();
    vueTuilePlace = new VueTuile(*tuilePlace);
    ui->espaceTuilePlace->addWidget(vueTuilePlace);
}

void VuePartie::setPlateau(){
    ui->plateau->setCurrentCell(76,77);
    ui->plateau->horizontalHeader()->setDefaultSectionSize(100);
    ui->plateau->verticalHeader()->setDefaultSectionSize(100);
    // A decommenter pour ne pas voir les numeros de ligne du dessus
//    ui->plateau->horizontalHeader()->setVisible(false);
//    ui->plateau->verticalHeader()->setVisible(false);
    Tuile *premiereTuile= this->controller->getPioche()->piocher();
    placerTuile(72,72, *premiereTuile);
}


// Cette fonction prends en parametre la position X et Y (centré en 0, 0 donc selon constructeur)
void VuePartie::placerTuile(const int Nligne, const int NCol,Tuile& tuile){
    VueTuile* vueTuilePlace = new VueTuile(tuile);
    ui->plateau->setCellWidget(Nligne,NCol, vueTuilePlace);
    this->controller->placementTuile(&tuile,NCol,Nligne);
    cout << " --------------------------  Affichage des tuiles présentes sur le plateau ------------------------------------- " << endl;
    std::vector<Tuile*> tuiles =controller->getPlateau()->getTuiles();
     for(Tuile* t : tuiles){
         cout << *t << endl << endl;
         cout << t->getX() << " " << t->getY() << endl;
     }

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
    if(this->controller->estCompatible(*tuilePlace,ui->plateau->currentColumn(),ui->plateau->currentRow())==true){
         placerTuile(ui->plateau->currentRow(),ui->plateau->currentColumn(),*tuilePlace);
         controller->nextTour();
         piocherCarte();

    }
    else{
        cout << " INCOMPATIBLEEEEEEEEEEEE "<< endl;
    }
}


void VuePartie::on_rotationTuile_clicked(){

    vueTuilePlace->hide();
    tuilePlace->changerOrientation();
    vueTuilePlace = new VueTuile(*tuilePlace);
    ui->espaceTuilePlace->addWidget(vueTuilePlace);
}

