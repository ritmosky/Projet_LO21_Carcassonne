
#ifndef joueur_h
#define joueur_h


#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include "meeple.h"



class Joueur {

private:

    int id;
    int score;
    int nbrMeeples;
    string name;
    vector<const Meeple*> meeples;

public:

    Joueur(int uid, int nb, string str) : id(uid), nbrMeeples(nb), score(0), name(str), meeples(NULL) {}
    Joueur(int uid) : id(uid){}

    inline const int getId() const { return id; }
    inline const int getScore() const { return score; }
    inline const size_t getNbrMeeplesUsed() const { return meeples.size(); }
    inline const int getNbrMeeples() const { return nbrMeeples; }
    inline const string getName() const { return name; }
    inline const vector<const Meeple*> getMeeples() const { return meeples; }

    inline void addScore(int pts) { score += pts; }
    void addMeeple(const Meeple& m);
    void addName(const string& str);
    void removeMeeple(){nbrMeeples--;}
    void addnbrMeeple(){nbrMeeples++;}
        void setNbMeeple(int i){
        nbrMeeples = i;
    }
};


ostream& operator<<(ostream& f, const Joueur& J);


#endif
