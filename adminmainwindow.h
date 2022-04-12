#ifndef ADMINMAINWINDOW_H
#define ADMINMAINWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include "candidatesinformationinput.h"

namespace Ui {
class adminMainWindow;
}

class adminMainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit adminMainWindow(QWidget *parent = nullptr);
    ~adminMainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::adminMainWindow *ui;
};

#endif // ADMINMAINWINDOW_H
