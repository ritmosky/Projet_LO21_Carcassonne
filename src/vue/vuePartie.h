#ifndef VUEPARTIE_H
#define VUEPARTIE_H

#include <QMainWindow>
#include "vueTuile.h"

namespace Ui {
class VuePartie;
}

class VuePartie : public QMainWindow
{
    Q_OBJECT

public:
    explicit VuePartie(Tuile& tuilePlace, QWidget *parent = nullptr);
    ~VuePartie();
    void setAffichageScore();
    void setAffichageTuile(Tuile& tuilePlace);

private:
    Ui::VuePartie *ui;
    Tuile& tuilePlace;
};

#endif // VUEPARTIE_H
