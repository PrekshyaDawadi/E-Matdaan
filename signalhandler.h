#ifndef SIGNALHANDLER_H
#define SIGNALHANDLER_H

#include <QObject>
#include "signalhandler.cpp"

class signalHandler : public QObject
{
    Q_OBJECT
public:
    signalHandler();

public slots:
    void dashboard(void);
};

#endif // SIGNALHANDLER_H
