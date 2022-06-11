#include "vueOuPlacerMeeple.h"
#include "ui_vueOuPlacerMeeple.h"
#include "QtWidgets/qpushbutton.h"
#include "vueTuile.h"
#include "modele/tuile.h"
#include "vuePlacementMeeple.h"



vueOuPlacerMeeple::vueOuPlacerMeeple(int l,int c, QWidget *parent,VuePartie* part,Tuile* t,Controller *con):
    QDialog(parent),
    ui(new Ui::vueOuPlacerMeeple),
    partie(part),
    Nligne(l),
    Ncol(c),
    tuile(t),
    controller(con)
{
    ui->setupUi(this);
    setTuile(*tuile);
}

vueOuPlacerMeeple::~vueOuPlacerMeeple(){
    delete ui;
}


void vueOuPlacerMeeple::setTuile(Tuile& tuile){
    int placement;
    TypesTuiles typeTuile;
    vector<ContenanceTuile> contenance = tuile.getContenance();
    vector<VueContenuTuile*> tabTest(9);

    int i = 0;
    for (auto itContenance = contenance.cbegin(); itContenance < contenance.cend(); itContenance++){
           placement = itContenance->getNumPlacement();
           typeTuile = itContenance->getType();
           bool bouclier = itContenance->getBouclier();
           tabTest[i] = new VueContenuTuile(typeTuile, bouclier);
           switch (placement) {
           case 0:
               ui->affichageTuile->addWidget(tabTest[i], 0,0);
               break;
           case 1:
               ui->affichageTuile->addWidget(tabTest[i], 0,1);
               break;
           case 2:
               ui->affichageTuile->addWidget(tabTest[i], 0,2);
               break;
           case 3:
               ui->affichageTuile->addWidget(tabTest[i], 1,2);
               break;
           case 4:
               ui->affichageTuile->addWidget(tabTest[i], 2,2);
               break;
           case 5:
               ui->affichageTuile->addWidget(tabTest[i], 2,1);
               break;
           case 6:
               ui->affichageTuile->addWidget(tabTest[i], 2,0);
               break;
           case 7:
               ui->affichageTuile->addWidget(tabTest[i], 1,0);
               break;
           case 8:
               ui->affichageTuile->addWidget(tabTest[i], 1,1);
               break;
           default:
               break;
           }
           i++;
    }
}


void vueOuPlacerMeeple::on_c0_clicked(){
    int tour = controller->getTour()-1;
    cout<<"\nPlacer le Meeple sur c0 : "<< tuile->getContenance()[0];
    bool insere = true;
    vector<int> extensions = controller->getExtensions();
    size_t nbr = 0;
    std::vector<int>::iterator it = std::find(extensions.begin(), extensions.end(), 1);
    std::vector<int>::iterator it2 = std::find(extensions.begin(), extensions.end(), 2);
    if (it != extensions.end() && it2!= extensions.end()){
        nbr = 1;
    }
        Meeple *m = new Meeple();
        m->setIdJoueur(controller->getNumJoueurActu());

    for(size_t i = nbr ; i<extensions.size();i++){
        ModeJeu *modeJeu = controller->getModeJeu(extensions[i]-1);
        if(modeJeu->validationPlacementM(tuile->getContenu(0),m,controller->getEspace(tuile->getContenancePointeur(0)))==false){
            insere = false;
        }
        else{
            cout << "Impossible";
        }
    }

   if(insere==true){
   partie->updateVueTuileAddM(this->Nligne, this->Ncol, 0, tuile);
   cout << "**********" << controller->getTour() << endl;
    controller->placementMeeple(controller->getJoueurs().at(tour%(controller->getJoueurs().size())),m,tuile->getContenu(0),0,Ncol,Nligne);

   }
   else{
       cout << "ITS IMPOSSIBLE" << endl;
   }
   //sinon afficher une méthode invalide et demander de replacer
}

void vueOuPlacerMeeple::on_c1_clicked(){
        int tour = controller->getTour()-1;
    cout<<"\nPlacer le Meeple sur c1 : "<< tuile->getContenance()[1];

    bool insere = true;
    vector<int> extensions = controller->getExtensions();
    size_t nbr = 0;
    std::vector<int>::iterator it = std::find(extensions.begin(), extensions.end(), 1);
    std::vector<int>::iterator it2 = std::find(extensions.begin(), extensions.end(), 2);
    if (it != extensions.end() && it2!= extensions.end()){
        nbr = 1;
    }
        Meeple *m = new Meeple();
        m->setIdJoueur(controller->getNumJoueurActu());
    for(size_t i = nbr ; i<extensions.size();i++){
        ModeJeu *modeJeu = controller->getModeJeu(extensions[i]-1);
        if(modeJeu->validationPlacementM(tuile->getContenu(1),m,controller->getEspace(tuile->getContenancePointeur(1)))==false){
            insere = false;
        }
    }
    if(insere==true){
        partie->updateVueTuileAddM(this->Nligne, this->Ncol, 1, tuile);
         controller->placementMeeple(controller->getJoueurs().at(tour%(controller->getJoueurs().size())),m,tuile->getContenu(1),1,Ncol,Nligne);
    }
    else{
        cout << "ITS IMPOSSIBLE" << endl;
    }
}

