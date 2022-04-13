#include "dashboard.h"
#include "ui_dashboard.h"

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

}
