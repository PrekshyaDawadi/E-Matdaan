#ifndef CANDIDATESINFORMATIONINPUT_H
#define CANDIDATESINFORMATIONINPUT_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include "mainwindow.h"
#include <QString>


namespace Ui {
class CandidatesInformationInput;
}

class CandidatesInformationInput : public QDialog
{
    Q_OBJECT

public:
    explicit CandidatesInformationInput(QWidget *parent = nullptr);
    ~CandidatesInformationInput();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::CandidatesInformationInput *ui;
    QSqlDatabase  db;
};

#endif // CANDIDATESINFORMATIONINPUT_H
