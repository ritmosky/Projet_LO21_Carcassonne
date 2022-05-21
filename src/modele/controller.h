#ifndef _CONTROLLER_H
#define _CONTROLLER_H
#include <iostream>
#include <string>
#include <vector>
#include "pioche.h"
#include "joueur.h"
#include "plateau.h"
#include "tuile.h"

enum State {
    GAME_MENU, GAME_START, PLACING_TILE, PLACING_MEEPLE, GAME_OVER
};

/*  GAME_MENU -> permet de choisir le mode de jeu, et d'initiliser la liste des joueurs
    GAME_START -> permet d'initialiser le plateau,la pioche de tuile, et de lancer la partie, avec la vue Qt du plateau
    PLACING_TILE -> permet de placer une tuile sur le plateau
    PLACING_MEEPLE -> permet de placer un meeple sur le plateau
    GAME_OVER -> permet de terminer la partie et de compter les scores finaux
*/


using namespace std;

class Controller{

    private:

        bool fini;
        vector<Joueur*> listeJoueurs;
        //ModeJeu* modeJeu;
        Plateau *plateau;
        Pioche *pioche;
        State state;
        int tour;
        int nbJoueurs;

    public:

        //Constructeur
        Controller(int nj);
        //Destructeur
        ~Controller();

        //On interdit l'opérateur d'affectation et le constructeur de recopie
        Controller(const Controller&) = delete;
        Controller& operator=(const Controller&) = delete ;

        bool placementTuileAutorise(Tuile newTuile);
        bool placementTuileAutorise(Tuile newTuile,Plateau* plateau);
        bool estCompatible(Tuile newTuile,int x,int y,Plateau *plateau);
        bool estCompatible(Tuile newTuile,int x,int y);
        bool placementMeeple(Meeple m);
        void setState(State s); 
        void compteScore(State s);
        void compteScore(TypesTuiles t, State s);
        void nextTour();
        void compteScoreAbbaye(State s);
        void AffichageJoueurs(){
            for(int i=0;i<listeJoueurs.size();i++){
                cout << "Joueur " << i << " : " << listeJoueurs.at(i)->getNbrMeeples() << " meeples" << endl;
            }
        }

        //Getters
        inline bool getFini() const{
            return this->fini;
        }

        inline int getNbJoueur() const{
            return this->nbJoueurs;
        }

        inline State getState() const{
            return this->state;
        }

        inline int getTour() const{
            return this->tour;
        }

};

#endif