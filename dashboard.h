#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QDeclarativeItem>
#include <QMainWindow>
#include <QObject>
#include <QSharedDataPointer>
#include <QWidget>

class DashboardData;

class Dashboard
{
    Q_OBJECT
public:
    Dashboard();
    Dashboard(const Dashboard &);
    Dashboard &operator=(const Dashboard &);
    ~Dashboard();

private:
    QSharedDataPointer<DashboardData> data;
};

#endif // DASHBOARD_H
