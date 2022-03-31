#include "ballot.h"
#include "ui_ballot.h"

ballot::ballot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ballot)
{
    ui->setupUi(this);
}

ballot::~ballot()
{
    delete ui;
}

void ballot::on_radioButton_clicked()
{
    //Increase the vote for candidate 1 and disable buttons
}


void ballot::on_radioButton_2_clicked()
{
    //Increase the vote for candidate 2 and disable buttons
}

void ballot::on_radioButton_3_clicked()
{
    //Increase the vote for candidate 3 and disable buttons
}
