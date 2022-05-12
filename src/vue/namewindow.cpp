#include "nameWindow.h"


NameWindow::NameWindow():QMainWindow()

{
    // Création de la fenêtre de NOM des joueur
    // Titre et taille de la fenêtre fixé.

    setWindowTitle("CARCASSONNE");
    setFixedSize(800,800);

    n_window = new QWidget(this);

    m_vLayout = new QVBoxLayout(this);
    n_window->setLayout(m_vLayout);

    //int nbJoueur = IntNBjoueur();
    for (int i=1; i <= 6 ;i++)
    {
        //Création des espaces de label et des lineEdit pour les noms dans la fenêtre en fonction du nombre de joueur "i".


        QLabel *L_prenom = new QLabel("Nom joueur n° " ,n_window);
        this->m_listLabel.append(L_prenom);
        QString str ="";
        str = QString::number(i);
        L_prenom->setText("Nom joueur n° "+ str);
        m_vLayout->addWidget(L_prenom);
        L_prenom->move(50,i*30);

        QLineEdit *m_prenom= new QLineEdit("",n_window);
        this->m_listLineEdit.append(m_prenom);
        m_vLayout->addWidget(m_prenom);
        m_prenom->move(100,i*30);

        QFormLayout *formLayout1 = new QFormLayout;

        QVBoxLayout *layout1= new QVBoxLayout;
        layout1->addLayout(formLayout1);

    }
    // le boutton "COMMENCER" pour afficher la fenêtre de jeu.
    this-> m_commencer = new QPushButton("Commencer",n_window);
    QObject::connect(m_commencer, SIGNAL(clicked()), this, SLOT(commencer()));
    m_commencer->move(0,0);


    setCentralWidget(n_window);

}

NameWindow::~NameWindow()
{
}

//action du button commencer.
void NameWindow::commencer(){
    /*
    VuePartie *window = new VuePartie();
    window->show();
    */
}
