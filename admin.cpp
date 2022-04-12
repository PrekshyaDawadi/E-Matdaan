#include "admin.h"
#include "ui_admin.h"
#include "candidateinformation.h"

admin::admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin)
    //db(db)
{
    ui->setupUi(this);
}

admin::~admin()
{
    delete ui;
}

void admin::on_pushButton_clicked()
{
    this->hide();
    adminMainWindow amw;
    amw.setModal(true);
    amw.exec();
}
