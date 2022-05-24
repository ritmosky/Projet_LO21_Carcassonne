#include "vueformnom.h"
#include "ui_VueFormNom.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"

int MainWindow::IntNBjoueur(){

    QString contenu = ui->lineEdit->text();
    bool ok;
    this->resultat_ = contenu.toInt(&ok,3);
    return resultat_;
}

VueFormNom::VueFormNom(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VueFormNom)
{

    ui->setupUi(this);

    ui->m_vLayout = new QVBoxLayout;

    for (int i=1; i <= 6 ; i++){

        // création ds espaces de label et des LineEdit pour les noms dans la fenêtre en fonction du nombre de joueur "i"
        ui->L_prenom = new QLabel("Nom joueur n° ",this);
        this->m_listLabel.append(ui->L_prenom);
        QString str ="";
        str = QString::number(i);
        ui->L_prenom->setText("Nom joueur n° "+str);
        ui->m_vLayout->addWidget(ui->L_prenom);
        ui->L_prenom->move(50,i*30);


        ui->m_prenom = new QLineEdit("",this);
        this->m_listLineEdit.append(ui->m_prenom);
        ui->m_vLayout->addWidget(ui->m_prenom);
        ui->m_prenom->move(200, i*30);

        QFormLayout *formLayout1 = new QFormLayout;

        QVBoxLayout *layout1 = new QVBoxLayout;
        layout1->addLayout(formLayout1);


    }



}

VueFormNom::~VueFormNom(){
    delete ui;
}

void VueFormNom::on_pushButton_2_clicked()
{

}
