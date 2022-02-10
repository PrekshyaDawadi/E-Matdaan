// Header files included by the editor
#include "mainwindow.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>

// Header files that I added
#include <qpushbutton.h>
#include <QVBoxLayout>
#include <QWindow>

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

    //MainWindow w;
    //w.show();

    QVBoxLayout box;
    //Resize the container


    QPushButton button("Close", &box);
    button.resize(100,100);
    button.setFont(QFont("Times", 18, QFont::Bold));

    QObject::connect(&button, SIGNAL(clicked()), &a, SLOT(quit()));


    box.show();

    return a.exec();
}
