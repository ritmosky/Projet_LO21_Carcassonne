#include "vuePlacementMeeple.h"
#include "modele/tuile.h"
#include "ui_vuePlacementMeeple.h"



vuePlacementMeeple::vuePlacementMeeple(QWidget *parent, VuePartie* partie, const int l, const int c ,Tuile* tuile):
    QDialog(parent),
    ui(new Ui::vuePlacementMeeple),
    partie(partie),
    Nligne(l),
    NCol(c) ,
    tuile(tuile)
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
    cout<<"Je clique sur oui, je veux placer un meeple";
    cout << "\nligne = " << Nligne+1 << " col = " << NCol+1;
    cout<<"\nChoisir le contenu de la tuile d\'adresse :" << tuile;  
    // ---------- Placement du MEEPLE // ---------- //
    vueOuPlacerMeeple* affichage = new vueOuPlacerMeeple(Nligne,NCol,nullptr,partie,tuile);
    affichage->show();
}


