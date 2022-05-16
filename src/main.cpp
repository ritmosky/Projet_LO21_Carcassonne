#include <QApplication>
#include "vue/vueAccueil.h"
#include "vue/vuePartie.h"
#include "vue/vueContenuTuile.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

//    VueAccueil w;
//    w.show();


//    VuePartie partie;
//    partie.show();

    VueContenuTuile testContenuTuile(2, 1);


    testContenuTuile.show();

    return app.exec();

}
