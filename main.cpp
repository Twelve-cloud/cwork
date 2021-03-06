#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    QString filename = ":/style.css";
    if (!QFile::exists(filename))
    {
        qFatal("Can't loading styles.");
    }
    QFile style(filename);
    style.open(QIODevice::ReadOnly);
    app.setStyleSheet(style.readAll());

    MainWindow window("127.0.0.1", 1280);
    window.display();

    return app.exec();
}
