#include "vuePlacementMeeple.h"
#include "modele/tuile.h"
#include "ui_vuePlacementMeeple.h"

vuePlacementMeeple::vuePlacementMeeple(QWidget *parent, VuePartie* partie, const int Nligne, const int NCol ,Tuile* tuile ):
    QDialog(parent),
    ui(new Ui::vuePlacementMeeple),
    partie(partie),
    Nligne(Nligne),
    NCol(NCol) ,
    tuile(tuile)
{
    ui->setupUi(this);
}

vuePlacementMeeple::~vuePlacementMeeple()
{
    delete ui;
}







void vuePlacementMeeple::on_Oui_clicked(vuePlacementMeeple* affichage)
{
    cout<<"Je clique"<<endl;
    affichage->hide();
    // Affichage pour dire clique sur un Contenu

    // Rendre contenu cliquable et récupérer lequel a été cliqué

    // Construire la Tuile en fonction avec un new

    affichage->partie->placerTuile(Nligne, NCol,tuile);

}


void vuePlacementMeeple::on_Non_clicked(vuePlacementMeeple* affichage)
{
    cout<<"Je clique"<<endl;
    // Pas de modif sur la Tuile
    affichage->hide();
    affichage->partie->placerTuile(Nligne, NCol,tuile);

}



