#ifndef CANDIDATEINFO_H
#define CANDIDATEINFO_H

#include <QDialog>

namespace Ui {
class candidateinfo;
}

class candidateinfo : public QDialog
{
    Q_OBJECT

public:
    explicit candidateinfo(QWidget *parent = nullptr);
    ~candidateinfo();

private:
    Ui::candidateinfo *ui;
};

#endif // CANDIDATEINFO_H
