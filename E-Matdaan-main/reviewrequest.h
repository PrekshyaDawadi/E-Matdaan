#ifndef REVIEWREQUEST_H
#define REVIEWREQUEST_H

#include <QMainWindow>

#include <QApplication>
#include <QTableView>
#include <QStandardItemModel>
#include <QStyledItemDelegate>
#include <QHeaderView>
#include <QPushButton>

namespace Ui {
class ReviewRequest;
}

class ReviewRequest : public QMainWindow
{
    Q_OBJECT

public:
    explicit ReviewRequest(QWidget *parent = nullptr);
    ~ReviewRequest();

private:
    Ui::ReviewRequest *ui;
};

#endif // REVIEWREQUEST_H
