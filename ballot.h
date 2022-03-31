#ifndef BALLOT_H
#define BALLOT_H

#include <QDialog>

namespace Ui {
class ballot;
}

class ballot : public QDialog
{
    Q_OBJECT

public:
    explicit ballot(QWidget *parent = nullptr);
    ~ballot();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

private:
    Ui::ballot *ui;
};

#endif // BALLOT_H
