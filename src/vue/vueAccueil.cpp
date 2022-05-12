#include "vueAccueil.h"
#include "ui_mainwindow.h"
#include "vueFormNom.h"


VueAccueil::VueAccueil(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Création de la page d'accueil (NB de joueur, choix de l'extention)

    setWindowTitle("CARCASSONNE");
    setFixedSize(600,300);

    // photo de fond d'écran (mettre l'adresse de l'image)

    QPixmap bkgnd("/Users/ambroisethibault/Documents/LO21/projet/Projet_LO21_Carcassonne/src/ressources/images/image_accueil.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    // NB de joueur, création label

    this->m_NBjoueur = new QLabel("Nombre de joueur", this);
    m_NBjoueur->setGeometry(50, 50,120, 25);
    m_NBjoueur->setStyleSheet("QLabel { background-color : black; color : white; }");


    this->NBjoueurLayout = new QFormLayout;
    NBjoueurLayout->addRow( "" ,m_NBjoueur);

    this->L_NBjoueur = new QLineEdit("",this);
    L_NBjoueur->setGeometry(220, 50,50, 25);


    // choix de l'extention

    this->m_extention = new QLabel("Choisir l'extention", this);
    m_extention->setGeometry(50, 100,120, 25);
    m_extention->setStyleSheet("QLabel { background-color : black; color : white; }");

    this->L_extention = new QLineEdit("", this);
    L_extention->setGeometry(220, 100,50, 25);

    this->Choix_Extention = new QLabel("Taper : 1) Classique   2) Les paysans   3) l'Abbé   4) La rivière   5) Auberges et carthédrales", this);
    Choix_Extention->setGeometry(15, 150,555, 25);
    Choix_Extention->setStyleSheet("QLabel { background-color : white; color : black; }");


    // bouton next et son action
    this->m_Next = new QPushButton("Next", this);
    m_Next->setGeometry(500, 260,81, 25);
    QObject::connect(m_Next, SIGNAL(clicked()), this, SLOT(next()));

    //buton QUIT et son action
    this-> m_Quit = new QPushButton("Quit", this);
    m_Quit->setGeometry(50, 260,81, 25);
    QObject::connect(m_Quit, SIGNAL(clicked()), this, SLOT(exit()));

}

// Fonction pour transformer les caractères récupérés dans le lineEdit de nbjoueur en int.
int VueAccueil::IntNBjoueur(){

    QString contenu = L_NBjoueur->text();
    bool ok;
    this->resultat_ = contenu.toInt(&ok,10);
    return resultat_;
}



VueAccueil::~VueAccueil()
{
    delete ui;
}

//action du buton next.
void VueAccueil::next(){
    VueFormNom *window = new VueFormNom();
    window->show();

}

//action du buton quit.
void VueAccueil::exit()
{
close();
qApp->quit();
}
