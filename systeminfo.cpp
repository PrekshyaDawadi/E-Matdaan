#include "systeminfo.h"
#include "ui_systeminfo.h"

systeminfo::systeminfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::systeminfo)
{
    ui->setupUi(this);
}

systeminfo::~systeminfo()
{
    delete ui;
}
