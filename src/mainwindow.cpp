#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("CARCASSONNE");
    setFixedSize(500,300);


    QPixmap bkgnd("C:/Users/TavernyK.000/OneDrive/Bureau/Documents/Projet4/R");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);



    this->m_NBjoueur = new QLabel("Nombre de joueur", this);
    m_NBjoueur->setGeometry(50, 50,120, 25);
    m_NBjoueur->setStyleSheet("QLabel { background-color : white; color : black; }");


    //this->NBjoueurLayout = new QFormLayout;
    //NBjoueurLayout->addRow( "Nom du premier :" ,m_NBjoueur);

    this->L_NBjoueur = new QLineEdit("",this);
    L_NBjoueur->setGeometry(220, 50,50, 25);

    this->m_extention = new QLabel("Choisir l'extention", this);
    m_extention->setGeometry(50, 100,150, 25);
    m_extention->setStyleSheet("QLabel { background-color : white; color : black; }");

    this->L_extention = new QLineEdit("", this);
    L_extention->setGeometry(220, 100,50, 25);

    this->Choix_Extention = new QLabel("Taper : 1)-Classique   2)-la princesse et le Dragon   3)...", this);
    Choix_Extention->setGeometry(50, 150,400, 25);
    Choix_Extention->setStyleSheet("QLabel { background-color : white; color : black; }");


    this->m_Next = new QPushButton("Next", this);
    m_Next->setGeometry(370, 260,81, 25);

    QObject::connect(m_Next, SIGNAL(clicked()), this, SLOT(next()));


    this-> m_Quit = new QPushButton("Quit", this);
    m_Quit->setGeometry(50, 260,81, 25);
    QObject::connect(m_Quit, SIGNAL(clicked()), this, SLOT(exit()));

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::next(){
    NewWindow();

}

void MainWindow::NewWindow()

{
    ui->setupUi(this);

    QWidget *Plateau =new QWidget;

    Plateau->setWindowTitle("CARCASSONNE");
    Plateau->setFixedSize(500,300);

    QPixmap bkgnd("C:/Users/TavernyK.000/OneDrive/Bureau/Documents/Projet4/R");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);



    Plateau->show();
}

void MainWindow::exit()
{
close();
qApp->quit();
}
