#include "vueOuPlacerMeeple.h"
#include "ui_vueOuPlacerMeeple.h"
#include "QtWidgets/qpushbutton.h"
#include "vueTuile.h"
#include "modele/tuile.h"



vueOuPlacerMeeple::vueOuPlacerMeeple(int l,int c, QWidget *parent,VuePartie* part,Tuile* t):
    QDialog(parent),
    ui(new Ui::vueOuPlacerMeeple),
    partie(part),
    Nligne(l),
    Ncol(c),
    tuile(t)
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
    cout<<"\nPlacer le Meeple sur c0 : "<< tuile->getContenance()[0];
    partie->updateVueTuileM(this->Nligne, this->Ncol, 0, tuile);
}

void vueOuPlacerMeeple::on_c1_clicked(){
    cout<<"\nPlacer le Meeple sur c1 : "<< tuile->getContenance()[1];
    partie->updateVueTuileM(this->Nligne, this->Ncol, 1, tuile);
}

void vueOuPlacerMeeple::on_c2_clicked(){
    cout<<"\nPlacer le Meeple sur c2 : "<< tuile->getContenance()[1];
    partie->updateVueTuileM(this->Nligne, this->Ncol, 1, tuile);
}

void vueOuPlacerMeeple::on_c3_clicked(){
    cout<<"\nPlacer le Meeple sur c3 : "<< tuile->getContenance()[3];
    partie->updateVueTuileM(this->Nligne, this->Ncol, 3, tuile);
}

void vueOuPlacerMeeple::on_c4_clicked(){
    cout<<"\nPlacer le Meeple sur c4 : "<< tuile->getContenance()[4];
    partie->updateVueTuileM(this->Nligne, this->Ncol, 4, tuile);
}

void vueOuPlacerMeeple::on_c5_clicked(){
    cout<<"\nPlacer le Meeple sur c5 : "<< tuile->getContenance()[5];
    partie->updateVueTuileM(this->Nligne, this->Ncol, 5, tuile);
}

void vueOuPlacerMeeple::on_c6_clicked(){
    cout<<"\nPlacer le Meeple sur c6 : "<< tuile->getContenance()[6];
    partie->updateVueTuileM(this->Nligne, this->Ncol, 6, tuile);
}

void vueOuPlacerMeeple::on_c7_clicked(){
    cout<<"\nPlacer le Meeple sur c7 : "<< tuile->getContenance()[7];
    partie->updateVueTuileM(this->Nligne, this->Ncol, 7, tuile);
}

void vueOuPlacerMeeple::on_c8_clicked(){
    cout<<"\nPlacer le Meeple sur c8 : "<< tuile->getContenance()[8];
    partie->updateVueTuileM(this->Nligne, this->Ncol, 8, tuile);
}
