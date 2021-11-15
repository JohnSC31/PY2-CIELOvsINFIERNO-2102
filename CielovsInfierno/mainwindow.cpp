#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    qDebug() << "Se ejecuta";
//    // pruebas para la lectura de archivos
//    QString filePath = QDir::currentPath() + "/../Names.txt";
//    qDebug() << "ruta: " + filePath;
//    QFile file(filePath);
//    QString errMsg;
//    QFileDevice::FileError err = QFileDevice::NoError;
//    if (!file.exists()) {
//        qDebug() << "No existe el archivox2";
//    }else{
//        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
//            qDebug() << "Error al abrir el archivo";
//            errMsg = file.errorString();
//            err = file.error();
//            qDebug() << errMsg;

//        }else{
//            QTextStream in(&file);
//            while (!in.atEnd()) {
//                QString line = in.readLine();
//                qDebug() << line;
//            }
//            file.close();
//        }
//    }


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




