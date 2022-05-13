#include <QApplication>
#include "vue/vueAccueil.h"
#include "vue/vuePartie.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    //VueAccueil w;
//    w.show();

    VuePartie partie;

    partie.show();

    return app.exec();

}
