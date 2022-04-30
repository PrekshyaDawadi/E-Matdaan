#ifndef TECHNICAL_H
#define TECHNICAL_H

#include <QDialog>

namespace Ui {
class technical;
}

class technical : public QDialog
{
    Q_OBJECT

public:
    explicit technical(QWidget *parent = nullptr);
    ~technical();

private:
    Ui::technical *ui;
};

#endif // TECHNICAL_H
