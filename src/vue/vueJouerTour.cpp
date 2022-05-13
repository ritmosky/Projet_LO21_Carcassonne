#include "vueJouerTour.h"
#include "ui_vueJouerTour.h"

VueJouerTour::VueJouerTour(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VueJouerTour)
{
    ui->setupUi(this);
}

VueJouerTour::~VueJouerTour()
{
    delete ui;
}
