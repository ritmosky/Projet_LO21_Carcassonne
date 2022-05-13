#ifndef VUESCORE1JOUEUR_H
#define VUESCORE1JOUEUR_H

#include <QWidget>

namespace Ui {
class VueScore1Joueur;
}

class VueScore1Joueur : public QWidget
{
    Q_OBJECT

public:
    explicit VueScore1Joueur(QWidget *parent = nullptr);
    ~VueScore1Joueur();

private:
    Ui::VueScore1Joueur *ui;
};

#endif // VUESCORE1JOUEUR_H
