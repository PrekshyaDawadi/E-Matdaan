#include "mainwindow.h"
#include "dashboard.h"
#include "ballot.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QtSql>
#include <QtDebug>
#include <QMessageBox>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/prekshya/Documents/projects/E-Matdaan/studentInformation.sqlite");

    if(!db.open()){
        QMessageBox msg;
        QMessageBox::information(&msg, "Connectivity", "Database not connected.");
    }

    MainWindow w;
    w.show();


    return a.exec();
}
