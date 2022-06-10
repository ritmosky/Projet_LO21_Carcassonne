#ifndef PROJET_LO21_CARCASSONNE_PLATEAU_H
#define PROJET_LO21_CARCASSONNE_PLATEAU_H
#include<vector>
#include <iostream>
#include "tuile.h"
#include "espace.h"


class Plateau{
private:
    std::vector<Tuile*> tuiles;
    std::vector<Espace*> espaces;
    int nbrEspaces;
    int nbrTuiles;

public:
    Plateau(int nbT) : tuiles(nbT), nbrTuiles(nbT){;}
    Plateau() = default;
    ~Plateau();
    int getNbrTuiles() const{return nbrTuiles;}
    int getNbrEspaces() const{return nbrEspaces;}
    void setNbrTuiles(const int &nbrT) {this->nbrTuiles = nbrT;}
    void ajouterTuiles(Tuile* tuile);
    void ajouterEspace(Espace* espace);
    void supprimerEspace(Espace* espace);
    std::vector<Tuile*> getTuiles() const{return tuiles;}
    std::vector<Espace*> getEspaces() const {return espaces;}
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
