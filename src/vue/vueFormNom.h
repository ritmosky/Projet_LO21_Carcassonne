#ifndef VUEFORMNOM_H
#define VUEFORMNOM_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QFormLayout>

namespace Ui {
class VueFormNom;
}

class VueFormNom : public QMainWindow
{
    Q_OBJECT

public:
    explicit VueFormNom(int& nJoueur, QWidget *parent = nullptr);
    ~VueFormNom();
    int getNbrJoueur()const{return this->nbrJoueur;}


private slots:
    void on_pushButton_2_clicked();

private:
    Ui::VueFormNom *ui;
    QWidget* m_window;
    int nbrJoueur;
    QList<QLineEdit*> m_listLineEdit;
    QList<QLabel*> m_listLabel;
    QLabel* L_prenom;
    QLineEdit* m_prenom;

};


#endif // VUEFORMNOM_H
