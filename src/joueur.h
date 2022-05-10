
#ifndef _JOUEUR_H
#define _JOUEUR_H 


#include <stdio.h>
#include <meeple.h>



class Joueur {
	
	private:

		int id;
		int score = 0;
		int nbrMeeples;
		Meeple** meeples;

	public:

		Joueur(int un_id, int un_nb_meeples) : id(un_id), nbrMeeples(un_nb_meeples), meeples(nullptr) {}
		~Joueur();

		Joueur(const Joueur&) = delete;
		Joueur& operator=(const Joueur&) = delete;

		inline int getId() { return id;}
		inline int getScore() { return score;}

};



#endif
