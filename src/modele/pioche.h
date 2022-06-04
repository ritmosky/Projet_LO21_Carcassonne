
#ifndef pioche_h
#define pioche_h


#include <stdio.h>
#include "tuile.h"



class Pioche {

private :

    vector<Tuile> tuiles;

public :

    Pioche(vector<int> mode);

    inline const Tuile& getTuile(int i) const {return tuiles[i];}
    inline size_t getNbTuiles() const {return tuiles.size();}

    Tuile* piocher(int nbTour, bool riviereActive);
    bool estVide() const {return tuiles.size() == 0;}

    Pioche(const Pioche&)= delete;
    Pioche& operator=(const Pioche&)= delete;
    inline bool getBouclier(ContenanceTuile& c) { return c.bouclier; };
    
    
};


ostream& operator<<(ostream& f, const Pioche& T);


#endif
