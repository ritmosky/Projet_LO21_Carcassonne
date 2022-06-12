#include "vuePartie.h"
#include "QtWidgets/qlineedit.h"
#include "ui_vuePartie.h"
#include "vueScore1Joueur.h"
#include "vuePlacementMeeple.h"
#include "vueRetirerMeeple.h"

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
}


VuePartie::~VuePartie(){
    delete ui;
}


void VuePartie::setAffichageScore() {
     int nbrJ = this->controller->getNbJoueur();
     vector<Joueur*> vectJoueur = this->controller->getJoueurs();
     vector<VueScore1Joueur*> vectVueScore;
     for (int i = 0; i < nbrJ; i++){
         VueScore1Joueur* vueScore = new VueScore1Joueur(vectJoueur[i]->getName(), vectJoueur[i]->getId());
         ui->affichageScore->addWidget(vueScore);
     }
     ui->numTour->display(controller->getTour());
}


void VuePartie::setAffichageTuile(){
    cout<<"Nb tuile restantes : "<< controller->getPioche()->getNbTuiles()<<endl;
    cout<<"Extension rivière activée : "<< controller->getRiviereActive()<<endl<<endl;
     for(size_t i = 0; i < controller->getPioche()->getNbTuiles(); i++){
         cout << controller->getPioche()->getTuile(0) << endl << endl;
     }
    tuilePlace = this->controller->getPioche()->piocher(controller->getTour(), controller->getRiviereActive());
    vueTuilePlace = new VueTuile(tuilePlace);
    ui->espaceTuilePlace->addWidget(vueTuilePlace);
    if(controller->placementTuileAutorise(*tuilePlace)){
        this->piocherCarte();
    }
}


void VuePartie::setJoueurActu(){
    ui->labelNomJ->setText(QString::fromStdString(controller->getJoueurs()[controller->getNumJoueurActu()]->getName()));
    ui->nbrMeepleRestant->display(controller->getJoueurs()[controller->getNumJoueurActu()]->getNbrMeeples());
}


void VuePartie::piocherCarte(){
    cout<<"On pioche "<<endl;
    vueTuilePlace->hide();
    tuilePlace = this->controller->getPioche()->piocher(this->controller->getTour(), this->controller->getRiviereActive());
    cout<<"On a pioche "<<endl;
    cout<< *tuilePlace <<endl;
    vueTuilePlace = new VueTuile(tuilePlace);
    ui->espaceTuilePlace->addWidget(vueTuilePlace);
    if(controller->placementTuileAutorise(*tuilePlace)==false){
        this->piocherCarte();
        cout << "Tuile incompatible partout, on l'enlève de la pioche et on repioche " << endl;
    }
}


void VuePartie::setPlateau(){
    ui->plateau->setCurrentCell(76,77);
    ui->plateau->horizontalHeader()->setDefaultSectionSize(100);
    ui->plateau->verticalHeader()->setDefaultSectionSize(100);
    Tuile *premiereTuile = this->controller->getPioche()->piocher(this->controller->getTour(), this->controller->getRiviereActive());
    placerTuile(72,72, premiereTuile);
    controller->creerEspace(premiereTuile);
    premiereTuile->ReplaceParChamps();
}


// PLACER MEEPLE
void VuePartie::placerMeeple(const int Nligne, const int NCol,Tuile* tuile){
    // Appel à la fenêtre qui demande placement si le joueur possède encore des Meeples
    int nbM = controller->getJoueurs().at(controller->getTour()%(controller->getJoueurs().size()))->getNbrMeeples();
    if ( nbM > 0){
        cout<<"\n---------- Demande à ajouter un Meeple ----------\n";
        vuePlacementMeeple* affichage = new vuePlacementMeeple(nullptr,this,Nligne,NCol,tuile,controller);
        affichage->show();
    }
}



// RETIRER MEEPLE
void VuePartie::retirerMeeple(){
    // Appel à la fenêtre qui demande placement si le joueur n'a pas plus de Meeples fixés
    int nbM = controller->getJoueurs().at(controller->getTour()%(controller->getJoueurs().size()))->getNbrMeeples();
    if ( nbM > 0){  // changer le nombre de meeple max
        cout<<"\n---------- Demande à retirer un Meeple ----------\n";
        VueRetirerMeeple* affichage = new VueRetirerMeeple(this,nullptr);
        affichage->show();
    }
}


// Cette fonction prends en parametre la position X et Y (centré en 0, 0 donc selon constructeur)
void VuePartie::placerTuile(const int Nligne, const int NCol,Tuile* tuile){

    VueTuile* vueTuilePlace = new VueTuile(tuile);
    ui->plateau->setCellWidget(Nligne,NCol, vueTuilePlace);
    this->controller->placementTuile(tuile,NCol,Nligne);

}


// PENSER A RETIRER 1 MEEPLE DU JOUEUR COURANT
// la fonction permet de changer l'affichage d'une tuile en ajoutant un MEEPLE
void VuePartie::updateVueTuileAddM(int l, int c, int p, Tuile* T){
    VueTuile* vueTuilePlace = new VueTuile(T);
    vueTuilePlace->addMeeple(T, p,controller->getJoueurs().at(controller->getTour()%(controller->getJoueurs().size()))->getId()-1);
    ui->plateau->setCellWidget(l,c,vueTuilePlace);
}


