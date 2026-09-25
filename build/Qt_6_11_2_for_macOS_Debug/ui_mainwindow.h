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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_5;
    QComboBox *cbxGestionar;
    QLabel *label_6;
    QTextBrowser *txtListas;
    QGroupBox *grpProductos;
    QWidget *layoutWidget;
    QFormLayout *formLayout_2;
    QLabel *lblCodigoP;
    QLineEdit *txtCodigoClientes;
    QLabel *lblProd;
    QLineEdit *txtNombreProducto;
    QLabel *lblP;
    QLineEdit *txtPrecioProducto;
    QLabel *label_4;
    QLineEdit *txtCantidadProducto;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_5;
    QPushButton *btnEliminarProducto;
    QPushButton *btnAgregarProducto;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_6;
    QPushButton *btnModificarProducto;
    QPushButton *btnBuscarProducto;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout;
    QComboBox *inputTipoListado;
    QPushButton *buttonMostrarListado;
    QGroupBox *grpCompras;
    QWidget *layoutWidget4;
    QFormLayout *formLayout_3;
    QLabel *lblCodigo_2;
    QLineEdit *txtCodigoCompras;
    QLabel *lblNombre_2;
    QLineEdit *txtClienteCompras;
    QLabel *lblCorreo_2;
    QLineEdit *txtProductoCompras;
    QLabel *lblCorreo_3;
    QLineEdit *txtPrecioCompras;
    QLineEdit *txtCantidadCompras;
    QLabel *lblCorreo_4;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btnEliminarCompra;
    QPushButton *btnAgregarCompra;
    QWidget *layoutWidget6;
    QVBoxLayout *verticalLayout_4;
    QPushButton *btnModificarCompra;
    QPushButton *btnBuscarCompra;
    QGroupBox *grpClientes;
    QWidget *layoutWidget_2;
    QFormLayout *formLayout_4;
    QLabel *lblCodigo_3;
    QLineEdit *txtCodigoCrearClientes;
    QLabel *lblNombre_3;
    QLineEdit *txtNombreCliente;
    QLabel *lblCorreo_5;
    QLineEdit *txtCorreoCliente;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_7;
    QPushButton *btnEliminarCliente;
    QPushButton *btnAgregarCliente;
    QWidget *layoutWidget_4;
    QVBoxLayout *verticalLayout_8;
    QPushButton *btnModificarCliente;
    QPushButton *btnBuscarCliente;
    QPushButton *btnDescargarRegistros;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(561, 729);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgba(250,250,250,0.9);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setEnabled(true);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 0, 571, 31));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("background-color:rgb(30,30,30);\n"
"text-align: center;\n"
"color:white;"));
        cbxGestionar = new QComboBox(centralwidget);
        cbxGestionar->addItem(QString());
        cbxGestionar->addItem(QString());
        cbxGestionar->addItem(QString());
        cbxGestionar->setObjectName("cbxGestionar");
        cbxGestionar->setGeometry(QRect(160, 40, 311, 32));
        cbxGestionar->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(233,233,233);\n"
