#include "vuePlateau.h"
#include "ui_vuePlateau.h"

VuePlateau::VuePlateau(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VuePlateau)
{
    ui->setupUi(this);
}

VuePlateau::~VuePlateau()
{
    delete ui;
}
