//
//  Tuiles.cpp
//  Caracassonne
//
//  Created by Massil on 07/05/2022.
//

#include "tuile.h"

using namespace std;

// --------------------------------------------- Class ContenanceTuile ------------------------------------------------


void ContenanceTuile::setBouclier(){
    if (type == ville) {bouclier = true ;}
    else {throw "Impossible : ce n'est pas une ville";}
}


ContenanceTuile::ContenanceTuile(const ContenanceTuile& c):numPlacement(c.numPlacement), type(c.type), bouclier(c.bouclier){;}

ContenanceTuile& ContenanceTuile::operator=(const ContenanceTuile& c){
    numPlacement = c.numPlacement;
    type = c.type;
    bouclier = c.bouclier;
    return *this;
}



// ------------------------------------------------ Class Tuile -------------------------------------------------------



Tuile::Tuile(const vector<ContenanceTuile>& c): voisin_haut(nullptr),voisin_bas(nullptr),voisin_gauche(nullptr),voisin_droite(nullptr),
                                                contenance(c.size()){
    for ( size_t i = 0; i < size(c); i++){
        contenance[i] = c[i];
    }
}


void Tuile::changerOrientation(){
    ContenanceTuile c0 = contenance[0];
    ContenanceTuile c1 = contenance[1];
    for (size_t i = 0 ; i < 6 ; i++){
        contenance[i] = contenance[i+2];
    }
    contenance[6] = c0;
    contenance[7] = c1;
}



Tuile::Tuile(const Tuile& T):
        voisin_haut(T.voisin_haut),voisin_bas(T.voisin_bas),voisin_gauche(T.voisin_gauche),voisin_droite(T.voisin_droite),
        posX(T.posX),posY(T.posY),
        contenance(T.contenance.size()){    // Impossible d'initialiser contenance avec T.getSize()
    for (int i = 0 ; i < 9; i++){
        contenance[i] = T.contenance[i];
    }

}

Tuile& Tuile::operator=(const Tuile& T){

    voisin_haut = T.voisin_haut;
    voisin_bas = T.voisin_bas;
    voisin_gauche = T.voisin_gauche;
    voisin_droite = T.voisin_droite;
    posX = T.posX;
    posY = T.posY;
    contenance = T.contenance;
    return *this;
}


ostream& operator<<(ostream& f, const Tuile& T){

    f << &T <<endl;
    for (int i = 0; i < 3 ; i++ )
    {
        f << i << " : " << T.getContenu(i) << '\t';
        if (T.getContenu(i) == 2 && T.getContenance(i).getBouclier() ) { f << "Bouclier"<<endl;}
    }
    f<< endl;

    f << 7 << " : " << T.getContenu(7);
    if (T.getContenu(7) == 2 && T.getContenance(7).getBouclier() ) { f << " Bouclier"<<endl;}
    f << '\t';

    f << 8 << " : " << T.getContenu(8);
    if (T.getContenu(8) == 2 && T.getContenance(8).getBouclier() ) { f << " Bouclier"<<endl;}
    f << '\t';

    f << 3 << " : " << T.getContenu(3);
    if (T.getContenu(3) == 2 && T.getContenance(3).getBouclier() ) { f << " Bouclier"<<endl;}
    f << '\t';

    f<< endl;

    f << 6 << " : " << T.getContenu(6);
    if (T.getContenu(6) == 2 && T.getContenance(6).getBouclier() ) { f << " Bouclier"<<endl;}
    f << '\t';


    f << 5 << " : " << T.getContenu(5);
    if (T.getContenu(5) == 2 && T.getContenance(5).getBouclier() ) { f << " Bouclier"<<endl;}
    f << '\t';

    f << 4 << " : " << T.getContenu(4);
    if (T.getContenu(4) == 2 && T.getContenance(4).getBouclier() ) { f << " Bouclier"<<endl;}
    f << '\t';



    return f;
}

ostream& operator<<(ostream& f, const ContenanceTuile& c){

    f << "Contenance Tuile : " << &c <<endl;
    f << " Type : "<< c.getType()<<endl;
    f << "Position : " << c.getNumPlacement() <<endl;

    return f;
}
