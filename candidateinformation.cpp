#include "candidateinformation.h"
#include "ui_candidateinformation.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <iostream>

CandidateInformation::CandidateInformation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CandidateInformation)
{
    ui->setupUi(this);
    // first create connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/prekshya/Documents/projects/E-Matdaan/studentInformation.sqlite");


    QSqlQuery statement("SELECT Name FROM CandidateInformation",db);
    QSqlRecord record = statement.record();

    std::cout << record.count() <<std::endl;
    while(statement.next()) {
        auto name = statement.value(record.indexOf("Name")).toString();
    }

}

CandidateInformation::~CandidateInformation()
{
    delete ui;
}

void CandidateInformation::on_pushButton_clicked()
{
    // TODO:
    // delete from SelectedCandidates;
    //QSqlQuery qry;
    //qry.prepare("SELECT * FROM ");

    // insert into SelectedCandidates (1, "text1"), (2,"text2"), (3, "text3");

}
