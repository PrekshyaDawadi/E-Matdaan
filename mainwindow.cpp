#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->FirstName->setPlaceholderText("Enter your First name");
    ui->LastName->setPlaceholderText("Enter your Last name");
    ui->UserName->setPlaceholderText("Enter your user name");
    ui->Password->setPlaceholderText("Enter your Password");
    ui->RollNumber->setPlaceholderText("Enter your Roll Number");
    ui->LoginUsername->setPlaceholderText("Enter your username");
    ui->LoginPassword->setPlaceholderText("Enter your password");


    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/prekshya/Documents/projects/E-Matdaan/studentInformation.sqlite");

    if(!db.open()){
        QMessageBox::information(this, "Connectivity", "Database not connected.");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(db.isOpen()){

        // Take inputs from each field
        QString FirstName =ui->FirstName->text();
        QString LastName =ui->LastName->text();
        QString RollNumber =ui->RollNumber->text();
        QString UserName =ui->UserName->text();
        QString Password =ui->Password->text();

        // Insert into the database

        QSqlQuery qry;
        qry.prepare("INSERT INTO BasicInformation (RollNumber, FirstName, LastName, UserName, Password)\
                    VALUES (:RollNumber, :FirstName, :LastName, :UserName, :Password);");

        qry.bindValue(":RollNumber", RollNumber);
        qry.bindValue(":FirstName", FirstName);
        qry.bindValue(":LastName", LastName);
        qry.bindValue(":UserName", UserName);
        qry.bindValue(":Password", Password);

        qry.exec();

        QMessageBox::information(this, "Successful!", "Your account was successfully created!");

    }else{
        QMessageBox::information(this,"Not Connected", "Connection establish failed");
    }
    //db.close();
    //QSqlDatabase::removeDatabase("StudentInformation");
}


void MainWindow::on_pushButton_3_clicked()
{
        QString username, password;
        username = ui->LoginUsername->text();
        password = ui->LoginPassword->text();

        if(!db.isOpen()){
            QString message = "Failed to open database - mainwindow.cpp.";
            QMessageBox::information(this, "Failed", message);
        }

        QSqlQuery qry;

//        qry.prepare(
//           "select * from BasicInformation where UserName= :username and Password= :password"
//        );
//        qry.bindValue(":UserName",  username);
//        qry.bindValue(":Password", password);

        if(qry.exec("select * from BasicInformation where UserName = '"+username+"' and Password = '"+password+"'")){
        int count = 0;
        while (qry.next()){
            count++;
        }
        if(count==1){
            //QMessageBox::information(this, "Info", "Username and password is correct.");
            this->hide();
            dashboard dash;
            dash.setModal(true);
            dash.exec();
        }
        if(count>1){
            QMessageBox::information(this, "Info", "Duplicate Username and password.");
            exit(0);
        }
        if(count<1){
            QMessageBox::information(this, "Info", "Username and password is not correct.");
            exit(0);
        }
        }
}
