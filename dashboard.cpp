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
        //QString winner;
//        if(depart == "Computer Science"){

//            std::cout<<"Entered Computer Science"<<std::endl;
//        }else if(depart == "Computer Engineering"){
//            winner = winnerCE;
//            std::cout<<"Entered Computer Engineering"<<std::endl;
//        }else{
//            std::cout<<"Didnot enter depart if-statement. "<<std::endl;
//        }
        qry.exec("select Winner from Results where Department = '"+depart+"' and Batch = '"+bat+"';");
//            QSqlQuery qry;
//            qry.exec("SELECT Name FROM ROW_NUMBER(1) AS 'name' FROM candidatesInformation");
//            QMessageBox::information(this, "Results", "The winner for this round of CR selection is '"+name+"'");
            QString candidate1, candidate2, candidate3;
            while(qry.next() == true){
                QSqlRecord rec = qry.record();
                int nameCol = rec.indexOf("Winner"); // index of the field "name"
                QString name = qry.value(nameCol).toString();
                QMessageBox::information(this, "Results", "The winner for this round of CR selection is '"+name+"'");
            }
}
