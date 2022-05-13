#include "vueTuile.h"
#include "ui_vueTuile.h"

VueTuile::VueTuile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VueTuile)
{
    ui->setupUi(this);
}

VueTuile::~VueTuile()
{
    delete ui;
}
