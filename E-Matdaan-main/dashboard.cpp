#include "dashboard.h"
#include "ui_dashboard.h"
#include"candidateinfo.h"
#include"help.h"
#include"logout.h"
#include "adminmainwindow.h"
#include "candidatesinformationinput.h"
#include <iostream>

//QString winnerCS, winnerCE;

dashboard::dashboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dashboard)
{
    ui->setupUi(this);
    db = QSqlDatabase::database("qt_sql_default_connection");
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


void dashboard::on_pushButton_2_clicked()
{
    QSqlQuery qry(db);
    QString batch = QString::number(bat); // converting int to string

    // Got the QSqlError("","","") here. I have noticed I get this bug generally when I try to
    // select a value from data base and in the condition I keep any datatype other than string as a constain.

    qry.exec("SELECT Winner FROM Results WHERE Department = '"+depart+"' AND Batch = '"+batch+"'");
    QString name;
    while(qry.next()){
        QSqlRecord rec = qry.record();
        int nameCol = rec.indexOf("Winner");// index of the field "name"
        name = qry.value(nameCol).toString();
        qDebug() << name;

    }
    QMessageBox::information(nullptr, "Title",
                             QString("The winner of this round of CR elections is: %1")
                             .arg(name));
    if(!qry.next()){
        qDebug()<<"Error while selecting data from results table. next -> "<<qry.lastError().text();
    }
    if(!qry.exec()){
        qDebug()<<"Error while selecting data from results table.  exec-> "<<qry.lastError();
    }
}
