#include <QApplication>
#include "vue/vueAccueil.h"
#include "vue/vueFormNom.h"
#include "vue/vuePartie.h"
#include "vue/vuePlateau.h"
#include "vue/vueContenuTuile.h"
#include "vue/vueTuile.h"
#include "vue/vueScore1Joueur.h"
#include "modele/tuile.h"
#include "modele/controller.h"
#include <iostream>
#include <string>


int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    VueAccueil w;
    w.show();

    return app.exec();

}
