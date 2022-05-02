#include <QWidget>
#include <QLabel>
#include <QProgressBar>
#include <QLCDNumber>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

#include "vuepartie.h"
#include "vuecarte.h"


VuePartie::VuePartie(QWidget *parent) : QWidget(parent), vuecartes(20) {

    // Initialisation des QLabels
    this->pioche = new QLabel("Pioche");
    this->score = new QLabel("Score");

    // Initialisation de la barre de progression
    this->nbCartesPioche = new QProgressBar;
    // TODO Paramétrage

    // Initialisation du QLCDNumber
    this->scoreJoueur = new QLCDNumber;
    // TODO paramétrage

    // Initialisation des Layouts
    this->layoutInformations = new QHBoxLayout;
    this->layoutCartes = new QGridLayout;
    this->couche = new QVBoxLayout;

    this->couche->addLayout(this->layoutInformations);
    this->couche->addLayout(this->layoutCartes);
    this->setLayout(this->couche);


    // Création des vues de cartes (vuecartes[]) et affectation au layoutCartes
    for(size_t i = 0; i < 20; i++) {
        // Création de l'objet VueCarte dans vuecartes[i]
        vuecartes[i] = new VueCarte;
        // Ajout de la vuecarte nouvellement créée au layoutCartes (grid)
        layoutCartes->addWidget(vuecartes[i], i/4, i%4);
        // TODO Connexion du signal de la VueCarte au private slot carteClique
        connect(vuecartes[i], SIGNAL(carteClicked(VueCarte*)),
                this, SLOT(carteClique(VueCarte*)));
    }

    // Initialisation du jeu via le Controleur
    this->controleur.distribuer();

    // Affectation des cartes du plateau au layout de grid
    // Pour récupérer les cartes du plateau, on doit passer par l'iterator
    size_t i = 0;
    for(auto it = this->controleur.getPlateau().begin();
        it != this->controleur.getPlateau().end(); ++it) {

        vuecartes[i]->setCarte(*it);
        i++;
    }

}


void VuePartie::carteClique(VueCarte* vc) {
    // TODO QUESTION 2
    return;
}






