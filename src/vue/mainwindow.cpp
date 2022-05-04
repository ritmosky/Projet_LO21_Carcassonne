#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("CARCASSONNE");
    setFixedSize(600,300);


    QPixmap bkgnd("C:/Users/TavernyK.000/OneDrive/Bureau/Documents/Projet4/R");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);



    this->m_NBjoueur = new QLabel("Nombre de joueur", this);
    m_NBjoueur->setGeometry(50, 50,120, 25);
    m_NBjoueur->setStyleSheet("QLabel { background-color : black; color : white; }");


    this->NBjoueurLayout = new QFormLayout;
    NBjoueurLayout->addRow( "Nom du premier :" ,m_NBjoueur);

    this->L_NBjoueur = new QLineEdit("",this);
    L_NBjoueur->setGeometry(220, 50,50, 25);

    this->m_extention = new QLabel("Choisir l'extention", this);
    m_extention->setGeometry(50, 100,120, 25);
    m_extention->setStyleSheet("QLabel { background-color : black; color : white; }");

    this->L_extention = new QLineEdit("", this);
    L_extention->setGeometry(220, 100,50, 25);

    this->Choix_Extention = new QLabel("Taper : 1) Classique   2) Les paysans   3) l'Abbé   4) La rivière   5) Auberges et carthédrales", this);
    Choix_Extention->setGeometry(15, 150,555, 25);
    Choix_Extention->setStyleSheet("QLabel { background-color : white; color : black; }");


    this->m_Next = new QPushButton("Next", this);
    m_Next->setGeometry(500, 260,81, 25);
    QObject::connect(m_Next, SIGNAL(clicked()), this, SLOT(next()));


    this-> m_Quit = new QPushButton("Quit", this);
    m_Quit->setGeometry(50, 260,81, 25);
    QObject::connect(m_Quit, SIGNAL(clicked()), this, SLOT(exit()));

}

int MainWindow::IntNBjoueur(){

    QString contenu = L_NBjoueur->text();
    bool ok;
    this->resultat_ = contenu.toInt(&ok,10);
    return resultat_;
}


NameWindow::NameWindow():QMainWindow()

{
    setWindowTitle("CARCASSONNE");
    setFixedSize(800,800);

    m_window = new QWidget(this);

    m_vLayout = new QVBoxLayout(this);
    m_window->setLayout(m_vLayout);


    for (int i=1; i <= 6 ;i++)
    {

    QLabel *L_prenom = new QLabel("Nom joueur n° " ,m_window);
    this->m_listLabel.append(L_prenom);
    QString str ="";
    str = QString::number(i);
    L_prenom->setText("Nom joueur n° "+ str);
    m_vLayout->addWidget(L_prenom);
    L_prenom->move(50,i*30);

    QLineEdit *m_prenom= new QLineEdit("",m_window);
    this->m_listLineEdit.append(m_prenom);
    m_vLayout->addWidget(m_prenom);
    m_prenom->move(100,i*30);

    QFormLayout *formLayout1 = new QFormLayout;

    QVBoxLayout *layout1= new QVBoxLayout;
    layout1->addLayout(formLayout1);

    }
    QPushButton* commencer = new QPushButton("Commencer",m_window);
    commencer->move(0,0);


    setCentralWidget(m_window);

}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::next(){
    NameWindow *window = new NameWindow();
    window->show();

}

void MainWindow::exit()
{
close();
qApp->quit();
}
