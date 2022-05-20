#include "vueTuile.h"
#include "vueContenuTuile.h"
#include "ui_vueTuile.h"

VueTuile::VueTuile(Tuile tuile ,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VueTuile)
{
    ui->setupUi(this);
//    VueContenuTuile* testContenuTuile = new VueContenuTuile(route);
//    ui->grilleContenuTuile->addWidget(testContenuTuile, 0,0);
    this->resize(225,225);
    ui->gridLayoutWidget->resize(225,225);
    vector<VueContenuTuile*> tabTest(9);
//    int i = 0;
//    tabTest[0] = new VueContenuTuile(ville);
//    tabTest[1] = new VueContenuTuile(route);
//    tabTest[2] = new VueContenuTuile(auberge);
//    tabTest[3] = new VueContenuTuile(route);
//    tabTest[4] = new VueContenuTuile(ville);
//    tabTest[5] = new VueContenuTuile(route);
//    tabTest[6] = new VueContenuTuile(ville);
//    tabTest[7] = new VueContenuTuile(route);
//    tabTest[8] = new VueContenuTuile(ville);

//    ui->grilleContenuTuile->addWidget(tabTest[0], 0,0);
//    ui->grilleContenuTuile->addWidget(tabTest[2], 0,1);
//    ui->grilleContenuTuile->addWidget(tabTest[1], 0,2);

//    i= 1;
//    tabTest[i] = new VueContenuTuile(route);
//    ui->grilleContenuTuile->addWidget(tabTest[i], 1,0);

//    i = 2,
//    tabTest[i] = new VueContenuTuile(route);
//    ui->grilleContenuTuile->addWidget(tabTest[i], 2,0);

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
           std::cout<<"placement :"<<placement<< std::endl;
//           VueContenuTuile* contenuTuile = new VueContenuTuile(typeTuile);
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
