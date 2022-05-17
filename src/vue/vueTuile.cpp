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
    int placement;
    TypesTuiles typeTuile;
    vector<ContenanceTuile> contenance = tuile.getContenance();
    for (auto itContenance = contenance.cbegin(); itContenance < contenance.cend(); itContenance++){
           placement = itContenance->getNumPlacement();
           typeTuile = itContenance->getType();
           VueContenuTuile* contenuTuile = new VueContenuTuile(typeTuile, placement);
           switch (placement) {
           case route:
               ui->grilleContenuTuile->addWidget(contenuTuile, 0,0);
               break;
           case abbaye:
               ui->grilleContenuTuile->addWidget(contenuTuile, 0,1);
               break;
           case ville:
               ui->grilleContenuTuile->addWidget(contenuTuile, 0,2);
               break;
           case champs:
               ui->grilleContenuTuile->addWidget(contenuTuile, 1,2);
               break;
           case rivière:
               ui->grilleContenuTuile->addWidget(contenuTuile, 2,2);
               break;
           case auberge:
               ui->grilleContenuTuile->addWidget(contenuTuile, 2,1);
               break;
           case cathédrale:
               ui->grilleContenuTuile->addWidget(contenuTuile, 2,0);
               break;
           case jardin:
               ui->grilleContenuTuile->addWidget(contenuTuile, 1,0);
               break;
           case 8:
               ui->grilleContenuTuile->addWidget(contenuTuile, 1,1);
               break;
           default:
               break;
           }
    }

}
