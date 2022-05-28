#ifndef VUEFORMNOM_H
#define VUEFORMNOM_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QFormLayout>
#include <vector>
using namespace std;


namespace Ui {
class VueFormNom;
}

class VueFormNom : public QMainWindow
{
    Q_OBJECT

public:
    explicit VueFormNom(int& nJoueur, vector<int> listeNumExt,QWidget *parent = nullptr);
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
    vector<int> listeNumE;

};


#endif // VUEFORMNOM_H
