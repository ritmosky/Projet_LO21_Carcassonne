#ifndef VUEOUPLACERMEEPLE_H
#define VUEOUPLACERMEEPLE_H

#include <QDialog>
#include "vuePartie.h"
#include "modele/tuile.h"
#include <QAbstractButton>



namespace Ui {
class vueOuPlacerMeeple;
}

class vueOuPlacerMeeple : public QDialog
{
    Q_OBJECT

public:
    explicit vueOuPlacerMeeple(int l,int c, QWidget *parent = nullptr, VuePartie* part = nullptr, Tuile* t = nullptr,Controller *con=nullptr);
    ~vueOuPlacerMeeple();
    void setTuile(Tuile&);

private slots:
    void on_c0_clicked();
    void on_c1_clicked();
    void on_c2_clicked();
    void on_c3_clicked();
    void on_c4_clicked();
    void on_c5_clicked();
    void on_c6_clicked();
    void on_c7_clicked();
    void on_c8_clicked();

private:
    Ui::vueOuPlacerMeeple *ui;
    VuePartie* partie;
    int Nligne;
    int Ncol;
    Tuile* tuile;
    Controller *controller;
};

#endif // VUEOUPLACERMEEPLE_H
