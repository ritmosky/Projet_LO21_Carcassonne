#ifndef VUETUILE_H
#define VUETUILE_H

#include <QWidget>
#include "../modele/tuile.h"
#include <vector>
#include "vueContenuTuile.h"


namespace Ui {
class VueTuile;
}

class VueTuile : public QWidget
{
    Q_OBJECT

public:
    explicit VueTuile(Tuile* tuile ,QWidget *parent = nullptr);
    explicit VueTuile(Tuile* tuile, int p, QWidget *parent = nullptr);
    ~VueTuile();
    void setContenuTuile(Tuile& tuile);
    void addMeeple(Tuile* tuile, int p,int id);
    inline vector<VueContenuTuile*>& getVueContenuT() {return tabContenuTuile;}

private:
    Ui::VueTuile *ui;
    vector<VueContenuTuile*> tabContenuTuile;
};

#endif // VUETUILE_H
