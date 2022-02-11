#include "signalhandler.h"
#include <QGridLayout>
#include <QPushButton>
#include <QObject>

signalHandler::signalHandler()
{
}

void signalHandler::dashboard(){

    // New Window Widget
    QWidget *window = new QWidget;
    window->setWindowTitle("Dashboard");
    // creating Layout for dashboard
    QGridLayout *layout2 = new QGridLayout;

    // Creating push buttons
    QPushButton *BallotButton = new QPushButton("Ballot");
    QPushButton *PartyButton = new QPushButton("Parties Information");
    QPushButton *CandidatesButton = new QPushButton("Candidates Information");
    QPushButton *ResultButton = new QPushButton("Results");
    QPushButton *HelpButton = new QPushButton("Help");

    // Adding push buttons to layout
    layout2->addWidget(BallotButton, 0, 0);
    layout2->addWidget(PartyButton, 0, 1);
    layout2->addWidget(CandidatesButton, 0, 2);
    layout2->addWidget(ResultButton, 1, 1);
    layout2->addWidget(HelpButton, 1, 2);

    window->setLayout(layout2);

    window->show();
}





