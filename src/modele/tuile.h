
#ifndef tuile_h
#define tuile_h


#include <stdio.h>
#include <vector>
#include<string>
#include<iostream>


using namespace std;


// Definition enum TypesTuiles
enum TypesTuiles {
    route,
    abbaye,
    ville,
    champs,
    rivière,
    auberge,
    cathédrale,
    jardin,
    droute
};



// Convertir Enum en String
static const char* TypesTuiles_str[] = { "Route", "Abbaye", "Ville", "Champs", "Rivière", "Auberge", "Cathédrale", "Jardin", "DoubleRoute" };



class ContenanceTuile{

private :

    friend class Pioche;
    friend class Tuile;


    int numPlacement;
    TypesTuiles type;
    bool bouclier;

public:

    ContenanceTuile(const TypesTuiles t, const int n): type(t), numPlacement(n), bouclier(false) {}
    ContenanceTuile() = default;

    inline const TypesTuiles& getType() const {return type;}
    inline const int getNumPlacement() const {return numPlacement;}
    const bool getBouclier() const { return bouclier; }
    void setBouclier();
        void setType(const TypesTuiles t){
        type = t;
    }

    inline bool operator==(const ContenanceTuile& c) const {return this->type == c.getType(); };
    ContenanceTuile(const ContenanceTuile& c):numPlacement(c.numPlacement), type(c.type), bouclier(c.bouclier) {}
    ContenanceTuile& operator=(const ContenanceTuile& c);

};



class Tuile {

private:

    Tuile* voisin_haut;
    Tuile* voisin_bas;
    Tuile* voisin_gauche;
    Tuile* voisin_droite;
    int posX;
    int posY;
    vector<ContenanceTuile> contenance;


public :

    Tuile(const vector<ContenanceTuile>& c);
    Tuile() = default;

    inline const size_t getSize() const {return contenance.size();}
    inline const int getX() const {return posX;}
    inline const int getY() const {return posY;}
    inline const Tuile* getVoisinHaut() const {return voisin_haut;}
    inline const Tuile* getVoisinBas() const {return voisin_bas;}
    inline const Tuile* getVoisinGauche() const {return voisin_gauche;}
    inline const Tuile* getVoisinDroite() const {return voisin_droite;}

    const vector<ContenanceTuile> getContenance() const {return contenance; }
    const ContenanceTuile& getContenance(int i) const {return contenance[i]; }
    const ContenanceTuile* getContenancePointeur(int i) const {return &contenance[i]; }
    ContenanceTuile* getContenancePointeur(int i) {return &contenance[i]; }
    const TypesTuiles& getContenu(int i) const { return contenance[i].getType() ; }
    void changerOrientation();

    Tuile(const Tuile& T);
    Tuile& operator=(const Tuile& T);
    bool operator==(const Tuile& T) const{return this->getContenance() == T.getContenance();}
    
        void setContenu(int i, TypesTuiles c){
        contenance[i].setType(c);
    }
    
        void ReplaceParChamps(){
        for (int i = 0; i < 9; i++){
            if((getContenu(i) == TypesTuiles::auberge) || (getContenu(i)==TypesTuiles::jardin)){
                setContenu(i, TypesTuiles::champs);
            }
        }
    }

    void setVoisinHaut(Tuile* t){
        voisin_haut = t;
    }
    void setVoisinBas(Tuile* t){
        voisin_bas = t;
    }
    void setVoisinGauche(Tuile* t){
        voisin_gauche = t;
    }
    void setVoisinDroite(Tuile* t){
        voisin_droite = t;
    }
    void setPosX(int x){
        this->posX = x;
    }
    void setPosY(int y){
        posY = y;
    }

        //setter x et y
    void setX(int x){
        posX = x;
    }
    void setY(int y){
        posY = y;
    }

};


ostream& operator<<(ostream& f, const Tuile& T);
ostream& operator<<(ostream& f, const ContenanceTuile& T);


#endif /* tuile_h */

