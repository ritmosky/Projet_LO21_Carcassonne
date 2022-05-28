#include "vueTuile.h"
#include "vueContenuTuile.h"
#include "ui_vueTuile.h"

VueTuile::VueTuile(Tuile tuile ,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VueTuile)
{
    ui->setupUi(this);
//    this->resize(225,225);
//    ui->gridLayoutWidget->resize(225,225);
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
    vector<VueContenuTuile*> tabTest(9);
    int i = 0;
    for (auto itContenance = contenance.cbegin(); itContenance < contenance.cend(); itContenance++){
           placement = itContenance->getNumPlacement();
           typeTuile = itContenance->getType();
           tabTest[i] = new VueContenuTuile(typeTuile);
           switch (placement) {
           case 0:
               ui->grilleContenuTuile->addWidget(tabTest[i], 0,0);
               break;
           case 1:
               ui->grilleContenuTuile->addWidget(tabTest[i], 0,1);
               break;
           case 2:
               ui->grilleContenuTuile->addWidget(tabTest[i], 0,2);
               break;
           case 3:
               ui->grilleContenuTuile->addWidget(tabTest[i], 1,2);
               break;
           case 4:
               ui->grilleContenuTuile->addWidget(tabTest[i], 2,2);
               break;
           case 5:
               ui->grilleContenuTuile->addWidget(tabTest[i], 2,1);
               break;
           case 6:
               ui->grilleContenuTuile->addWidget(tabTest[i], 2,0);
               break;
           case 7:
               ui->grilleContenuTuile->addWidget(tabTest[i], 1,0);
               break;
           case 8:
               ui->grilleContenuTuile->addWidget(tabTest[i], 1,1);
               break;
           default:
               break;
           }
           i++;
    }

}