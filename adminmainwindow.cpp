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
