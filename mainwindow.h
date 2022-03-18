#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include<QFont>
#include<QColorDialog>
#include<QColor>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSql>
#include <QMainWindow>
#include<QMessageBox>
#include <QSqlQuery>



class QPushButton;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Login_clicked();

    void on_pushButton_clicked();

    void on_actionColor_triggered();

    void dashboard();
private:
    Ui::MainWindow *ui;
    QPushButton* pushButton;
    QSqlDatabase db;
};
#endif // MAINWINDOW_H