void vueOuPlacerMeeple::on_c2_clicked(){
        int tour = controller->getTour()-1;
    cout<<"\nPlacer le Meeple sur c2 : "<< tuile->getContenance()[2];
    bool insere = true;
    vector<int> extensions = controller->getExtensions();
    size_t nbr = 0;
    std::vector<int>::iterator it = std::find(extensions.begin(), extensions.end(), 1);
    std::vector<int>::iterator it2 = std::find(extensions.begin(), extensions.end(), 2);
    if (it != extensions.end() && it2!= extensions.end()){
        nbr = 1;
    }
        Meeple *m = new Meeple();
        m->setIdJoueur(controller->getNumJoueurActu());
    for(size_t i = nbr ; i<extensions.size();i++){
        ModeJeu *modeJeu = controller->getModeJeu(extensions[i]-1);
        if(modeJeu->validationPlacementM(tuile->getContenu(2),m,controller->getEspace(tuile->getContenancePointeur(2)))==false){
            insere = false;
        }
    }
    if(insere==true){
        partie->updateVueTuileAddM(this->Nligne, this->Ncol, 2, tuile);
         controller->placementMeeple(controller->getJoueurs().at(tour%(controller->getJoueurs().size())),m,tuile->getContenu(2),2,Ncol,Nligne);
    }
    else{
        cout << "ITS IMPOSSIBLE" << endl;
    }
}

void vueOuPlacerMeeple::on_c3_clicked(){
        int tour = controller->getTour()-1;
    cout<<"\nPlacer le Meeple sur c3 : "<< tuile->getContenance()[3];
    bool insere = true;
    vector<int> extensions = controller->getExtensions();
    size_t nbr = 0;
    std::vector<int>::iterator it = std::find(extensions.begin(), extensions.end(), 1);
    std::vector<int>::iterator it2 = std::find(extensions.begin(), extensions.end(), 2);
    if (it != extensions.end() && it2!= extensions.end()){
        nbr = 1;
    }
        Meeple *m = new Meeple();
        m->setIdJoueur(controller->getNumJoueurActu());
    for(size_t i = nbr ; i<extensions.size();i++){
        ModeJeu *modeJeu = controller->getModeJeu(extensions[i]-1);
        if(modeJeu->validationPlacementM(tuile->getContenu(3),m,controller->getEspace(tuile->getContenancePointeur(3)))==false){
            insere = false;
        }
    }

    if(insere==true){
    partie->updateVueTuileAddM(this->Nligne, this->Ncol, 3, tuile);
     controller->placementMeeple(controller->getJoueurs().at(tour%(controller->getJoueurs().size())),m,tuile->getContenu(3),3,Ncol,Nligne);
    }
    else{
        cout << "ITS IMPOSSIBLE" << endl;
    }
}

void vueOuPlacerMeeple::on_c4_clicked(){
        int tour = controller->getTour()-1;
    cout<<"\nPlacer le Meeple sur c4 : "<< tuile->getContenance()[4];
    bool insere = true;
    vector<int> extensions = controller->getExtensions();
    size_t nbr = 0;
    std::vector<int>::iterator it = std::find(extensions.begin(), extensions.end(), 1);
    std::vector<int>::iterator it2 = std::find(extensions.begin(), extensions.end(), 2);
    if (it != extensions.end() && it2!= extensions.end()){
        nbr = 1;
    }
    else{
        cout << "ITS IMPOSSIBLE" << endl;
    }
    Meeple *m = new Meeple();

    m->setIdJoueur(controller->getNumJoueurActu());
    for(size_t i = nbr ; i<extensions.size();i++){
        ModeJeu *modeJeu = controller->getModeJeu(extensions[i]-1);

        if(modeJeu->validationPlacementM(tuile->getContenu(4),m,controller->getEspace(tuile->getContenancePointeur(4)))==false){
            insere = false;
        }
    }
    if(insere==true){
    partie->updateVueTuileAddM(this->Nligne, this->Ncol, 4, tuile);
     controller->placementMeeple(controller->getJoueurs().at(tour%(controller->getJoueurs().size())),m,tuile->getContenu(4),4,Ncol,Nligne);
    }
    else{
        cout << "ITS IMPOSSIBLE" << endl;
    }
}

