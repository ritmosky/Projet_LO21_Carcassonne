#include "vueTuile.h"
#include "vueContenuTuile.h"
#include "ui_vueTuile.h"

VueTuile::VueTuile(Tuile tuile ,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VueTuile)
{
    ui->setupUi(this);
    setContenuTuile(tuile);
}

VueTuile::~VueTuile()
{
    delete ui;
}


void VueTuile::setContenuTuile(Tuile& tuile){
    int placement, typeTuile;
    vector<ContenanceTuile> contenance = tuile.getContenance();
    for (auto itContenance = contenance.cbegin(); itContenance < contenance.cend(); itContenance++){
           placement = itContenance->getNumPlacement();
           typeTuile = itContenance->getType();
           VueContenuTuile* contenuTuile = new VueContenuTuile(typeTuile, placement);
           switch (placement) {
           case 0:
               ui->grilleContenuTuile->addWidget(contenuTuile, 0,0);
               break;
           case 1:
               ui->grilleContenuTuile->addWidget(contenuTuile, 0,1);
               break;
           case 2:
               ui->grilleContenuTuile->addWidget(contenuTuile, 0,2);
               break;
           case 3:
               ui->grilleContenuTuile->addWidget(contenuTuile, 1,2);
               break;
           case 4:
               ui->grilleContenuTuile->addWidget(contenuTuile, 2,2);
               break;
           case 5:
               ui->grilleContenuTuile->addWidget(contenuTuile, 2,1);
               break;
           case 6:
               ui->grilleContenuTuile->addWidget(contenuTuile, 2,0);
               break;
           case 7:
               ui->grilleContenuTuile->addWidget(contenuTuile, 0,1);
               break;
           case 8:
               ui->grilleContenuTuile->addWidget(contenuTuile, 1,1);
               break;
           default:
               break;
           }
    }

}
