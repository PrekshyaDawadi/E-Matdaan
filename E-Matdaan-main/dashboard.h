#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QDialog>
#include "ballot.h"

namespace Ui {
class dashboard;
}

class dashboard : public QDialog
{
    Q_OBJECT

public:
    explicit dashboard(QWidget *parent = nullptr);
    ~dashboard();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::dashboard *ui;
};

#endif // DASHBOARD_H
