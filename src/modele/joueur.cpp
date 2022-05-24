
#include "joueur.h"
#include <iostream>




void Joueur::addMeeple(const Meeple& m) {

    if (meeples.size() > nbrMeeples){
        cout << "Il y\'a trop de meeples";
    }

    meeples.push_back(&m);
}


void Joueur::addName(const string& str){
    name = str;
}



ostream& operator<<(ostream& f, const Joueur& J){

    f << "--------------------------------------------------------\n";

    f << "\n Joueur ID : " << J.getId() << " nom : " << J.getName();
    f << "\n Score : " << J.getScore();
    f << "\n Nombre de meeples autorisé : " << J.getNbrMeeples();
    f << "\n Nombre de meeples utilisé : " << J.getNbrMeeplesUsed();

    for(int i =0; i< J.getMeeples().size(); i++){
        cout << "\n\t - adresse meeple " << i+1 << " : " << J.getMeeples()[i];
    }

    f << "\n\n--------------------------------------------------------\n\n";

    return f;
 }

