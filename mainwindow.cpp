#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>


QString TableName;
QString selectedCandidates;
QString depart;




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
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    db = QSqlDatabase::database("qt_sql_default_connection");

    if(!db.open()){
        QMessageBox::information(this, "Connectivity", "Database not connected.");
    }

    if(db.isOpen()){

        // Take inputs from each field
        QString FirstName =ui->FirstName->text();
        QString LastName =ui->LastName->text();
        QString RollNumber =ui->RollNumber->text();
        QString UserName =ui->UserName->text();
        QString Password =ui->Password->text();
        QString Batch =ui->Batch->text();
        QString Department = ui->Department->currentText();

        if(ui->Department->currentText() == "Computer Science"){
            TableName = "ComputerScience";
            //QString Department = "cs";
            selectedCandidates = "selectedComputerScience";
            //QMessageBox::information(this, "Programmer Info","Table name set to computer science");
        }else{
            TableName = "ComputerEngineering";
            //QString Department = "ce";
            selectedCandidates = "selectedComputerEngineering";
            //QMessageBox::information(this, "Programmer Info","Table name set to computer engineering");
        }

        // Check and Insert into the database
        {
            QSqlQuery qry;

            if(qry.exec("select * from '"+TableName+"' where FirstName == '"+FirstName+"' and LastName == '"+LastName+"' and RollNumber == '"+RollNumber+"' and Batch == '"+Batch+"'")){
                //QMessageBox::information(this, "programmer info", "Entered '"+TableName+"' loop.");
                int count = 0;
                while (qry.next() == true){
                    count++;
                    //QString scount = QString::number(count);
                    //QMessageBox::information(this, "programmer info", "Value of count: '"+scount+"'");

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
                    qry.prepare("INSERT INTO BasicInformation (RollNumber, FirstName, LastName, UserName, Password, Batch, Department)\
                                VALUES (:RollNumber, :FirstName, :LastName, :UserName, :Password, :Batch, :Department);");

                            qry.bindValue(":RollNumber", RollNumber);
                    qry.bindValue(":FirstName", FirstName);
                    qry.bindValue(":LastName", LastName);
                    qry.bindValue(":UserName", UserName);
                    qry.bindValue(":Password", Password);
                    qry.bindValue(":Batch", Batch);
                    qry.bindValue(":Department", Department);

                    qry.exec();

                    if(!qry.exec())
                    {
                        qDebug() << qry.lastError();
                    }
                    else
                    {
                        qDebug() << "Success!";
                        QMessageBox::information(this, "programmer info", "qry.exec() returned true.");

                    }

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

        }
    }else{
        QMessageBox::information(this,"Not Connected", "Connection establish failed");
    }
}




void MainWindow::on_pushButton_3_clicked()
{
    QString username, password;
    username = ui->LoginUsername->text();
    password = ui->LoginPassword->text();
    QSqlQuery qry;

    if(qry.exec("select * from BasicInformation where UserName == '"+username+"' and Password == '"+password+"'")){
        int count = 0;
        while (qry.next()){
            count++;
        }
        if(count==1){

            qry.exec("select Department from BasicInformation where UserName == '"+username+"' and Password == '"+password+"'");
            //depart = qry.boundValue(1).toString();
            QSqlRecord rec = qry.record();
            int nameCol = rec.indexOf("Department"); // index of the field "name"
            qry.next();
            depart = qry.value(nameCol).toString();

            // qDebug() << depart;

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
