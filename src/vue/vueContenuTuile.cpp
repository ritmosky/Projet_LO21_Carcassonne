#include "vueContenuTuile.h"
#include "ui_vueContenuTuile.h"

VueContenuTuile::VueContenuTuile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VueContenuTuile)
{
    ui->setupUi(this);
}

VueContenuTuile::~VueContenuTuile()
{
    delete ui;
}
