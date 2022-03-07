#include "mandatoryfieldgroup.h"
#include "ui_mandatoryfieldgroup.h"

MandatoryFieldGroup::MandatoryFieldGroup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MandatoryFieldGroup)
{
    ui->setupUi(this);
}

MandatoryFieldGroup::~MandatoryFieldGroup()
{
    delete ui;
}
