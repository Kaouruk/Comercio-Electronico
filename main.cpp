#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    a.setStyleSheet(
        "QMessageBox {"
        "    background-color: #fff023;"
        "}"

        "QMessageBox QLabel {"
        "    color: black;"
        "    font-size: 15px;"
        "}"

        "QMessageBox QPushButton {"
        "    background-color: #3498db;"
        "    color: black;"
        "    padding: 8px 20px;"
        "    border-radius: 5px;"
        "}"

        "QMessageBox QPushButton:hover {"
        "    background-color: black;"
        "}"
        );

    // MainWindow w;
    w.show();

    return a.exec();
    w.show();
    return a.exec();
}
