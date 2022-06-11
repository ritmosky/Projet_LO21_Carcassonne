#include "vueTuile.h"
#include "vueContenuTuile.h"
#include "../modele/tuile.h"
#include "ui_vueTuile.h"

VueTuile::VueTuile(Tuile* tuile ,QWidget *parent):
    QWidget(parent),
    ui(new Ui::VueTuile)
{
    ui->setupUi(this);
    setContenuTuile(*tuile);
}



VueTuile::~VueTuile(){
    delete ui;
}



void VueTuile::setContenuTuile(Tuile& tuile){
    int placement;
    TypesTuiles typeTuile;
    vector<ContenanceTuile> contenance = tuile.getContenance();
    this->tabContenuTuile.resize(9);
    int i = 0;
    for (auto itContenance = contenance.cbegin(); itContenance < contenance.cend(); itContenance++){
           placement = itContenance->getNumPlacement();
           typeTuile = itContenance->getType();
           bool bouclier = itContenance->getBouclier();
           tabContenuTuile[i] = new VueContenuTuile(typeTuile, bouclier);
           switch (placement) {
           case 0:
               ui->grilleContenuTuile->addWidget(this->tabContenuTuile[i], 0,0);
               break;
           case 1:
               ui->grilleContenuTuile->addWidget(tabContenuTuile[i], 0,1);
               break;
           case 2:
               ui->grilleContenuTuile->addWidget(tabContenuTuile[i], 0,2);
               break;
           case 3:
               ui->grilleContenuTuile->addWidget(tabContenuTuile[i], 1,2);
               break;
           case 4:
               ui->grilleContenuTuile->addWidget(tabContenuTuile[i], 2,2);
               break;
           case 5:
               ui->grilleContenuTuile->addWidget(tabContenuTuile[i], 2,1);
               break;
           case 6:
               ui->grilleContenuTuile->addWidget(tabContenuTuile[i], 2,0);
               break;
           case 7:
               ui->grilleContenuTuile->addWidget(tabContenuTuile[i], 1,0);
               break;
           case 8:
               ui->grilleContenuTuile->addWidget(tabContenuTuile[i], 1,1);
               break;
           default:
               break;
           }
           i++;
    }
}



void VueTuile::addMeeple(Tuile* tuile,int p,int id){
    ContenanceTuile ct = tuile->getContenance()[p];
    ui->grilleContenuTuile->removeWidget(this->tabContenuTuile[p]);
    tabContenuTuile[p]->hide();
    delete tabContenuTuile[p];
    tabContenuTuile[p] = new VueContenuTuile(ct.getType(), ct.getBouclier(),id, true);
    switch (p) {
    case 0:
        ui->grilleContenuTuile->addWidget(this->tabContenuTuile[p], 0,0);
        break;
    case 1:
        ui->grilleContenuTuile->addWidget(tabContenuTuile[p], 0,1);
        break;
    case 2:
        ui->grilleContenuTuile->addWidget(tabContenuTuile[p], 0,2);
        break;
    case 3:
        ui->grilleContenuTuile->addWidget(tabContenuTuile[p], 1,2);
        break;
    case 4:
        ui->grilleContenuTuile->addWidget(tabContenuTuile[p], 2,2);
        break;
    case 5:
        ui->grilleContenuTuile->addWidget(tabContenuTuile[p], 2,1);
        break;
    case 6:
        ui->grilleContenuTuile->addWidget(tabContenuTuile[p], 2,0);
        break;
    case 7:
        ui->grilleContenuTuile->addWidget(tabContenuTuile[p], 1,0);
        break;
    case 8:
        ui->grilleContenuTuile->addWidget(tabContenuTuile[p], 1,1);
        break;
    default:
        break;
    }
}
