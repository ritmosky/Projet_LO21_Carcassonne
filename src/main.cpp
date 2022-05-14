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

    VueContenuTuile testContenuTuile(nullptr, 5);


    testContenuTuile.show();

    return app.exec();

}
