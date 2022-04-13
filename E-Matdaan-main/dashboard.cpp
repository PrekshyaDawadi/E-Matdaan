#include "dashboard.h"
#include "ui_dashboard.h"
#include"candidateinfo.h"
#include"help.h"
#include"logout.h"

dashboard::dashboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dashboard)
{
    ui->setupUi(this);
}

dashboard::~dashboard()
{
    delete ui;
}

void dashboard::on_pushButton_4_clicked()
{
  this->hide();
  ballot b;
  b.setModal(true);
  b.exec();
}

void dashboard::on_pushButton_clicked()
{
    this->hide();
    candidateinfo c;
    c.setModal(true);
    c.exec();
}


void dashboard::on_pushButton_3_clicked()
{
    this->hide();
    help d;
    d.setModal(true);
    d.exec();
}


void dashboard::on_pushButton_5_clicked()
{
   this->close();
   }

