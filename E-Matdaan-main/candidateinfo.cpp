#include "candidateinfo.h"
#include "ui_candidateinfo.h"

candidateinfo::candidateinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::candidateinfo)
{
    ui->setupUi(this);
}

candidateinfo::~candidateinfo()
{
    delete ui;
}
