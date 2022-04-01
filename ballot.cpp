#include "ballot.h"
#include "ui_ballot.h"


int count1 = 0, count2 = 0, count3 = 0;


ballot::ballot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ballot)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/prekshya/Documents/projects/E-Matdaan/studentInformation.sqlite");

    if(!db.open()){
        QMessageBox::information(this, "Connectivity", "Database not connected.");
    }

}

ballot::~ballot()
{
    delete ui;
}


void ballot::on_pushButton_clicked()
{

    if (db.isOpen()){

        QSqlQuery qry; 
        if(ui->candidate1->isChecked()){
            count1++;
            qry.prepare("INSERT INTO VoteCount (Candidate1, Candidate2, Candidate3) VALUES (:count1, :count2, :count3);");
            qry.bindValue(":count1", count1);
            qry.bindValue(":count2", count2);
            qry.bindValue(":count3", count3);

            qry.exec();

            //QMessageBox::information(this, "Success!", "If condition 1 entered.");
        } else if(ui->candidate2->isChecked()){
            count2++;
            qry.prepare("INSERT INTO VoteCount (Candidate1, Candidate2, Candidate3) VALUES (:count1, :count2, :count3);");
            qry.bindValue(":count1", count1);
            qry.bindValue(":count2", count2);
            qry.bindValue(":count3", count3);

            qry.exec();

            //QMessageBox::information(this, "Success!", "If condition 2 entered.");
        }else if(ui->candidate3->isChecked()){
            qry.prepare("INSERT INTO VoteCount (Candidate1, Candidate2, Candidate3) VALUES (:count1, :count2, :count3);");
            qry.bindValue(":count1", count1);
            qry.bindValue(":count2", count2);
            qry.bindValue(":count3", count3);

            qry.exec();

            //QMessageBox::information(this, "Success!", "If condition 3 entered.");
        }else{
            return;
        }

        QMessageBox::information(this, "Success!", "Voting successful!");


    }else{
        QMessageBox::information(this, "Error!", "Database not connected!");
    }
    this->hide();
    dashboard d;
    d.setModal(true);
    d.exec();
}
