#ifndef MANDATORYFIELDGROUP_H
#define MANDATORYFIELDGROUP_H

#include <QDialog>

namespace Ui {
class MandatoryFieldGroup;
}

class MandatoryFieldGroup : public QDialog
{
    Q_OBJECT

public:
    explicit MandatoryFieldGroup(QWidget *parent = nullptr);
    ~MandatoryFieldGroup();

private:
    Ui::MandatoryFieldGroup *ui;
};

#endif // MANDATORYFIELDGROUP_H
