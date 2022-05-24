//
//  Pioche.h
//  Caracassonne
//
//  Created by Massil on 13/05/2022.
//

#ifndef Pioche_h
#define Pioche_h

#include <stdio.h>
#include "Tuiles.h"

#endif /* Pioche_h */


class Pioche {

private :
    vector<Tuile> tuiles;

public :
    Pioche(vector<int> mode);

    inline const Tuile& getTuile(int i) const {return  tuiles[i];}
    inline size_t getNbTuiles() const {return size(tuiles);}

    const Tuile& piocher();
    bool estVide() const {return tuiles.size() == 0;}

    Pioche(const Pioche&)= delete;
    Pioche& operator=(const Pioche&)= delete;
    inline bool getBouclier(ContenanceTuile& c) { return c.bouclier; };


};

ostream& operator<<(ostream& f, const Pioche& T);

