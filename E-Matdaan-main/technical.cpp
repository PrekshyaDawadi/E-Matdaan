#include "technical.h"
#include "ui_technical.h"

technical::technical(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::technical)
{
    ui->setupUi(this);
}

technical::~technical()
{
    delete ui;
}
