#include <QApplication>
#include "vue/vueAccueil.h"
#include "vue/vueFormNom.h"
#include "vue/vuePartie.h"
#include "vue/vueContenuTuile.h"
#include "vue/vueTuile.h"
#include "vue/vueScore1Joueur.h"
#include "modele/tuile.h"
#include "modele/controller.h"
#include <iostream>


int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

//    VueAccueil w;
//    w.show();

//    VueFormNom test;
//    test.show();
    //    VueContenuTuile testContenuTuile(ville);
    //    testContenuTuile.show();

//         Test pour un objet tuile
//        vector<ContenanceTuile> c(9);
//        c[0] = ContenanceTuile(auberge,0);  c[1] = ContenanceTuile(champs,1);  c[2] = ContenanceTuile(ville,2);
//        c[7] = ContenanceTuile(rivière,7);   c[8] = ContenanceTuile(abbaye, 8); c[3]= ContenanceTuile(champs,3);
//        c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(auberge,4);

//        Tuile T(c);
//        VueTuile testTuile(T);

//        testTuile.show();

   Controller* controllerPartie = new Controller(3);

   VuePartie* partie = new VuePartie(controllerPartie);
//  VuePartie partie(controllerPartie);
   partie->show();



    return app.exec();

}
