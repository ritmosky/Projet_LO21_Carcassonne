
#ifndef _MEEPLE_H
#define _MEEPLE_H 


#include <stdio.h>
#include <tuile.h>
#include <nomMeeple.h>




// Definition enum NomMeeple
enum NomMeeple { 
	chevalier, 
	paysan, 
	abbe, 
	voleur
};


// Convertir Enum en String 
static const char* NomMeeple_str[] = { "Chevalier", "Paysan", "Abbe", "Voleur" };



// CLASSE MÈRE
class TypeMeeple {
	
	private:

		NomMeeple nom;

	public:

		TypeMeeple(NomMeeple& un_nom) : nom(un_nom) {}  // constructeur
		~TypeMeeple() = default;

		TypeMeeple(const TypeMeeple&) = delete;
		TypeMeeple& operator=(const TypeMeeple&) = delete;

		// idonnePoint();
		// contraintePlacement();
};



// CLASSE FILLE
class Meeple : public TypeMeeple {
	
	private:

		Tuile* tuile;
		TypeMeeple type;
		int positionSurT;
		Joueur* joueur;

	public:

		Meeple(Tuile& t, TypeMeeple& un_type, int pos, Joueur& j) : tuile(t), type(un_type), positionSurT(pos), joueur(j) {}
		~Meeple();
		
		Meeple(const Meeple&) = delete;
		Meeple& operator=(const Meeple&) = delete;

		inline bool isUsed() { return tuile == nullptr;}
		inline int getPosition() { return positionSurT;}
};



#endif

