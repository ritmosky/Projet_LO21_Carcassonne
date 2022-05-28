#ifndef VUEPARTIE_H
#define VUEPARTIE_H

#include <QMainWindow>
#include "vueTuile.h"
#include "../modele/controller.h"


namespace Ui {
class VuePartie;
}

class VuePartie : public QMainWindow
{
    Q_OBJECT

public:
    explicit VuePartie(Controller* c, QWidget *parent = nullptr);
    ~VuePartie();
    void setAffichageScore();
    void setAffichageTuile();
    void setJoueurActu();

private:
    Ui::VuePartie *ui;
    Controller* controller;


};

#endif // VUEPARTIE_H
