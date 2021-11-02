#include "structs.h"
#include <QDebug>
void Actions::addGoods(){
    //int num = 1+rand()%(7);
    for(int i = 0; i < 7; i++){
        int randomGood = rand()%(7); // Elige un índice random para colocar la cantidad de buenas acciones, es decir, escoge la buena acción a aumentar.
        goods[randomGood] += 1+rand()%(100);

    }
}
void Actions::addSins(){
    for(int i = 0; i < 7; i++){
        int randomGood = rand()%(7); // Elige un índice random para colocar la cantidad de pecados, es decir, escoge el pecado a aumentar.
        sinsCommited[randomGood] += 1+rand()%(100);

    }
}
void Actions::printGoods(){
    for(int i = 0; i < 7; i++){
        qDebug() << "Buena acción: " << goodActions[i] << " Cantidad cometida: " << goods[i] << "\n";
    }
}
void Actions::printSins(){
    for(int i = 0; i < 7; i++){
        qDebug() << "Pecado: " << sins[i] << " Cantidad cometida: " << sinsCommited[i] << "\n";
    }
}
int Actions::countGoods(){
    int total = 0;
    for(int i = 0; i < 7; i++){
        total += goods[i];
    }
    return total;
}
int Actions::countSins(){
    int total = 0;
    for(int i = 0; i < 7; i++){
        total += sinsCommited[i];
    }
    return total;
}