// la fonction permet de changer l'affichage d'une tuile en retirant un MEEPLE
void VuePartie::updateVueTuileRemoveM(int l, int c){
    // regarder dans meeple si une adresse de ContenaceTuile de la tuile s'y trouve
    Tuile* T = controller->getPlateau()->existeTuile(c-1,l-1);
    VueTuile* vT = new VueTuile(T);
    ui->plateau->setCellWidget(l-1,c-1,vT);
    int tour = controller->getTour()-1;
    controller->getJoueurs().at(tour%(controller->getJoueurs().size()))->addnbrMeeple();
}


void VuePartie::on_zoomIn_clicked(){
    int tailleHori = ui->plateau->horizontalHeader()->defaultSectionSize();
    int tailleVert = ui->plateau->verticalHeader()->defaultSectionSize();
    ui->plateau->horizontalHeader()->setDefaultSectionSize(tailleHori + 20);
    ui->plateau->verticalHeader()->setDefaultSectionSize(tailleVert + 20);

}


void VuePartie::on_zoomOut_clicked(){
    int tailleHori = ui->plateau->horizontalHeader()->defaultSectionSize();
    int tailleVert = ui->plateau->verticalHeader()->defaultSectionSize();
    ui->plateau->horizontalHeader()->setDefaultSectionSize(tailleHori - 20);
    ui->plateau->verticalHeader()->setDefaultSectionSize(tailleVert - 20);
}


void VuePartie::on_bouttonValiderTuile_clicked(){
    //Changement du jardin et de l'auberge en jardin dans l'extension Paysan et AubergesEtCathédrales
     bool hasJardin = false;
     bool hasAuberge = false;
     int placementChamps = 0;
     for (int i = 0; i < 9; i++){
         if(tuilePlace->getContenu(i) == TypesTuiles::auberge){
             tuilePlace->setContenu(i, TypesTuiles::champs);
             placementChamps = i;
             hasAuberge = true;
             break;
         }
         if(tuilePlace->getContenu(i)==TypesTuiles::jardin){
             tuilePlace->setContenu(i, TypesTuiles::champs);
             placementChamps = i;
             hasJardin = true;
             break;
         }
     }

    bool insere = true;
    vector<int> extensions = controller->getExtensions();
    for(size_t i=0; i<extensions.size();i++){
        ModeJeu *modeJeu = controller->getModeJeu(extensions[i]-1);
        if(modeJeu->validationPlacementT(*tuilePlace,ui->plateau->currentColumn(),ui->plateau->currentRow(),controller->getPlateau())==false){
            insere = false;
        }
    }

    if(insere==true){
        // Remettre le champs en jardin et le champ en auberge pour le placement des meeples
         if(hasAuberge==true){
             tuilePlace->setContenu(placementChamps, TypesTuiles::auberge);
         }
         if(hasJardin==true){
             tuilePlace->setContenu(placementChamps, TypesTuiles::jardin);
         }

         placerTuile(ui->plateau->currentRow(),ui->plateau->currentColumn(),tuilePlace);
         controller->creerEspace(tuilePlace);
         controller->fusionVoisin(tuilePlace);

         placerMeeple(ui->plateau->currentRow(),ui->plateau->currentColumn(),tuilePlace); // placerMeeple appellera placerTuile
         retirerMeeple();

         controller->nextTour();
         ui->numTour->display(controller->getTour());
         ui->labelNomJ->setText(QString::fromStdString(controller->getJoueurs().at(controller->getTour()%(controller->getJoueurs().size()))->getName()));
         ui->nbrMeepleRestant->display(controller->getJoueurs().at(controller->getTour()%(controller->getJoueurs().size()))->getNbrMeeples());
                  if(controller->getPioche()->estVide()==true){
                 delete vueTuilePlace;
    }
         else{
         piocherCarte();
         }
    }
    else{
        cout << " INCOMPATIBLEEEEEEEEEEEE "<< endl;
    }
}


void VuePartie::on_rotationTuile_clicked(){

    vueTuilePlace->hide();
    tuilePlace->changerOrientation();
    vueTuilePlace = new VueTuile(tuilePlace);
    ui->espaceTuilePlace->addWidget(vueTuilePlace);
}


void VuePartie::partieFinie(){
    delete ui->affNbrMeeple;
    delete ui->labelNomJ;
    delete ui->nbrMeepleRestant;
    ui->affCestAuTour->setText("Il n'y a plus aucune carte à piocher, la partie est désormais terminée.\n Les joueurs doivent désormais ajouter leurs points de fin de partie en suivant les règles du jeu via les boutons + et - habituels!");
    delete vueTuilePlace;
    delete ui->bouttonValiderTuile;
    delete ui->label_2;
    delete ui->rotationTuile;

}



void VuePartie::on_bouttonFinPartie_clicked()
{
    this->partieFinie();
}

