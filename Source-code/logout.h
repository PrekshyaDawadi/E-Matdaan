#ifndef LOGOUT_H
#define LOGOUT_H

#include <QDialog>

namespace Ui {
class logout;
}

class logout : public QDialog
{
    Q_OBJECT

public:
    explicit logout(QWidget *parent = nullptr);
    ~logout();

private slots:
    void on_pushButton_clicked();

private:
    Ui::logout *ui;
};

#endif // LOGOUT_H
