#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <math.h>
#include "structs.h"
#include <QColor>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // ------- CREACION DE LA ESTRUCTURA PRINCIPAL ---------------
    Universe * universe = new Universe();

    MainWindow(QWidget * parent = nullptr);
    ~MainWindow();

 // -------------------------------- DEFINICION DE LOS SLOTS PARA BOTONES ------------------------------------
private slots:
    void on_btnGenerateHumans_clicked();
    void on_btnSumOfActions_clicked();
    void on_btnQueryFamily_clicked();

    void on_ConsultarMiembrosDeInfierno_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
