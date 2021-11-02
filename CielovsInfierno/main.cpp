#include "mainwindow.h"
#include <QDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    Actions x;
    x.addGoods();
    x.printGoods();
    x.addSins();
    x.printSins();
    qDebug() << "Total buenas acciones: " << x.countGoods() << "\n";
    qDebug() << "Total de pecados: " << x.countSins() << "\n";
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    // cambio nuevo en la rama de john
    //Comentario de Fabian
    // tercer comentario
    //Otro cambio
}
