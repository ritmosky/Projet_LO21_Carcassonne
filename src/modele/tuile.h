#ifndef Tuiles_h
#define Tuiles_h

#include <stdio.h>


// Definition enum TypesTuiles
enum TypesTuiles {
    route,
    abbaye,
    ville,
    champs
};



// Convertir Enum en String
static const char* TypesTuiles_str[] = { "Route", "Abbaye", "Ville", "Champs" };


class ContenanceTuile{

private :
    int numPlacement;
    TypesTuiles type;

public:
    ContenanceTuile(const TypesTuiles t, const int n): type(t), numPlacement(n){;}


};

class Tuile {

private:
    Tuile* voisin_haut;
    Tuile* voisin_bas;
    Tuile* voisin_gauche;
    Tuile* voisin_droite;
    int posX;
    int posY;
    ContenanceTuile* contenance;


public :
    Tuile(const ContenanceTuile* c);
    const int& getX() const {return posX;}
    const int& getY() const {return posY;}





};

#endif /* Tuiles_h */