void vueOuPlacerMeeple::on_c5_clicked(){
        int tour = controller->getTour()-1;
    cout<<"\nPlacer le Meeple sur c5 : "<< tuile->getContenance()[5];
    bool insere = true;
    vector<int> extensions = controller->getExtensions();
    size_t nbr = 0;
    std::vector<int>::iterator it = std::find(extensions.begin(), extensions.end(), 1);
    std::vector<int>::iterator it2 = std::find(extensions.begin(), extensions.end(), 2);
    if (it != extensions.end() && it2!= extensions.end()){
        nbr = 1;
    }
        Meeple *m = new Meeple();
        m->setIdJoueur(controller->getNumJoueurActu());
    for(size_t i = nbr ; i<extensions.size();i++){
        ModeJeu *modeJeu = controller->getModeJeu(extensions[i]-1);
        if(modeJeu->validationPlacementM(tuile->getContenu(5),m,controller->getEspace(tuile->getContenancePointeur(5)))==false){
            insere = false;
        }
    }
    if(insere==true){
    partie->updateVueTuileAddM(this->Nligne, this->Ncol, 5, tuile);
     controller->placementMeeple(controller->getJoueurs().at(tour%(controller->getJoueurs().size())),m,tuile->getContenu(5),5,Ncol,Nligne);
    }
    else{
        cout << "ITS IMPOSSIBLE" << endl;
    }
}

void vueOuPlacerMeeple::on_c6_clicked(){
        int tour = controller->getTour()-1;
    cout<<"\nPlacer le Meeple sur c6 : "<< tuile->getContenance()[6];
    bool insere = true;
    vector<int> extensions = controller->getExtensions();
    size_t nbr = 0;
    std::vector<int>::iterator it = std::find(extensions.begin(), extensions.end(), 1);
    std::vector<int>::iterator it2 = std::find(extensions.begin(), extensions.end(), 2);
    if (it != extensions.end() && it2!= extensions.end()){
        nbr = 1;
    }
        Meeple *m = new Meeple();
        m->setIdJoueur(controller->getNumJoueurActu());
    for(size_t i = nbr ; i<extensions.size();i++){
        ModeJeu *modeJeu = controller->getModeJeu(extensions[i]-1);
        if(modeJeu->validationPlacementM(tuile->getContenu(6),m,controller->getEspace(tuile->getContenancePointeur(6)))==false){
            insere = false;
        }
    }
    if(insere==true){
    partie->updateVueTuileAddM(this->Nligne, this->Ncol, 6, tuile);
     controller->placementMeeple(controller->getJoueurs().at(tour%(controller->getJoueurs().size())),m,tuile->getContenu(6),6,Ncol,Nligne);
    }
    else{
        cout << "ITS IMPOSSIBLE" << endl;
    }
}

void vueOuPlacerMeeple::on_c7_clicked(){
        int tour = controller->getTour()-1;

    cout<<"\nPlacer le Meeple sur c7 : "<< tuile->getContenance()[7];
    bool insere = true;
    vector<int> extensions = controller->getExtensions();
    size_t nbr = 0;
    std::vector<int>::iterator it = std::find(extensions.begin(), extensions.end(), 1);
    std::vector<int>::iterator it2 = std::find(extensions.begin(), extensions.end(), 2);
    if (it != extensions.end() && it2!= extensions.end()){
        nbr = 1;
    }
        Meeple *m = new Meeple();
        m->setIdJoueur(controller->getNumJoueurActu());
    for(size_t i = nbr ; i<extensions.size();i++){
        ModeJeu *modeJeu = controller->getModeJeu(extensions[i]-1);
        if(modeJeu->validationPlacementM(tuile->getContenu(7),m,controller->getEspace(tuile->getContenancePointeur(7)))==false){
            insere = false;
        }
    }
    if(insere==true){
    partie->updateVueTuileAddM(this->Nligne, this->Ncol, 7, tuile);
     controller->placementMeeple(controller->getJoueurs().at(tour%(controller->getJoueurs().size())),m,tuile->getContenu(7),7,Ncol,Nligne);
    }
    else{
        cout << "ITS IMPOSSIBLE" << endl;
    }
}

void vueOuPlacerMeeple::on_c8_clicked(){
        int tour = controller->getTour()-1;
    cout<<"\nPlacer le Meeple sur c8 : "<< tuile->getContenance()[8];
    bool insere = true;
    vector<int> extensions = controller->getExtensions();
    size_t nbr = 0;
    std::vector<int>::iterator it = std::find(extensions.begin(), extensions.end(), 1);
    std::vector<int>::iterator it2 = std::find(extensions.begin(), extensions.end(), 2);
    if (it != extensions.end() && it2!= extensions.end()){
        nbr = 1;
    }
    Meeple *m = new Meeple();
    m->setIdJoueur(controller->getNumJoueurActu());
    for(size_t i = nbr ; i<extensions.size();i++){
       ModeJeu *modeJeu = controller->getModeJeu(extensions[i]-1);
        if(modeJeu->validationPlacementM(tuile->getContenu(8),m,controller->getEspace(tuile->getContenancePointeur(8)))==false){
           insere = false;
        }
   }

    if(insere==true){
        partie->updateVueTuileAddM(this->Nligne, this->Ncol, 8, tuile);
        cout << Ncol - 1 << " " << Nligne-1 << endl;
        controller->placementMeeple(controller->getJoueurs().at(tour%(controller->getJoueurs().size())),m,tuile->getContenu(8),8,Ncol,Nligne);
    }
    else{
        cout << "ITS IMPOSSIBLE" << endl;
    }
}
