#include "signup.h"
#include "ui_signup.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QFont>
#include<QColorDialog>
#include<QColor>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSql>
#include <QMainWindow>
#include <iostream>

Signup::Signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Signup)
{
    ui->setupUi(this);
}

Signup::~Signup()
{
    delete ui;
}

void Signup::on_SignupOK_clicked()
{
    // open the database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/prekshya/Documents/projects/E-matdaan/StudentInfo");

    if(db.open()){

        // Take inputs from each field
        QString Name =ui->lineEdit_Name->text();
        QString RollNumber =ui->lineEdit_RollNumber->text();
        QString Department =ui->lineEdit_Department->text();
        QString Batch =ui->lineEdit_Batch->text();
        QString Password =ui->lineEdit_Password->text();

        // Insert into the database

        QSqlQuery qry;
        qry.prepare("INSERT INTO BasicInformation (RollNumber, Name, Department, Batch, Password)"
                    "VALUES (:RollNumber, :Name, :Department, :Batch, :Password)");

        qry.bindValue(":RollNumber", RollNumber);
        qry.bindValue(":Name", Name);
        qry.bindValue(":Department", Department);
        qry.bindValue(":Batch", Batch);
        qry.bindValue(":Password", Password);

    }else{
        QMessageBox::information(this,"Not Connected", "Connection establish failed");
    }
    db.close();
    QSqlDatabase::removeDatabase("StudentInformation");

    QMessageBox::information(this,"Successful","Your records were entered! You will get an email after the admin reviews your request.");


}
