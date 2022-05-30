#ifndef _CONTROLLER_H
#define _CONTROLLER_H
#include <iostream>
#include <string>
#include <vector>
#include "pioche.h"
#include "joueur.h"
#include "plateau.h"
#include "tuile.h"
#include "meeple.h"
#include "modeJeu.h"

enum State {
    GAME_MENU,GAME_START, PLACING_TILE, PLACING_MEEPLE, GAME_OVER
};

/*  GAME_START -> permet d'initialiser le plateau,la pioche de tuile, et de lancer la partie, avec la vue Qt du plateau
    PLACING_TILE -> permet de placer une tuile sur le plateau
    PLACING_MEEPLE -> permet de placer un meeple sur le plateau
    GAME_OVER -> permet de terminer la partie et de compter les scores finaux
*/


using namespace std;

class Controller{

    private:

        bool fini;
        vector<Joueur*> listeJoueurs;
        vector<int> extensions;
        ModeJeu* modeJeu[5];
        Plateau *plateau;
        Pioche *pioche;
        State state;
        int tour;
        int nbJoueurs;

    public:
        //Constructeur
        Controller(int nj);
        Controller(int nj,vector<string> listeNomJoueur,vector<int> listeNumExtensions);
        //Destructeur
        ~Controller();
        Controller(const Controller&) = delete;
        Controller& operator=(const Controller&) = delete ;


        //permet de placer la tuile sur le plateau
        void placementTuile(Tuile *newTuile,int x,int y);
        //permet de placer un meeple sur un contenu de tuile
        void placementMeeple(Joueur* j,Meeple* m,TypeMeeple tm,int i,int x,int y);
        // Vérifie si la tuile donnée serait autorisée n'importe où sur le plateau adjacent aux autres tuiles
        bool placementTuileAutorise(Tuile newTuile);
        //Vérifie si la tuile donnée peut être placée à la position x, y sur le plateau
        bool estCompatible(Tuile newTuile,int x,int y);
        void setState(State s); 
       // void compteScore(State s);
       // void compteScore(TypesTuiles t, State s);
        void nextTour();
        //void compteScoreAbbaye(State s);
        void AffichageJoueurs(){
            for(int i=0;i<listeJoueurs.size();i++){
                cout << "Joueur " << i << " : " << listeJoueurs.at(i)->getNbrMeeples() << " meeples" << endl;
            }
        }

        vector<Joueur*> getJoueurs(){
            return listeJoueurs;
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
    
    //Fonction test
    bool placementTuileAutorise(Tuile newTuile,Plateau* plateau);
    bool estCompatible(Tuile newTuile,int x,int y,Plateau *plateau);
    bool validationPlacementRiviere(Tuile newTuile,int x,int y,Plateau *plateau);
    void placementMeeple(Joueur* j,Meeple* m,TypeMeeple tm,int i,int x,int y,Plateau *plateau);
    void placementTuile(Tuile *newTuile,int x,int y,Plateau *plateau);
};

#endif
