#include <QApplication>
#include "vue/vueAccueil.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    VueAccueil w;
    w.show();

    return app.exec();

}
