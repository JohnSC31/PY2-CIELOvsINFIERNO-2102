/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *btnGenerateHumans;
    QPushButton *btnSumOfActions;
    QPushButton *GenerarBuenasAcciones;
    QPushButton *ConsultarMiembrosDeInfierno;
    QPushButton *IniciarSalvacion;
    QPushButton *MostrarGanador;
    QPushButton *ConsultarFamilias;
    QPushButton *ConsultarBuenasAcciones;
    QPushButton *ConsultarPecados;
    QLineEdit *inpNumHumans;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1323, 675);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(410, 0, 361, 51));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        btnGenerateHumans = new QPushButton(centralwidget);
        btnGenerateHumans->setObjectName(QString::fromUtf8("btnGenerateHumans"));
        btnGenerateHumans->setGeometry(QRect(50, 110, 171, 31));
        btnSumOfActions = new QPushButton(centralwidget);
        btnSumOfActions->setObjectName(QString::fromUtf8("btnSumOfActions"));
        btnSumOfActions->setGeometry(QRect(50, 180, 171, 51));
        GenerarBuenasAcciones = new QPushButton(centralwidget);
        GenerarBuenasAcciones->setObjectName(QString::fromUtf8("GenerarBuenasAcciones"));
        GenerarBuenasAcciones->setGeometry(QRect(50, 270, 171, 51));
        ConsultarMiembrosDeInfierno = new QPushButton(centralwidget);
        ConsultarMiembrosDeInfierno->setObjectName(QString::fromUtf8("ConsultarMiembrosDeInfierno"));
        ConsultarMiembrosDeInfierno->setGeometry(QRect(50, 350, 171, 51));
        IniciarSalvacion = new QPushButton(centralwidget);
        IniciarSalvacion->setObjectName(QString::fromUtf8("IniciarSalvacion"));
        IniciarSalvacion->setGeometry(QRect(50, 430, 171, 51));
        MostrarGanador = new QPushButton(centralwidget);
        MostrarGanador->setObjectName(QString::fromUtf8("MostrarGanador"));
        MostrarGanador->setGeometry(QRect(50, 520, 171, 51));
        ConsultarFamilias = new QPushButton(centralwidget);
        ConsultarFamilias->setObjectName(QString::fromUtf8("ConsultarFamilias"));
        ConsultarFamilias->setGeometry(QRect(270, 270, 171, 51));
        ConsultarBuenasAcciones = new QPushButton(centralwidget);
        ConsultarBuenasAcciones->setObjectName(QString::fromUtf8("ConsultarBuenasAcciones"));
        ConsultarBuenasAcciones->setGeometry(QRect(270, 90, 171, 51));
        ConsultarPecados = new QPushButton(centralwidget);
        ConsultarPecados->setObjectName(QString::fromUtf8("ConsultarPecados"));
        ConsultarPecados->setGeometry(QRect(270, 180, 171, 51));
        inpNumHumans = new QLineEdit(centralwidget);
        inpNumHumans->setObjectName(QString::fromUtf8("inpNumHumans"));
        inpNumHumans->setGeometry(QRect(50, 90, 171, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1323, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Cielo vs Infierno \360\237\230\210", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Cielo vs Infierno \360\237\221\271", nullptr));
        btnGenerateHumans->setText(QCoreApplication::translate("MainWindow", "Generar Humanos", nullptr));
        btnSumOfActions->setText(QCoreApplication::translate("MainWindow", "Suma de acciones", nullptr));
        GenerarBuenasAcciones->setText(QCoreApplication::translate("MainWindow", "Generar Buenas Acciones", nullptr));
        ConsultarMiembrosDeInfierno->setText(QCoreApplication::translate("MainWindow", "Miembros del infierno", nullptr));
        IniciarSalvacion->setText(QCoreApplication::translate("MainWindow", "Iniciar salvaci\303\263n", nullptr));
        MostrarGanador->setText(QCoreApplication::translate("MainWindow", "Mostrar ganador", nullptr));
        ConsultarFamilias->setText(QCoreApplication::translate("MainWindow", "Consultar familias", nullptr));
        ConsultarBuenasAcciones->setText(QCoreApplication::translate("MainWindow", "Consultar buenas acciones", nullptr));
        ConsultarPecados->setText(QCoreApplication::translate("MainWindow", "Consultar Pecados", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
