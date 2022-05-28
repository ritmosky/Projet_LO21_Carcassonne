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
    explicit VueScore1Joueur(std::string nomJ, QWidget *parent = nullptr);
    ~VueScore1Joueur();

private:
    Ui::VueScore1Joueur *ui;
    std::string nom;

private slots:

    void on_ajouterPoints_clicked();
    void on_retirerPoints_clicked();
};

#endif // VUESCORE1JOUEUR_H
