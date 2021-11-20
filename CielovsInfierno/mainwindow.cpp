#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // detectar el cambio de los comboboxs
    //connect(ui->cmbTrays, SIGNAL(currentIndexChanged(int)), this, SLOT(on_cmbTrays_change(int)));

    // Asignacion de los componentes graficos
    // el mundo
    universe->world->lblTreeData = ui->lblTreeData;
    universe->world->lblLastLvlTree = ui->lblLastLvlTree;
}

MainWindow::~MainWindow()
{
    delete ui;
}


//------------------- FUNCIONES DE LOS ACTION LISTENER DE LOS BOTONES----------------------------------------------
// funcion para el boton de generar humanos
void MainWindow::on_btnGenerateHumans_clicked(){
    QString humansStr = ui->inpNumHumans->text();

    if(validNumber(humansStr)){
        ui->inpNumHumans->setText("");
        universe->world->generateHumans(humansStr.toInt());
        qDebug () << "se generan " + humansStr + " humanos";
    }


}

// genera acciones para todos los humanos
void MainWindow::on_btnSumOfActions_clicked(){

    universe->world->sumOfActions();

    qDebug() << "Se generan acciones";
}
// ----------------------------- CONSULTAS ------------------------------------------
// Consulta de familia por id
void MainWindow::on_btnQueryFamily_clicked(){
    QString cmbOption = ui->cmbQueryFamily->currentText();
    QString humanIdStr = ui->inpQueryFamily->text();

    if(validNumber(humanIdStr)){
        universe->world->queryFamilyActions(humanIdStr.toInt(), cmbOption);
    }

}




