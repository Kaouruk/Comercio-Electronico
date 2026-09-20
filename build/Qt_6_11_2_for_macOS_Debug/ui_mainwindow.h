/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QTextBrowser *txtListas;
    QLCDNumber *lcdNumber;
    QPushButton *buttonMostrarListado;
    QComboBox *inputTipoListado;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255))"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(10, 50, 691, 41));
        textEdit->setStyleSheet(QString::fromUtf8("background-color:rgb(168, 168, 168);\n"
"color: black;"));
        txtListas = new QTextBrowser(centralwidget);
        txtListas->setObjectName("txtListas");
        txtListas->setGeometry(QRect(220, 200, 181, 201));
        txtListas->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"color:black;"));
        lcdNumber = new QLCDNumber(centralwidget);
        lcdNumber->setObjectName("lcdNumber");
        lcdNumber->setGeometry(QRect(590, 12, 101, 21));
        buttonMostrarListado = new QPushButton(centralwidget);
        buttonMostrarListado->setObjectName("buttonMostrarListado");
        buttonMostrarListado->setGeometry(QRect(260, 430, 100, 32));
        buttonMostrarListado->setStyleSheet(QString::fromUtf8("color:green;"));
        inputTipoListado = new QComboBox(centralwidget);
        inputTipoListado->addItem(QString());
        inputTipoListado->addItem(QString());
        inputTipoListado->addItem(QString());
        inputTipoListado->setObjectName("inputTipoListado");
        inputTipoListado->setGeometry(QRect(240, 160, 161, 32));
        inputTipoListado->setStyleSheet(QString::fromUtf8("color:rgb(0, 249, 0);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 30));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        textEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt;\"> Welcome Kathia</span></p></body></html>", nullptr));
        buttonMostrarListado->setText(QCoreApplication::translate("MainWindow", "Ver Listado", nullptr));
        inputTipoListado->setItemText(0, QCoreApplication::translate("MainWindow", "Clientes", nullptr));
        inputTipoListado->setItemText(1, QCoreApplication::translate("MainWindow", "Productos", nullptr));
        inputTipoListado->setItemText(2, QCoreApplication::translate("MainWindow", "Ultimas Compras", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
