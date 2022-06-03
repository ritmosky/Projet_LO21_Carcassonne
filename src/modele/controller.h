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



using namespace std;

class Controller{

    private:

        bool fini;
        vector<Joueur*> listeJoueurs;
        vector<int> extensions;
        ModeJeu* modeJeu[5];
        Plateau *plateau;
        Pioche *pioche;
        int tour;
        int nbJoueurs;
        int numJoueurActu; // Va de 0 à nbrJoueur - 1

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


        inline int getTour() const{
            return this->tour;
        }

         inline Pioche* getPioche() const{return this->pioche;}


         inline int getNumJoueurActu() const{return this->numJoueurActu;}
        inline Plateau* getPlateau() const{
            return this->plateau;
        }
    
            inline vector<int> getExtensions() const{
            return this->extensions;
        }

        //retourner le modedejeu
        inline ModeJeu* getModeJeu(int i) const{
            return this->modeJeu[i];
        }

    //Fonction test
    bool placementTuileAutorise(Tuile newTuile,Plateau* plateau);
    bool estCompatible(Tuile newTuile,int x,int y,Plateau *plateau);
    bool validationPlacementRiviere(Tuile newTuile,int x,int y,Plateau *plateau);
    void placementMeeple(Joueur* j,Meeple* m,TypeMeeple tm,int i,int x,int y,Plateau *plateau);
    void placementTuile(Tuile *newTuile,int x,int y,Plateau *plateau);
};

#endif
