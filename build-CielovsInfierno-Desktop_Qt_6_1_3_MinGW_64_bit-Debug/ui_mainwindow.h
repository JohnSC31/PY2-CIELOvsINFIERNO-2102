/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
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
    QPushButton *ConsultarBuenasAcciones;
    QPushButton *btnQueryFamily;
    QLineEdit *inpNumHumans;
    QLabel *lblTree;
    QLabel *lblTreeData;
    QLabel *lblLastLvlTree;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *cmbQueryFamily;
    QLineEdit *inpQueryFamily;
    QLabel *label_4;
    QComboBox *comboBox_2;
    QPushButton *ConsultarPecados_2;
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
        btnSumOfActions->setGeometry(QRect(50, 150, 171, 31));
        GenerarBuenasAcciones = new QPushButton(centralwidget);
        GenerarBuenasAcciones->setObjectName(QString::fromUtf8("GenerarBuenasAcciones"));
        GenerarBuenasAcciones->setGeometry(QRect(570, 410, 171, 51));
        ConsultarMiembrosDeInfierno = new QPushButton(centralwidget);
        ConsultarMiembrosDeInfierno->setObjectName(QString::fromUtf8("ConsultarMiembrosDeInfierno"));
        ConsultarMiembrosDeInfierno->setGeometry(QRect(570, 520, 171, 51));
        IniciarSalvacion = new QPushButton(centralwidget);
        IniciarSalvacion->setObjectName(QString::fromUtf8("IniciarSalvacion"));
        IniciarSalvacion->setGeometry(QRect(560, 90, 171, 51));
        MostrarGanador = new QPushButton(centralwidget);
        MostrarGanador->setObjectName(QString::fromUtf8("MostrarGanador"));
        MostrarGanador->setGeometry(QRect(560, 180, 171, 51));
        ConsultarBuenasAcciones = new QPushButton(centralwidget);
        ConsultarBuenasAcciones->setObjectName(QString::fromUtf8("ConsultarBuenasAcciones"));
        ConsultarBuenasAcciones->setGeometry(QRect(560, 310, 171, 51));
        btnQueryFamily = new QPushButton(centralwidget);
        btnQueryFamily->setObjectName(QString::fromUtf8("btnQueryFamily"));
        btnQueryFamily->setGeometry(QRect(320, 150, 171, 31));
        inpNumHumans = new QLineEdit(centralwidget);
        inpNumHumans->setObjectName(QString::fromUtf8("inpNumHumans"));
        inpNumHumans->setGeometry(QRect(50, 90, 171, 20));
        lblTree = new QLabel(centralwidget);
        lblTree->setObjectName(QString::fromUtf8("lblTree"));
        lblTree->setGeometry(QRect(50, 190, 171, 31));
        lblTree->setFont(font);
        lblTree->setAlignment(Qt::AlignCenter);
        lblTreeData = new QLabel(centralwidget);
        lblTreeData->setObjectName(QString::fromUtf8("lblTreeData"));
        lblTreeData->setGeometry(QRect(50, 220, 221, 61));
        lblLastLvlTree = new QLabel(centralwidget);
        lblLastLvlTree->setObjectName(QString::fromUtf8("lblLastLvlTree"));
        lblLastLvlTree->setGeometry(QRect(50, 290, 221, 311));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(56, 40, 161, 20));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(320, 40, 161, 20));
        label_3->setAlignment(Qt::AlignCenter);
        cmbQueryFamily = new QComboBox(centralwidget);
        cmbQueryFamily->addItem(QString());
        cmbQueryFamily->addItem(QString());
        cmbQueryFamily->setObjectName(QString::fromUtf8("cmbQueryFamily"));
        cmbQueryFamily->setGeometry(QRect(320, 120, 171, 22));
        inpQueryFamily = new QLineEdit(centralwidget);
        inpQueryFamily->setObjectName(QString::fromUtf8("inpQueryFamily"));
        inpQueryFamily->setGeometry(QRect(320, 90, 171, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(320, 70, 161, 20));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(320, 220, 171, 22));
        ConsultarPecados_2 = new QPushButton(centralwidget);
        ConsultarPecados_2->setObjectName(QString::fromUtf8("ConsultarPecados_2"));
        ConsultarPecados_2->setGeometry(QRect(320, 250, 171, 31));
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
        ConsultarBuenasAcciones->setText(QCoreApplication::translate("MainWindow", "Consultar buenas acciones", nullptr));
        btnQueryFamily->setText(QCoreApplication::translate("MainWindow", "Consultar Familia", nullptr));
        lblTree->setText(QCoreApplication::translate("MainWindow", "Arbol", nullptr));
        lblTreeData->setText(QString());
        lblLastLvlTree->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "Nacimiento", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Consultas", nullptr));
        cmbQueryFamily->setItemText(0, QCoreApplication::translate("MainWindow", "Pecados", nullptr));
        cmbQueryFamily->setItemText(1, QCoreApplication::translate("MainWindow", "Buenas Acciones", nullptr));

        label_4->setText(QCoreApplication::translate("MainWindow", "Identificador", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "Mas pecadores", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "Menos pecadores", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "Mas Buenos", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("MainWindow", "Menos Buenos", nullptr));

        ConsultarPecados_2->setText(QCoreApplication::translate("MainWindow", "Consultar Familia", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
