#ifndef VUETUILE_H
#define VUETUILE_H

#include <QWidget>
#include "../modele/tuile.h"
#include <vector>
#include "vueContenuTuile.h"


#include "vueContenuTuile.h"
#include "../modele/tuile.h"
#include "ui_vueTuile.h"
namespace Ui {
class VueTuile;
}

class VueTuile : public QWidget
{
    Q_OBJECT

public:
    explicit VueTuile(Tuile tuile ,QWidget *parent = nullptr);
    ~VueTuile();
    void setContenuTuile(Tuile& tuile);

private:
    Ui::VueTuile *ui;
    vector<VueContenuTuile*> tabContenuTuile;


//    delete tabContenuTuile[indideCase];
    // Créer ton ContenuTuile avec le nouveau constructeur
//    add ce nouveau contenuTuile dans tabContenuTuile[indiceCase]
};

#endif // VUETUILE_H
