#include "structs.h"

Demon::Demon(){

}

Demon::Demon(QString _name, QString _sin){
    name = _name;
    sin = _sin;
    familiesLength = 0;
    initFamilyHeap();
}

// inicia el heap con todas las posiciones apuntando a nulo
void Demon::initFamilyHeap(){
    for(int i = 0; i < heapSize; i ++){
        families[i] = NULL;
    }
}


void Demon::demonCondemnation(QList<Human *> humans, int fivePorcent, QString antagonistic){
    // qlist viene de menor a mayor entonces la recorremos de mayor a menor
    QString log = "";

    for(int i = humans.size() - 1; i >= 0; i--){
        if(fivePorcent <= 0) break; // no condena mas


        insertHumanFamily(humans.at(i));
        humans.at(i)->state = 1; // se cambia la ubicacion para el infierno
        fivePorcent--;
        // agregar texto al log
        log += QString::number(humans.at(i)->id) + " "+ humans.at(i)->name +" "+ humans.at(i)->lastName +" murio el "+ QDateTime::currentDateTime().toString("yyyy-MM-dd hh: mm: ss");
        log += "\n condenado por " + QString::number(humans.at(i)->getActionAmount(sin)) + " pecados de " + sin + " y ";
        log += QString::number(humans.at(i)->getActionAmount(antagonistic)) + " acciones de " + antagonistic + " por " + name;
        log += "\n\n";

    }

    qDebug() << "log de la condenacion";

    QString fileName = name + "_" + QDateTime::currentDateTime().toString("hhmmss");
    writeFile("condemnation/" + fileName, log);

}

// busca cual es su familia y si no esta la crea
void Demon::insertHumanFamily(Human * newHuman){
    Family * searchedFamily = searchFamily(newHuman->lastName, newHuman->country);

    if(searchedFamily != NULL){
        // se inserta en su respectiva familia
        searchedFamily->members->insertHuman(newHuman);
    }else{
        // se crea una nueva familia
        Family * newFamily = new Family(newHuman->lastName, newHuman->country);
        newFamily->members->insertHuman(newHuman);
        insertFamily(newFamily);
    }
}


Family * Demon::searchFamily(QString lastname, QString country){
    for(int i = 1; i <= familiesLength; i++){
        if(families[i]->lastname == lastname && families[i]->country == country){
            // esta es a familia
            return families[i];
        }
    }

    return NULL;
}

// ALGORITMOS PARA EL MANEJO DEL HEAP DE FAMILIAS
int Demon::leftChild(int k){
    int child = 2 * k;
    return validK(child) ? child : -1;
}


int Demon::rightChild(int k){
    int child = 2 * k + 1;
    return validK(child) ? child : -1;
}

int Demon::father(int k){
    int father = k % 2 == 0 ? k /2 : (k - 1) / 2;
    return validK(father) ? father : -1;
}

bool Demon::validK(int k){
    return k > 0 && k < heapSize;
}

// realiza una permutacion de familias en el heaps
void Demon::exchange(int a, int b){
    if(a > 0 && a < heapSize && b > 0 && b < heapSize){
            Family * temp = families[a];
            families[a] = families[b];
            families[b] = temp;
    }else{
        qDebug() << "Indices invalidos " + QString::number(a) +" <-> " +QString::number(b);
    }


}

// realiza una inserccion al final del arreglo
void Demon::insertFamily(Family * newFamily){
    if(familiesLength + 1 < heapSize){
        familiesLength++;
        families[familiesLength] = newFamily;
        orderHeap();
    }else{
        qDebug() << "No hay mas espacio en el heap";
    }
}

// se elimina la raiz y luego se ordena
void Demon::deleteFamily(){
    families[1] = families[familiesLength]; // se pasa el ultimo a la raiz
    families[familiesLength] = NULL; // se elimina la ultima posicion
    familiesLength--; // se resta un elemento
    orderHeap();// se ordena todo el arbol
}

// ordena la familia especificada por la cantidad de pecado cometida del demonio
void Demon::orderFamily(int k){
    while(k > 1 && families[k]->getTotalAction(sin) > families[father(k)]->getTotalAction(sin)){
        exchange(k, father(k)); // permutan
        k = father(k); // ahora k esta en el papa
    }
}

// se ordena todo el heap por la cantidad de accion del pecado del demonio correspondiente
// lo recorre del ultimo al inicio
void Demon::orderHeap(){
    for(int i = familiesLength; i > 0; i--){
        orderFamily(i);
    }
}
