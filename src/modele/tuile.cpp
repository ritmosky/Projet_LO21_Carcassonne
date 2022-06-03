
#include "tuile.h"



// --------------------------------------------- Class ContenanceTuile ------------------------------------------------


void ContenanceTuile::setBouclier(){
    if (type == ville) {bouclier = true ;}
    else {throw "Impossible : ce n'est pas une ville";}
}



ContenanceTuile& ContenanceTuile::operator=(const ContenanceTuile& c){
    numPlacement = c.numPlacement;
    type = c.type;
    bouclier = c.bouclier;
    return *this;
}


// ------------------------------------------------ Class Tuile -------------------------------------------------------


Tuile::Tuile(const vector<ContenanceTuile>& c): voisin_haut(nullptr),voisin_bas(nullptr),voisin_gauche(nullptr),voisin_droite(nullptr),
        contenance(c.size()){

    for ( size_t i = 0; i < c.size(); i++){
        contenance[i] = c[i];
        }
}


void Tuile::changerOrientation(){

    ContenanceTuile c0 = contenance[0];
    ContenanceTuile c1 = contenance[1];

    for (int i = 0 ; i < 6 ; i++){
        contenance[i] = contenance[i+2];
        contenance[i].numPlacement = i ;

    }

    contenance[6] = c0;
    contenance[6].numPlacement = 6;

    contenance[7] = c1;
    contenance[7].numPlacement = 7 ;

}


Tuile::Tuile(const Tuile& T): voisin_haut(T.voisin_haut),voisin_bas(T.voisin_bas),voisin_gauche(T.voisin_gauche),voisin_droite(T.voisin_droite), posX(T.posX),posY(T.posY),
contenance(9) {

    // Impossible d'initialiser contenance avec T.getSize()
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


//
//
//ostream& operator<<(ostream& f, const Tuile& T){
//
//    f << &T << endl << endl;
//
//    for (int i = 0; i < 3 ; i++ ) {
//
//        f << i << " : " << TypesTuiles_str[T.getContenu(i)];
//        if (T.getContenu(i) == 2 && T.getContenance(i).getBouclier() ) { f << " (Bouclier)";}
//        f << '\t';
//    }
//    f << endl;
//
//    f << 7 << " : " << TypesTuiles_str[T.getContenu(7)];
//    if (T.getContenu(7) == 2 && T.getContenance(7).getBouclier() ) { f << " (Bouclier)";}
//    f << '\t';
//
//    f << 8 << " : " << TypesTuiles_str[T.getContenu(8)];
//    if (T.getContenu(8) == 2 && T.getContenance(8).getBouclier() ) { f << " (Bouclier)";}
//    f << '\t';
//
//    f << 3 << " : " << TypesTuiles_str[T.getContenu(3)];
//    if (T.getContenu(3) == 2 && T.getContenance(3).getBouclier() ) { f << " (Bouclier)";}
//    f << '\t';
//
//    f<< endl;
//
//    f << 6 << " : " << TypesTuiles_str[T.getContenu(6)];
//    if (T.getContenu(6) == 2 && T.getContenance(6).getBouclier() ) { f << " (Bouclier)";}
//    f << '\t';
//
//    f << 5 << " : " << TypesTuiles_str[T.getContenu(5)];
//    if (T.getContenu(5) == 2 && T.getContenance(5).getBouclier() ) { f << " (Bouclier)";}
//    f << '\t';
//
//    f << 4 << " : " << TypesTuiles_str[T.getContenu(4)];
//    if (T.getContenu(4) == 2 && T.getContenance(4).getBouclier() ) { f << " (Bouclier)";}
//    f << '\t';
//
//    return f;
//}


ostream& operator<<(ostream& f, const Tuile& T){

    f << &T << endl << endl;
    vector<int> ordre = {0, 1, 2, 7, 8, 3, 6, 5, 4};

    for (auto i : ordre) {

        if (i == 7 || i == 6) { cout << endl;}

        cout << i << " : " << TypesTuiles_str[T.getContenu(i)];

        if (T.getContenu(i) == 2 && T.getContenance(i).getBouclier()) {
            f << " (Bouclier)" << "\t";
        }

        else {
            f << "   \t\t\t";
        }
    }

    f << endl;

    return f;
}


ostream& operator<<(ostream& f, const ContenanceTuile& c){

    f << " Contenance Tuile" << endl;
    f << " Type : "<< TypesTuiles_str[c.getType()] << endl;  // Taoufiq add this
    f << " Position : " << c.getNumPlacement() << endl;

    return f;
}
