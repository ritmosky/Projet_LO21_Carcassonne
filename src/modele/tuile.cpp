#include "tuile.h"
#include <vector>


void ContenanceTuile::setBouclier(){
    if (type == ville) {bouclier = true ;}
    else {throw "Impossible : ce n'est pas une ville";}
}


Tuile::Tuile(const vector<ContenanceTuile>& c): voisin_haut(nullptr),voisin_bas(nullptr),voisin_gauche(nullptr),voisin_droite(nullptr),contenance(c.size()){
    for ( size_t i = 0; i < c.size(); i++){
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




ostream& operator<<(ostream& f, const Tuile& T){


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