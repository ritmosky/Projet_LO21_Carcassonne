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
    void setPlateau();
    void placerTuile(const int Nligne,const int NCol, const Tuile* tuile);

private slots:
    void on_zoomIn_clicked();

    void on_zoomOut_clicked();

    void on_bouttonValiderTuile_clicked();

private:
    Ui::VuePartie *ui;
    Controller* controller;


};

#endif // VUEPARTIE_H
