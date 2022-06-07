#include "vuePartie.h"
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
    // A decommenter pour ne pas voir les numeros de ligne du dessus
//    ui->plateau->horizontalHeader()->setVisible(false);
//    ui->plateau->verticalHeader()->setVisible(false);
    Tuile *premiereTuile = this->controller->getPioche()->piocher(this->controller->getTour(), this->controller->getRiviereActive());
    placerTuile(72,72, premiereTuile);
    premiereTuile->ReplaceParChamps();
}


// PLACER MEEPLE
void VuePartie::placerMeeple(const int Nligne, const int NCol,Tuile* tuile){
    // Appel à la fenêtre qui demande placement si le joueur possède encore des Meeples
    Joueur joueur = controller->getNumJoueurActu();
    if ( joueur.getNbrMeeples() > 0){
        cout<<"Demande ajouter Meeple"<<endl;
        vuePlacementMeeple* affichage = new vuePlacementMeeple(nullptr,this,Nligne,NCol,tuile);
        affichage->show();
    }
}



// RETIRER MEEPLE
void VuePartie::retirerMeeple(const int Nligne,const int NCol,Tuile* tuile){
    // Appel à la fenêtre qui demande placement si le joueur n'a pas plus de Meeples fixés
    Joueur joueur = controller->getNumJoueurActu();
    //joueur.getId()
    if ( joueur.getNbrMeeples() > 0){  // changer le nombre de meeple max
        cout<<"Demande retirer Meeple"<<endl;
        VueRetirerMeeple* affichage = new VueRetirerMeeple(nullptr,this,Nligne,NCol,tuile);
        affichage->show();
    }
}


// Cette fonction prends en parametre la position X et Y (centré en 0, 0 donc selon constructeur)
void VuePartie::placerTuile(const int Nligne, const int NCol,Tuile* tuile){

    VueTuile* vueTuilePlace = new VueTuile(tuile);
    ui->plateau->setCellWidget(Nligne,NCol, vueTuilePlace);
    tuile->ReplaceParChamps();
    this->controller->placementTuile(tuile,NCol,Nligne);

    cout << " --------------------------  Affichage des tuiles présentes sur le plateau ------------------------------------- " << endl;
    std::vector<Tuile*> tuiles = controller->getPlateau()->getTuiles();
     for(Tuile* t : tuiles){
         cout << *t << endl << endl;
         cout << t->getX() << " " << t->getY() << endl;
     }
     cout<<endl<<endl<<endl;
     cout<<"Etat de la Pioche :"<<endl;
     for(size_t i = 0; i < controller->getPioche()->getNbTuiles(); i++){
         cout << controller->getPioche()->getTuile(i) << endl << endl;
     }
}


// PENSER A RETIRER 1 MEEPLE DU JOUEUR COURANT
// la fonction permet de changer l'affichage d'une tuile en ajoutant un MEEPLE
void VuePartie::updateVueTuileAddM(int l, int c, int p, Tuile* T){
    VueTuile* vueTuilePlace = new VueTuile(T);
    vueTuilePlace->addMeeple(T, p);
    ui->plateau->setCellWidget(l,c,vueTuilePlace);
}


// la fonction permet de changer l'affichage d'une tuile en retirant un MEEPLE
void VuePartie::updateVueTuileRemoveM(){

        //VueTuile* vueTuilePlace = new VueTuile(T);
        int line(ui->plateau->currentRow());
        int col(ui->plateau->currentColumn());
        //vueTuilePlace = ui->plateau->take(line,col);
        cout<<"\n aaaaa";
        ui->plateau->setCellWidget(line,col,vueTuilePlace);
        cout<<"\n bbbb";
        //placerTuile(l,c,T);
        //ui->plateau->
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
         placerMeeple(ui->plateau->currentRow(),ui->plateau->currentColumn(),tuilePlace); // placerMeeple appellera placerTuile


         retirerMeeple(ui->plateau->currentRow(),ui->plateau->currentColumn(),tuilePlace);

         controller->nextTour();
         ui->numTour->display(controller->getTour());
         ui->labelNomJ->setText(QString::fromStdString(controller->getJoueurs().at(controller->getTour()%(controller->getJoueurs().size()))->getName()));
         ui->nbrMeepleRestant->display(controller->getJoueurs().at(controller->getTour()%(controller->getJoueurs().size()))->getNbrMeeples());
         piocherCarte();
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

