#ifndef _CONTROLLER_H
#define _CONTROLLER_H
#include <iostream>
#include <string>


enum State {
    GAME_MENU, GAME_START, PLACING_TILE, PLACING_MEEPLE, GAME_OVER;
}

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
        Joueur** joueur;
        ModeJeu modeJeu[5];
        Plateau* plateau;
        Pioche* pioche;
        int nbJoueur;
        State state;
        int tour;

    public:

        //Constructeur
        Controller();
        //Destructeur
        ~Controller();

        //On interdit l'opérateur d'affectation et le constructeur de recopie
        Controller(const Controller&) = delete;
        Controller& operator=(const Controller&) = delete ;

        void debut();
        void fin();
        void debutTour();
        void finTour();
        void placementTuile(Tuile t);
        void placementMeeple(Meeple m);
        void setState(State s); 

        //Getters
        inline bool getFini() const{
            return this->fini;
        }

        inline int getNbJoueur() const{
            return this->nbJoueur;
        }

        inline State getState() const{
            return this->state;
        }

        inline int getTour() const{
            return this->tour;
        }
}

#endif