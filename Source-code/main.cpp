#include "mainwindow.h"
#include "dashboard.h"
#include "ballot.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QtSql>
#include <QtDebug>
#include <QMessageBox>
#include <QString>

// To do:
// 1. Do have a look at databases locking themselves, because this database definitely has that problem and
// that may crash the whole thing.
// 2. Have a look at duplicate connection thingy because the connections are all over the place and
// it's slowing down the addition and retrieval of data from the databases.
// 3. Document the code.
// 4. Make the database "cloud-based"(?), because here, you will have to have the whole table to
// make the application work.

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
{

    QSqlDatabase  db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/prekshya/Documents/projects/E-Matdaan/Source-code/E-MatdaanDatabase.sqlite");

    if(!db.open()){
        QMessageBox msg;
        QMessageBox::information(&msg, "Connectivity", "Database not connected.");
    }
    }

    MainWindow w;
    w.show();

    //db.close();
    //QSqlDatabase::removeDatabase("StudentInformation");

    return a.exec();
}
