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
    QString TableName;
    if(db.isOpen()){

        // Take inputs from each field
        QString FirstName =ui->FirstName->text();
        QString LastName =ui->LastName->text();
        QString RollNumber =ui->RollNumber->text();
        QString UserName =ui->UserName->text();
        QString Password =ui->Password->text();
        QString Batch =ui->Batch->text();

        //rollnumber = rollnumber.toInt();
        //batch = batch.toInt();

        if(ui->Department->currentText() == "Computer Science"){
            TableName = "ComputerScience";
            QMessageBox::information(this, "Programmer Info","Table name set to computer science");
        }else{
            TableName = "ComputerEngineering";
            QMessageBox::information(this, "Programmer Info","Table name set to computer engineering");
        }

        // Check and Insert into the database

        QSqlQuery qry;
        // int rows = 0;

        // Run some query
//        qry.exec("SELECT * FROM TableName");

//        while(qry.next())
//            rows++;

//        int count = 0;

//        while(count <= rows){

//            QSqlQuery roll.exec("SELECT RollNumber FROM TableName;");
//            QSqlQuery first.exec("SELECT FirstName FROM TableName;");
//            QSqlQuery last.exec("SELECT LastName FROM TableName;");
//            QSqlQuery batch.exec("SELECT Batch FROM TableName;");

            //if("FirstName == first.value(count);" and "LastName == last.value(count)==LastName;" and "RollNumber == roll.value(count);" and "Batch == batch.value(count);"){

            if(qry.exec("select * from '"+TableName+"' where FirstName == '"+FirstName+"' and LastName == '"+LastName+"' and RollNumber == '"+RollNumber+"' and Batch == '"+Batch+"'")){
                QMessageBox::information(this, "programmer info", "Entered '"+TableName+"' loop.");
                int count = 0;
                while (qry.next() == true){
                    count++;
                    QMessageBox::information(this, "programmer info", "Entered qry.next() loop.");

                }

                if(!qry.next())
                   {
                         qDebug() << qry.lastError();
                   }
                   else
                   {
                        qDebug() << "Success!";
                        QMessageBox::information(this, "programmer info", "qry.next() returned true.");

                   }

                if(count==1){
                    //QSqlQuery query;
                    //RollNumber = RollNumber.toInt();
                    //Batch = Batch.toInt();
                    qry.prepare("INSERT INTO BasicInformation (RollNumber, FirstName, LastName, UserName, Password, Batch)\
                        VALUES (:RollNumber, :FirstName, :LastName, :UserName, :Password, :Batch);");

                    qry.bindValue(":RollNumber", RollNumber);
                    qry.bindValue(":FirstName", FirstName);
                    qry.bindValue(":LastName", LastName);
                    qry.bindValue(":UserName", UserName);
                    qry.bindValue(":Password", Password);
                    qry.bindValue(":Batch", Batch);

                    qry.exec();
                    QMessageBox::information(this, "Successful!", "Your account was successfully created!");
                }
                if(count>1){
                    QMessageBox::information(this, "Info", "Duplicate Records found.");
                    exit(0);
                }
                if(count==0){
                    QMessageBox::information(this, "Info", "No records found.");
                    exit(0);
                }

        }
        else{
           QMessageBox::information(this, "Failed!", "Your data doesnot match our records!");
        }

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

        if(qry.exec("select * from BasicInformation where UserName == '"+username+"' and Password == '"+password+"'")){
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

void MainWindow::on_pushButton_4_clicked()
{
    this->hide();
    admin ad;
    ad.setModal(true);
    ad.exec();
}
