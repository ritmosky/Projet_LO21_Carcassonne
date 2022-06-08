#ifndef VUEOURETIRERMEEPLE_H
#define VUEOURETIRERMEEPLE_H

#include <QDialog>
#include "vuePartie.h"
#include "modele/tuile.h"
#include <QAbstractButton>



namespace Ui {
class VueOuRetirerMeeple;
}


class VueOuRetirerMeeple : public QDialog
{
    Q_OBJECT

public:
    explicit VueOuRetirerMeeple(VuePartie* partie=nullptr,QWidget *parent=nullptr);
    ~VueOuRetirerMeeple();

    int containMeeple(VueTuile& vt);
    void setTuile(Tuile& tuile,VueTuile& vt);

private slots:
    void on_OK_clicked();

private:
    Ui::VueOuRetirerMeeple *ui;
    VuePartie* partie;
};

#endif // VUEOURETIRERMEEPLE_H
