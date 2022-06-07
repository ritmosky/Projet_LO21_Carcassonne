#include "vueOuRetirerMeeple.h"
#include "ui_vueOuRetirerMeeple.h"
#include "QtWidgets/qpushbutton.h"
#include "vueTuile.h"
#include "modele/tuile.h"



VueOuRetirerMeeple::VueOuRetirerMeeple(QWidget *parent,VuePartie* partie,const int l,const int c,Tuile* T,VueTuile* vt):
    QDialog(parent),
    ui(new Ui::VueOuRetirerMeeple),
    partie(partie),
    tuile(T),
    vTuile(vt),
    Nligne(l),
    NCol(c)
{
    ui->setupUi(this);
    printTuile(*tuile);
}


VueOuRetirerMeeple::~VueOuRetirerMeeple(){
    delete ui;
}




void VueOuRetirerMeeple::printTuile(Tuile& tuile){
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
               ui->enleverMT->addWidget(tabTest[i], 0,0);
               break;
           case 1:
               ui->enleverMT->addWidget(tabTest[i], 0,1);
               break;
           case 2:
               ui->enleverMT->addWidget(tabTest[i], 0,2);
               break;
           case 3:
               ui->enleverMT->addWidget(tabTest[i], 1,2);
               break;
           case 4:
               ui->enleverMT->addWidget(tabTest[i], 2,2);
               break;
           case 5:
               ui->enleverMT->addWidget(tabTest[i], 2,1);
               break;
           case 6:
               ui->enleverMT->addWidget(tabTest[i], 2,0);
               break;
           case 7:
               ui->enleverMT->addWidget(tabTest[i], 1,0);
               break;
           case 8:
               ui->enleverMT->addWidget(tabTest[i], 1,1);
               break;
           default:
               break;
           }
           i++;
    }
}


void VueOuRetirerMeeple::retirerM(VueTuile& vt){
    // Vérification de la présence d'un meeple
    vector<VueContenuTuile*> tabVCT = vt.getVueContenuT();
    int p(-1);
    for (int i=0; i<9; i++){
        if (tabVCT[i]->getMeeple() == true){
            p = i;
        }
    }

    // Retrait du meeple
    if (p<0){
        cout<<"Aucun Meeple à présent\n";
    }
    else{
        // le booléen false indique qu'on retire le meeple
        // pour l'ajout de meeple on met true à la place
        partie->updateVueTuileM(72,72,p,tuile,false);
    }
}


void VueOuRetirerMeeple::on_OUI_clicked(){
    retirerM(*vTuile);
    this->close();
}

