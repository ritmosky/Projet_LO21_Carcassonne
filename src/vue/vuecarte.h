#ifndef VUECARTE_H
#define VUECARTE_H

#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPushButton>
#include "../modele/set.h"

class VueCarte : public QPushButton
{
    Q_OBJECT
public:
    VueCarte(const Set::Carte& c, QWidget *parent = nullptr); // Constructeur pour afficher une carte existante
    explicit VueCarte(QWidget *parent = nullptr); // Constructeur pour objet vueCarte associé à aucune carte
    // affecter une nouvelle carte à la vue
    void setCarte(const Set::Carte& c) { setCheckable(true); setChecked(false); carte=&c; update(); }
    // vue sans carte
    void setNoCarte() { carte=nullptr; setCheckable(false); update(); }
    const Set::Carte& getCarte() const { return *carte; }
    bool cartePresente() const { return carte!=nullptr; }
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    const Set::Carte* carte=nullptr;
    QPen pen;
    QBrush brush;
signals:
    // quand la vude de carte est cliquée, elle émet un signal en transmettant son adresse
    void carteClicked(VueCarte*);
public slots:
private slots:
    void clickedEvent() { emit carteClicked(this); }
};

#endif // VUECARTE_H
