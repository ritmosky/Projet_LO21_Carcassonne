#include "vuePlacementMeeple.h"
#include "modele/controller.h"
#include "modele/tuile.h"
#include "ui_vuePlacementMeeple.h"



vuePlacementMeeple::vuePlacementMeeple(QWidget *parent, VuePartie* partie, const int l, const int c ,Tuile* tuile,Controller* con):
    QDialog(parent),
    ui(new Ui::vuePlacementMeeple),
    partie(partie),
    Nligne(l),
    NCol(c) ,
    tuile(tuile),
    controller(con)
{
    ui->setupUi(this);
}



vuePlacementMeeple::~vuePlacementMeeple(){
    delete ui;
}



void vuePlacementMeeple::on_Non_clicked(){
    cout<<"Je clique sur non, je ne veux pas placer de meeple"<<endl;
}



void vuePlacementMeeple::on_Oui_clicked(){
    // ---------- Placement du MEEPLE // ---------- //
    vueOuPlacerMeeple* affichage = new vueOuPlacerMeeple(Nligne,NCol,nullptr,partie,tuile,controller);
    affichage->show();
}


