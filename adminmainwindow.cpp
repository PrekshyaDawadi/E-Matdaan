#include "adminmainwindow.h"
#include "ui_adminmainwindow.h"

adminMainWindow::adminMainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminMainWindow)
{
    ui->setupUi(this);
}

adminMainWindow::~adminMainWindow()
{
    delete ui;
}

void adminMainWindow::on_pushButton_clicked()
{
    //Signup Request review.
    // Delete this button
        this->hide();

}

void adminMainWindow::on_pushButton_3_clicked()
{
    this->hide();
    CandidatesInformationInput amw;
    amw.setModal(true);
    amw.exec();
}
