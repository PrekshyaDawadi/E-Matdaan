#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include "signup.h"
#include<QFont>
#include<QColorDialog>
#include<QColor>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSql>
#include <QMainWindow>

MainWindow::MainWindow(QWidget *parent)

    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Login_clicked()
{
    QString VoterID =ui->lineEdit_Name->text();
    QString password =ui->lineEdit_2_Password->text();

    if(VoterID== "prasiddhi" && password=="test"){
        dashboard();
    }
    else if(VoterID== "prasi" && password=="test"){
        dashboard();
    }
    else{
       QMessageBox::warning(this,"login","Voter ID and password is incorrect");
    }
}


void MainWindow::on_pushButton_clicked()
{
    Signup signup;
    signup.setModal(true);
    signup.exec();
}

void MainWindow::dashboard()
{

    // New Window Widget
    QWidget *window = new QWidget;
    setWindowTitle("Dashboard");
    // creating Layout for dashboard
    QGridLayout *layout2 = new QGridLayout;

    // Creating push buttons
    QPushButton *BallotButton = new QPushButton("Ballot");
    //QPushButton *PartyButton = new QPushButton("Parties Information");
    QPushButton *CandidatesButton = new QPushButton("Candidates Information");
    QPushButton *ResultButton = new QPushButton("Results");
    QPushButton *HelpButton = new QPushButton("Help");

    // Adding push buttons to layout
    layout2->addWidget(BallotButton, 0, 0);
    //addWidget(BallotButton, 0, 0);
    //layout2->addWidget(PartyButton, 0, 1);
    //addWidget(PartyButton, 0, 1);
    layout2->addWidget(CandidatesButton, 0, 2);
    //addWidget(CandidatesButton, 0, 2);
    layout2->addWidget(ResultButton, 1, 1);
    //addWidget(ResultButton, 1, 1);
    layout2->addWidget(HelpButton, 1, 2);
    //addWidget(HelpButton, 1, 2);

    window->setLayout(layout2);
    setLayout(layout2);

    window->show();
    show();
}



void MainWindow::on_actionColor_triggered()
{
    QColor color= QColorDialog::getColor(Qt::white,this);
if(color.isValid()){
   }
}
