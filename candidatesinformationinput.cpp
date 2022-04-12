#include "candidatesinformationinput.h"
#include "ui_candidatesinformationinput.h"


CandidatesInformationInput::CandidatesInformationInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CandidatesInformationInput)
{

    ui->setupUi(this);
}

CandidatesInformationInput::~CandidatesInformationInput()
{
    delete ui;
}

void CandidatesInformationInput::on_pushButton_2_clicked()
{
    exit(0);
}

void CandidatesInformationInput::on_pushButton_clicked()
{

    {
        QSqlDatabase  db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("/home/prekshya/Documents/projects/E-Matdaan/studentInformation.sqlite");
        //QString candidate1Name, candidate2Name, candidate3Name;
        QString candidateName[3];
        //QString candidate2Department, candidate3Department, candidate1Department;
        QString candidateDepartment[3];
        //QString candidate2RollNumber, candidate3RollNumber, candidate1RollNumber;
        QString candidateRollNumber[3];
        //QString candidate2Batch, candidate3Batch, candidate1Batch;
        QString candidateBatch[3];
        //    int candidate2Batch, candidate3Batch, candidate1Batch;
        //    int candidate2RollNumber, candidate3RollNumber, candidate1RollNumber;

        candidateName[0] = ui->candidate1Name->text();
        candidateName[1] = ui->candidate2Name->text();
        candidateName[2] = ui->candidate3Name->text();

        candidateRollNumber[0] = ui->candidate1RollNumber->text();
        candidateRollNumber[1] = ui->candidate2RollNumber->text();
        candidateRollNumber[2] = ui->candidate3RollNumber->text();

        candidateDepartment[0] = ui->candidate1Department->text();
        candidateDepartment[1] = ui->candidate2Department->text();
        candidateDepartment[2] = ui->candidate3Department->text();

        candidateBatch[0] = ui->candidate1Batch->text();
        candidateBatch[1] = ui->candidate2Batch->text();
        candidateBatch[2] = ui->candidate3Batch->text();

        for(int i=0; i<3; i++){
            QString Roll = candidateRollNumber[i];
            QString Name = candidateName[i];
            QString Department = TableName;
            QString Batch = candidateBatch[i];

            QSqlQuery qry(db);
            if(!db.open())
                qWarning() << "ERROR: " << db.lastError();

            else{
                qry.prepare("INSERT INTO candidatesInformation (Roll, Name, Department, Batch)\
                            VALUES (:Roll, :Name, :Department, :Batch);");

                qry.bindValue(":Roll", Roll);
                qry.bindValue(":Name", Name);
                qry.bindValue(":Batch", Batch);
                qry.bindValue(":Department", Department);

                qry.exec();
                if(!qry.exec()){
                    qWarning() << "ERROR: " << db.lastError();
                }
            }
        }
    }
    //db.close();
   // QSqlDatabase::removeDatabase("StudentInformation");

}
