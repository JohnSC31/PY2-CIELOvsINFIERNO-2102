#include "structs.h"
#include <QDebug>
#include <time.h> //Librería para los random

Actions::Actions(){
    // constructor de acciones
}

void Actions::addGoods(){ //Añade las buenas acciones al humano
     srand(time(NULL)); //Inicializa los random
    int randomGood;
    for(int i = 0; i < 7; i++){
        randomGood = rand()%(7); // Elige un índice random para colocar la cantidad de buenas acciones, es decir, escoge la buena acción a aumentar.
        goods[randomGood] += 1+rand()%(100+1);

    }
}
void Actions::addSins(){ //Añade los pecados al humano
    int randomGood;
    for(int i = 0; i < 7; i++){
        randomGood = rand()%(7); // Elige un índice random para colocar la cantidad de pecados, es decir, escoge el pecado a aumentar.
        sinsCommited[randomGood] += 1+rand()%(100+1);

    }
}
void Actions::printGoods(){ //Imprimir las buenas acciones
    for(int i = 0; i < 7; i++){
        qDebug() << "Buena acción: " << goodActions[i] << " Cantidad cometida: " << goods[i] << "\n";
    }
}
void Actions::printSins(){ //Imprime los pecados
    for(int i = 0; i < 7; i++){
        qDebug() << "Pecado: " << sins[i] << " Cantidad cometida: " << sinsCommited[i] << "\n"; // Recorre los subíndices para imprimir
    }
}
int Actions::countGoods(){ //Contar las buenas acciones. Creo que este método puede servir después para las consultas y la salvación
    int total = 0;
    for(int i = 0; i < 7; i++){
        total += goods[i];
    }
    return total;
}
int Actions::countSins(){ //Contador de pecados
    int total = 0;
    for(int i = 0; i < 7; i++){
        total += sinsCommited[i];
    }
    return total;
}

