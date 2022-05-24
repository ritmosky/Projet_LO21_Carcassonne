#ifndef joueur_h
#define joueur_h 


#include <stdio.h>
#include <iostream>
#include <vector>
#include "meeple.h"



class Joueur {
	
	private:

		int id;
		int score;
		int nbrMeeples;
		vector<const Meeple*> meeples;

	public:

		Joueur(int uid, int nb) : id(uid), nbrMeeples(nb), score(0){}
		Joueur(int uid) : id(uid){}
		//~Joueur();

		inline const int getId() const { return id; }
		inline const int getScore() const { return score; }
		inline const size_t getNbrMeeplesUsed() const { return meeples.size(); }
        inline const int getNbrMeeples() const { return nbrMeeples; }
        inline const vector<const Meeple*> getMeeples() const { return meeples; }
    
		inline void addScore(int pts) { score += pts; }
		void addMeeple(const Meeple& m);
		void removeMeeple(){
			nbrMeeples--;
		}
};


ostream& operator<<(ostream& f, const Joueur& J);


#endif