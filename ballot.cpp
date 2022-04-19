#include "ballot.h"
#include "ui_ballot.h"


int count1 = 0, count2 = 0, count3 = 0;


ballot::ballot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ballot)
{
    ui->setupUi(this);

    db = QSqlDatabase::database("qt_sql_default_connection");

    if(!db.open()){
        QMessageBox::information(this, "Connectivity", "Database not connected.");
    }

    else{
        QSqlQuery qry(db);
        qry.exec("select Name from candidatesInformation where Department = '"+depart+"';");
        int i= 0;
        while(qry.next() == true){
            QSqlRecord rec = qry.record();
            int nameCol = rec.indexOf("Name"); // index of the field "name"
            QString name = qry.value(nameCol).toString();
            if(i == 0){
             ui->candidate1->setText(name);
            }else if(i==1){
            ui->candidate2->setText(name);
            }else{
            ui->candidate3->setText(name);
            }
            i++;
            //qry.next();
        }
    }

}

ballot::~ballot()
{
    delete ui;
}


void ballot::on_pushButton_clicked()
{

    if(!db.open())
      qWarning() << "ERROR: " << db.lastError();

    else{

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
        }

        QMessageBox::information(this, "Success!", "Voting successful!");


    }

    //db.close();
    //QSqlDatabase::removeDatabase("StudentInformation");

    this->hide();
    dashboard d;
    d.setModal(true);
    d.exec();


}
