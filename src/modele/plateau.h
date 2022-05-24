#ifndef PROJET_LO21_CARCASSONNE_PLATEAU_H
#define PROJET_LO21_CARCASSONNE_PLATEAU_H
#include<vector>
#include <iostream>
#include "tuile.h"


class Plateau{
private:
    std::vector<Tuile*> tuiles;
    int nbrEspaces;
    int nbrTuiles;

public:
    Plateau(int nbT) : tuiles(nbT), nbrTuiles(nbT){;}
    int getNbrTuiles() const{return nbrTuiles;}
    void setNbrTuiles(const int &nbrT) {this->nbrTuiles = nbrT;}
    void ajouterTuiles(Tuile* tuile);
    std::vector<Tuile*> getTuiles() const{return tuiles;}
    Tuile* existeTuile(int x,int y){
        for(Tuile* tuile : tuiles){
            if(tuile->getX() == x && tuile->getY() == y){
                return tuile;
            }
        }
        return NULL;
    }
};
#endif //PROJET_LO21_CARCASSONNE_PLATEAU_H