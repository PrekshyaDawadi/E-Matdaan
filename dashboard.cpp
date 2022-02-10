#include "dashboard.h"

class DashboardData : public QSharedData
{
public:

};

Dashboard::Dashboard() : data(new DashboardData)
{

}

Dashboard::Dashboard(const Dashboard &rhs)
    : data{rhs.data}
{

}

Dashboard &Dashboard::operator=(const Dashboard &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

Dashboard::~Dashboard()
{

}
