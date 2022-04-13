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

        this->hide();
//        reviewrequest r;
//        r.show();
//      QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//      db.setDatabaseName("C:\Users\Dell\Desktop\E-Matdaan-main (1)\E-Matdaan-main\studentInformation.sqlite");

//      if (!db.open())
//      {
//        QMessageBox::information(this, "Connectivity", "DB is connected.");
//      }

//      QSqlTableModel *model = new QSqlTableModel(this,db);
//      model->setTable("SigninRequest");
//      model->setEditStrategy(QSqlTableModel::OnManualSubmit);
//      model->select();
//      model->setHeaderData(0, Qt::Horizontal, tr("First-name"));
//      model->setHeaderData(1, Qt::Horizontal, tr("Last-name"));

//      ui->tableView->setModel(model);
//      ui->tableView->show();
}
