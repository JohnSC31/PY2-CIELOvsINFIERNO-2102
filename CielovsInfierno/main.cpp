#include "mainwindow.h"
#include <QDebug>
#include <QApplication>


int main(int argc, char *argv[])
{   // Esos comentarios son pruebas de los random. Se los dejo ahí por si quieren revisar
    /*/Actions x;
    x.addGoods();
    x.printGoods();
    x.addSins();
    x.printSins();
    qDebug() << "Total buenas acciones: " << x.countGoods() << "\n";
    qDebug() << "Total de pecados: " << x.countSins() << "\n";*/
    //TheWorld* elMundo = new TheWorld();
    //elMundo->initLastNamesList();
    //qDebug() << "Nombres: "<< elMundo->lastNamesList[0];

    //int num =  maxInt(5, 8);
    //qDebug() << "El numero" << num;






    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
