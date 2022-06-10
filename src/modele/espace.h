

#ifndef espace_h
#define espace_h

#include <stdio.h>
#include "meeple.h"
#include <vector>


class Espace {

    friend class Controller;
    
private :

    TypesTuiles type;
    int nbrBouclier;
    int nbrMeeple;
    vector<const ContenanceTuile*> contenus;
    vector<const Meeple*> meeples;

public :

    Espace(const TypesTuiles& Tt): nbrBouclier(0), nbrMeeple(0), type(Tt){}
    

    inline const int getNbrMeeple() const { return nbrMeeple; }
    inline const int getNbrBouclier() const { return nbrBouclier; }
    inline const TypesTuiles& getType() const { return type; }
    inline const vector<const ContenanceTuile*> getContenus() const { return contenus; }
    inline const ContenanceTuile* getContenus(int i) const { return contenus[i]; }
    inline const vector<const Meeple*> getMeeples() const { return meeples; }
    inline const Meeple* getMeeples(int i) const { return meeples[i]; }
    inline const size_t getNbrContenanceTuile() const { return contenus.size(); }

    inline void addBouclier() { nbrBouclier += 1; }
    void addContenance(const ContenanceTuile* C);
    void addMeeple(const Meeple* M);
    
    Espace* fusionEspace(Espace* e);

    bool isComplete();
    inline const bool isFree() const {return meeples.size() == 0;}
    void calculScore();
};


ostream& operator<<(ostream& f, const Espace& E);


#endif
