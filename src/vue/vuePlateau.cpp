#include "vuePlateau.h"
#include "ui_vuePlateau.h"
#include <QTableWidget>>

VuePlateau::VuePlateau(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VuePlateau)
{
    ui->setupUi(this);
    setTable();
}

void VuePlateau::setTable(){
    ui->tableWidget->setCurrentCell(72,72);
}

VuePlateau::~VuePlateau()
{
    delete ui;
}