"color:black;\n"
"font-size:24;\n"
"padding:5px;\n"
""));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(80, 50, 71, 20));
        label_6->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:transparent;"));
        txtListas = new QTextBrowser(centralwidget);
        txtListas->setObjectName("txtListas");
        txtListas->setGeometry(QRect(50, 480, 451, 171));
        txtListas->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"color:black;"));
        grpProductos = new QGroupBox(centralwidget);
        grpProductos->setObjectName("grpProductos");
        grpProductos->setGeometry(QRect(50, 80, 461, 331));
        grpProductos->setStyleSheet(QString::fromUtf8("padding:5px;\n"
"background-color:rgb(30,30,30);\n"
"color:white;"));
        grpProductos->setAlignment(Qt::AlignmentFlag::AlignCenter);
        layoutWidget = new QWidget(grpProductos);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 33, 421, 191));
        formLayout_2 = new QFormLayout(layoutWidget);
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setFormAlignment(Qt::AlignmentFlag::AlignCenter);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        lblCodigoP = new QLabel(layoutWidget);
        lblCodigoP->setObjectName("lblCodigoP");

        formLayout_2->setWidget(0, QFormLayout::ItemRole::LabelRole, lblCodigoP);

        txtCodigoClientes = new QLineEdit(layoutWidget);
        txtCodigoClientes->setObjectName("txtCodigoClientes");

        formLayout_2->setWidget(0, QFormLayout::ItemRole::FieldRole, txtCodigoClientes);

        lblProd = new QLabel(layoutWidget);
        lblProd->setObjectName("lblProd");

        formLayout_2->setWidget(1, QFormLayout::ItemRole::LabelRole, lblProd);

        txtNombreProducto = new QLineEdit(layoutWidget);
        txtNombreProducto->setObjectName("txtNombreProducto");

        formLayout_2->setWidget(1, QFormLayout::ItemRole::FieldRole, txtNombreProducto);

        lblP = new QLabel(layoutWidget);
        lblP->setObjectName("lblP");

        formLayout_2->setWidget(2, QFormLayout::ItemRole::LabelRole, lblP);

        txtPrecioProducto = new QLineEdit(layoutWidget);
        txtPrecioProducto->setObjectName("txtPrecioProducto");

        formLayout_2->setWidget(2, QFormLayout::ItemRole::FieldRole, txtPrecioProducto);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        formLayout_2->setWidget(3, QFormLayout::ItemRole::LabelRole, label_4);

        txtCantidadProducto = new QLineEdit(layoutWidget);
        txtCantidadProducto->setObjectName("txtCantidadProducto");

        formLayout_2->setWidget(3, QFormLayout::ItemRole::FieldRole, txtCantidadProducto);

        layoutWidget1 = new QWidget(grpProductos);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(20, 240, 201, 81));
        verticalLayout_5 = new QVBoxLayout(layoutWidget1);
        verticalLayout_5->setSpacing(10);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        btnEliminarProducto = new QPushButton(layoutWidget1);
        btnEliminarProducto->setObjectName("btnEliminarProducto");
        btnEliminarProducto->setMinimumSize(QSize(130, 30));
        btnEliminarProducto->setStyleSheet(QString::fromUtf8("margin:5px;\n"
"background-color:rgb(40,40,40);\n"
"padding:4px;"));

        verticalLayout_5->addWidget(btnEliminarProducto);

        btnAgregarProducto = new QPushButton(layoutWidget1);
        btnAgregarProducto->setObjectName("btnAgregarProducto");
        btnAgregarProducto->setMinimumSize(QSize(130, 30));
        btnAgregarProducto->setStyleSheet(QString::fromUtf8("margin:5px;\n"
"background-color:rgb(40,40,40);\n"
"padding:4px;"));

        verticalLayout_5->addWidget(btnAgregarProducto);

        layoutWidget2 = new QWidget(grpProductos);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(240, 240, 201, 81));
        verticalLayout_6 = new QVBoxLayout(layoutWidget2);
        verticalLayout_6->setSpacing(10);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        btnModificarProducto = new QPushButton(layoutWidget2);
        btnModificarProducto->setObjectName("btnModificarProducto");
        btnModificarProducto->setMinimumSize(QSize(130, 30));
        btnModificarProducto->setStyleSheet(QString::fromUtf8("margin:5px;\n"
"background-color:rgb(40,40,40);\n"
"padding:4px;"));

        verticalLayout_6->addWidget(btnModificarProducto);

        btnBuscarProducto = new QPushButton(layoutWidget2);
        btnBuscarProducto->setObjectName("btnBuscarProducto");
        btnBuscarProducto->setMinimumSize(QSize(130, 30));
        btnBuscarProducto->setStyleSheet(QString::fromUtf8("margin:5px;\n"
"background-color:rgb(40,40,40);\n"
"padding:4px;"));

        verticalLayout_6->addWidget(btnBuscarProducto);

        layoutWidget3 = new QWidget(centralwidget);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(50, 430, 451, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget3);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        inputTipoListado = new QComboBox(layoutWidget3);
        inputTipoListado->addItem(QString());
        inputTipoListado->addItem(QString());
        inputTipoListado->addItem(QString());
        inputTipoListado->addItem(QString());
        inputTipoListado->setObjectName("inputTipoListado");
        inputTipoListado->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(233,233,233);\n"
