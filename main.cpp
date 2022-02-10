// Header files included by the editor
#include "mainwindow.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>

// Header files that I added
#include <qpushbutton.h>
#include <QGridLayout>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "E-Matdaan_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    MainWindow w;
    w.show();

    return a.exec();
}
