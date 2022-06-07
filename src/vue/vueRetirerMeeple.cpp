#include "vueRetirerMeeple.h"
#include "ui_vueRetirerMeeple.h"
#include "QtWidgets/qpushbutton.h"
#include "vueTuile.h"
#include "modele/tuile.h"



VueRetirerMeeple::VueRetirerMeeple(QWidget *parent, VuePartie* part, const int l, const int c, Tuile* t) :
    QDialog(parent),
    ui(new Ui::VueRetirerMeeple),
    partie(part),
    Nligne(l),
    NCol(c),
    tuile(t)
{
    ui->setupUi(this);
}


VueRetirerMeeple::~VueRetirerMeeple(){
    delete ui;
}



void VueRetirerMeeple::on_oui_clicked(){
    cout << "\n Il y a un Espace complet";
    // ---------- Retrait du MEEPLE // ---------- //
    VueTuile* vT = new VueTuile(tuile);
    VueOuRetirerMeeple* affichage = new VueOuRetirerMeeple(nullptr,partie,Nligne,NCol,tuile,vT);
    affichage->show();
}


void VueRetirerMeeple::on_non_clicked(){
    cout << "\n Il n\'y a aucun Espace complet";
}