"color:black;\n"
"font-size:24;\n"
"padding:5px;\n"
""));

        horizontalLayout->addWidget(inputTipoListado);

        buttonMostrarListado = new QPushButton(layoutWidget3);
        buttonMostrarListado->setObjectName("buttonMostrarListado");
        buttonMostrarListado->setStyleSheet(QString::fromUtf8("color:black;\n"
"font-size:24;\n"
"background-color: rgb(233,233,233);"));

        horizontalLayout->addWidget(buttonMostrarListado);

        grpCompras = new QGroupBox(centralwidget);
        grpCompras->setObjectName("grpCompras");
        grpCompras->setGeometry(QRect(50, 80, 461, 331));
        grpCompras->setStyleSheet(QString::fromUtf8("padding:5px;\n"
"background-color:rgb(30,30,30);\n"
"color:white;\n"
""));
        grpCompras->setAlignment(Qt::AlignmentFlag::AlignCenter);
        layoutWidget4 = new QWidget(grpCompras);
        layoutWidget4->setObjectName("layoutWidget4");
        layoutWidget4->setGeometry(QRect(20, 31, 421, 211));
        formLayout_3 = new QFormLayout(layoutWidget4);
        formLayout_3->setObjectName("formLayout_3");
        formLayout_3->setFormAlignment(Qt::AlignmentFlag::AlignCenter);
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        lblCodigo_2 = new QLabel(layoutWidget4);
        lblCodigo_2->setObjectName("lblCodigo_2");

        formLayout_3->setWidget(0, QFormLayout::ItemRole::LabelRole, lblCodigo_2);

        txtCodigoCompras = new QLineEdit(layoutWidget4);
        txtCodigoCompras->setObjectName("txtCodigoCompras");

        formLayout_3->setWidget(0, QFormLayout::ItemRole::FieldRole, txtCodigoCompras);

        lblNombre_2 = new QLabel(layoutWidget4);
        lblNombre_2->setObjectName("lblNombre_2");

        formLayout_3->setWidget(1, QFormLayout::ItemRole::LabelRole, lblNombre_2);

        txtClienteCompras = new QLineEdit(layoutWidget4);
        txtClienteCompras->setObjectName("txtClienteCompras");

        formLayout_3->setWidget(1, QFormLayout::ItemRole::FieldRole, txtClienteCompras);

        lblCorreo_2 = new QLabel(layoutWidget4);
        lblCorreo_2->setObjectName("lblCorreo_2");

        formLayout_3->setWidget(2, QFormLayout::ItemRole::LabelRole, lblCorreo_2);

        txtProductoCompras = new QLineEdit(layoutWidget4);
        txtProductoCompras->setObjectName("txtProductoCompras");

        formLayout_3->setWidget(2, QFormLayout::ItemRole::FieldRole, txtProductoCompras);

        lblCorreo_3 = new QLabel(layoutWidget4);
        lblCorreo_3->setObjectName("lblCorreo_3");

        formLayout_3->setWidget(3, QFormLayout::ItemRole::LabelRole, lblCorreo_3);

        txtPrecioCompras = new QLineEdit(layoutWidget4);
        txtPrecioCompras->setObjectName("txtPrecioCompras");

        formLayout_3->setWidget(3, QFormLayout::ItemRole::FieldRole, txtPrecioCompras);

        txtCantidadCompras = new QLineEdit(layoutWidget4);
        txtCantidadCompras->setObjectName("txtCantidadCompras");

        formLayout_3->setWidget(4, QFormLayout::ItemRole::FieldRole, txtCantidadCompras);

        lblCorreo_4 = new QLabel(layoutWidget4);
        lblCorreo_4->setObjectName("lblCorreo_4");

        formLayout_3->setWidget(4, QFormLayout::ItemRole::LabelRole, lblCorreo_4);

        layoutWidget5 = new QWidget(grpCompras);
        layoutWidget5->setObjectName("layoutWidget5");
        layoutWidget5->setGeometry(QRect(20, 250, 191, 72));
        verticalLayout_3 = new QVBoxLayout(layoutWidget5);
        verticalLayout_3->setSpacing(10);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        btnEliminarCompra = new QPushButton(layoutWidget5);
        btnEliminarCompra->setObjectName("btnEliminarCompra");
        btnEliminarCompra->setMinimumSize(QSize(130, 30));
        btnEliminarCompra->setStyleSheet(QString::fromUtf8("margin:5px;\n"
"background-color:rgb(40,40,40);\n"
"padding:4px;"));

        verticalLayout_3->addWidget(btnEliminarCompra);

        btnAgregarCompra = new QPushButton(layoutWidget5);
        btnAgregarCompra->setObjectName("btnAgregarCompra");
        btnAgregarCompra->setMinimumSize(QSize(130, 30));
        btnAgregarCompra->setStyleSheet(QString::fromUtf8("margin:5px;\n"
"background-color:rgb(40,40,40);\n"
"padding:4px;"));

        verticalLayout_3->addWidget(btnAgregarCompra);

        layoutWidget6 = new QWidget(grpCompras);
        layoutWidget6->setObjectName("layoutWidget6");
        layoutWidget6->setGeometry(QRect(230, 250, 211, 72));
        verticalLayout_4 = new QVBoxLayout(layoutWidget6);
        verticalLayout_4->setSpacing(10);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        btnModificarCompra = new QPushButton(layoutWidget6);
        btnModificarCompra->setObjectName("btnModificarCompra");
        btnModificarCompra->setMinimumSize(QSize(130, 30));
        btnModificarCompra->setStyleSheet(QString::fromUtf8("margin:5px;\n"
"background-color:rgb(40,40,40);\n"
"padding:4px;"));

        verticalLayout_4->addWidget(btnModificarCompra);

        btnBuscarCompra = new QPushButton(layoutWidget6);
        btnBuscarCompra->setObjectName("btnBuscarCompra");
        btnBuscarCompra->setMinimumSize(QSize(130, 30));
        btnBuscarCompra->setStyleSheet(QString::fromUtf8("margin:5px;\n"
"background-color:rgb(40,40,40);\n"
"padding:4px;"));

        verticalLayout_4->addWidget(btnBuscarCompra);

        grpClientes = new QGroupBox(centralwidget);
        grpClientes->setObjectName("grpClientes");
        grpClientes->setGeometry(QRect(50, 80, 461, 331));
        grpClientes->setStyleSheet(QString::fromUtf8("padding:5px;\n"
"background-color:rgb(30,30,30);\n"
"color:white;\n"
""));
        grpClientes->setAlignment(Qt::AlignmentFlag::AlignCenter);
        layoutWidget_2 = new QWidget(grpClientes);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(20, 30, 421, 191));
        formLayout_4 = new QFormLayout(layoutWidget_2);
        formLayout_4->setObjectName("formLayout_4");
        formLayout_4->setFormAlignment(Qt::AlignmentFlag::AlignCenter);
        formLayout_4->setContentsMargins(0, 8, 7, 12);
        lblCodigo_3 = new QLabel(layoutWidget_2);
        lblCodigo_3->setObjectName("lblCodigo_3");

        formLayout_4->setWidget(0, QFormLayout::ItemRole::LabelRole, lblCodigo_3);

        txtCodigoCrearClientes = new QLineEdit(layoutWidget_2);
        txtCodigoCrearClientes->setObjectName("txtCodigoCrearClientes");

        formLayout_4->setWidget(0, QFormLayout::ItemRole::FieldRole, txtCodigoCrearClientes);

        lblNombre_3 = new QLabel(layoutWidget_2);
        lblNombre_3->setObjectName("lblNombre_3");

        formLayout_4->setWidget(1, QFormLayout::ItemRole::LabelRole, lblNombre_3);

        txtNombreCliente = new QLineEdit(layoutWidget_2);
        txtNombreCliente->setObjectName("txtNombreCliente");

        formLayout_4->setWidget(1, QFormLayout::ItemRole::FieldRole, txtNombreCliente);

        lblCorreo_5 = new QLabel(layoutWidget_2);
        lblCorreo_5->setObjectName("lblCorreo_5");

        formLayout_4->setWidget(2, QFormLayout::ItemRole::LabelRole, lblCorreo_5);

        txtCorreoCliente = new QLineEdit(layoutWidget_2);
        txtCorreoCliente->setObjectName("txtCorreoCliente");

        formLayout_4->setWidget(2, QFormLayout::ItemRole::FieldRole, txtCorreoCliente);

        layoutWidget_3 = new QWidget(grpClientes);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(20, 240, 191, 72));
        verticalLayout_7 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_7->setSpacing(10);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        btnEliminarCliente = new QPushButton(layoutWidget_3);
        btnEliminarCliente->setObjectName("btnEliminarCliente");
        btnEliminarCliente->setMinimumSize(QSize(130, 30));
        btnEliminarCliente->setStyleSheet(QString::fromUtf8("margin:5px;\n"
"background-color:rgb(40,40,40);\n"
"padding:4px;"));

        verticalLayout_7->addWidget(btnEliminarCliente);

        btnAgregarCliente = new QPushButton(layoutWidget_3);
        btnAgregarCliente->setObjectName("btnAgregarCliente");
        btnAgregarCliente->setMinimumSize(QSize(130, 30));
        btnAgregarCliente->setStyleSheet(QString::fromUtf8("margin:5px;\n"
"background-color:rgb(40,40,40);\n"
"padding:4px;"));

        verticalLayout_7->addWidget(btnAgregarCliente);

        layoutWidget_4 = new QWidget(grpClientes);
        layoutWidget_4->setObjectName("layoutWidget_4");
        layoutWidget_4->setGeometry(QRect(230, 240, 211, 72));
        verticalLayout_8 = new QVBoxLayout(layoutWidget_4);
        verticalLayout_8->setSpacing(10);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        btnModificarCliente = new QPushButton(layoutWidget_4);
        btnModificarCliente->setObjectName("btnModificarCliente");
        btnModificarCliente->setMinimumSize(QSize(130, 30));
        btnModificarCliente->setStyleSheet(QString::fromUtf8("margin:5px;\n"
"background-color:rgb(40,40,40);\n"
"padding:4px;"));

        verticalLayout_8->addWidget(btnModificarCliente);

        btnBuscarCliente = new QPushButton(layoutWidget_4);
        btnBuscarCliente->setObjectName("btnBuscarCliente");
        btnBuscarCliente->setMinimumSize(QSize(130, 30));
        btnBuscarCliente->setStyleSheet(QString::fromUtf8("margin:5px;\n"
"background-color:rgb(40,40,40);\n"
"padding:4px;"));

        verticalLayout_8->addWidget(btnBuscarCliente);

        btnDescargarRegistros = new QPushButton(centralwidget);
        btnDescargarRegistros->setObjectName("btnDescargarRegistros");
        btnDescargarRegistros->setGeometry(QRect(200, 660, 151, 41));
        btnDescargarRegistros->setStyleSheet(QString::fromUtf8("background-color:rgb(230, 230, 230);\n"
"color:black;\n"
"border: 1px gray solid;"));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "                                          SISTEMA DE COMERCIALIZACION KATHIA'S CMR", nullptr));
        cbxGestionar->setItemText(0, QCoreApplication::translate("MainWindow", "Clientes", nullptr));
        cbxGestionar->setItemText(1, QCoreApplication::translate("MainWindow", "Productos", nullptr));
        cbxGestionar->setItemText(2, QCoreApplication::translate("MainWindow", "Compras", nullptr));

        label_6->setText(QCoreApplication::translate("MainWindow", "Gestionar:", nullptr));
        grpProductos->setTitle(QCoreApplication::translate("MainWindow", "Productos", nullptr));
        lblCodigoP->setText(QCoreApplication::translate("MainWindow", "Codigo:", nullptr));
        lblProd->setText(QCoreApplication::translate("MainWindow", "Producto:", nullptr));
        lblP->setText(QCoreApplication::translate("MainWindow", "Precio:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Cantidad:", nullptr));
        btnEliminarProducto->setText(QCoreApplication::translate("MainWindow", "Eliminar", nullptr));
        btnAgregarProducto->setText(QCoreApplication::translate("MainWindow", "Agregar", nullptr));
        btnModificarProducto->setText(QCoreApplication::translate("MainWindow", "Modificar", nullptr));
        btnBuscarProducto->setText(QCoreApplication::translate("MainWindow", "Buscar", nullptr));
        inputTipoListado->setItemText(0, QCoreApplication::translate("MainWindow", "Clientes", nullptr));
        inputTipoListado->setItemText(1, QCoreApplication::translate("MainWindow", "Productos", nullptr));
        inputTipoListado->setItemText(2, QCoreApplication::translate("MainWindow", "Ultimas Compras", nullptr));
        inputTipoListado->setItemText(3, QCoreApplication::translate("MainWindow", "Prod Existentes", nullptr));

        buttonMostrarListado->setText(QCoreApplication::translate("MainWindow", "Ver Listado", nullptr));
        grpCompras->setTitle(QCoreApplication::translate("MainWindow", "Compras", nullptr));
        lblCodigo_2->setText(QCoreApplication::translate("MainWindow", "Codigo:", nullptr));
        lblNombre_2->setText(QCoreApplication::translate("MainWindow", "Cliente:", nullptr));
        lblCorreo_2->setText(QCoreApplication::translate("MainWindow", "Producto:", nullptr));
        lblCorreo_3->setText(QCoreApplication::translate("MainWindow", "Precio:", nullptr));
        lblCorreo_4->setText(QCoreApplication::translate("MainWindow", "Cantidad: ", nullptr));
        btnEliminarCompra->setText(QCoreApplication::translate("MainWindow", "Eliminar", nullptr));
        btnAgregarCompra->setText(QCoreApplication::translate("MainWindow", "Agregar", nullptr));
        btnModificarCompra->setText(QCoreApplication::translate("MainWindow", "Modificar", nullptr));
        btnBuscarCompra->setText(QCoreApplication::translate("MainWindow", "Buscar", nullptr));
        grpClientes->setTitle(QCoreApplication::translate("MainWindow", "Clientes", nullptr));
        lblCodigo_3->setText(QCoreApplication::translate("MainWindow", "Codigo:", nullptr));
        lblNombre_3->setText(QCoreApplication::translate("MainWindow", "Nombre", nullptr));
        lblCorreo_5->setText(QCoreApplication::translate("MainWindow", "Correo", nullptr));
        btnEliminarCliente->setText(QCoreApplication::translate("MainWindow", "Eliminar", nullptr));
        btnAgregarCliente->setText(QCoreApplication::translate("MainWindow", "Agregar", nullptr));
        btnModificarCliente->setText(QCoreApplication::translate("MainWindow", "Modificar", nullptr));
        btnBuscarCliente->setText(QCoreApplication::translate("MainWindow", "Buscar", nullptr));
        btnDescargarRegistros->setText(QCoreApplication::translate("MainWindow", "Descargar Registros", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
