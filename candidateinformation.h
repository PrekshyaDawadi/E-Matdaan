#ifndef CANDIDATEINFORMATION_H
#define CANDIDATEINFORMATION_H

#include <QWidget>

namespace Ui {
class CandidateInformation;
}

class CandidateInformation : public QWidget
{
    Q_OBJECT

public:
    explicit CandidateInformation(QWidget *parent = nullptr);
    ~CandidateInformation();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CandidateInformation *ui;
};

#endif // CANDIDATEINFORMATION_H
