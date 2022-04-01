#ifndef ADMINMAINWINDOW_H
#define ADMINMAINWINDOW_H

#include <QDialog>

namespace Ui {
class adminMainWindow;
}

class adminMainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit adminMainWindow(QWidget *parent = nullptr);
    ~adminMainWindow();

private:
    Ui::adminMainWindow *ui;
};

#endif // ADMINMAINWINDOW_H
