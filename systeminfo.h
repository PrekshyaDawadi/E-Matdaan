#ifndef SYSTEMINFO_H
#define SYSTEMINFO_H

#include <QDialog>

namespace Ui {
class systeminfo;
}

class systeminfo : public QDialog
{
    Q_OBJECT

public:
    explicit systeminfo(QWidget *parent = nullptr);
    ~systeminfo();

private:
    Ui::systeminfo *ui;
};

#endif // SYSTEMINFO_H
