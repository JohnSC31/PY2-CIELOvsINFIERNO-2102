#include "structs.h"


TheWorld::TheWorld(){
    humanList = new HumanList();
    peopleTree = new PeopleTree();
    treeCounter = 0; // contador para la generacion del arbol
    genTree = 100; // el minimo y cada cuanto se genera un nuevo arbol

    // se inicializan las listas de datos
    initHumanIdList();
    initNamesList();
    initLastNamesList();
    initBeliefsList();
    initCountriesList();
    initJobsList();
}


// generacion de humanos
void TheWorld::generateHumans(int numHumans){

    for(int i = 0; i < numHumans; i++){
        //humanList->generateHuman();
    }

    // determinar cuando se genera un arbol nuevo
    treeCounter += numHumans;
    if(treeCounter >= genTree){
        // genera un arbol con la lista de humanos que este
        peopleTree = new PeopleTree(humanList);
        treeCounter = 0;
    }

}

// Hace pecar y realizar buenas acciones a todos los humanos
void TheWorld::sumOfActions(){
    // recorre la lista de humanos llamando a una funcion que le sume a cada uno
    // las buenas acciones y los pecados (con herencia)
}




// funciones para llenar los arreglos de datos para la generacion de humanos
void TheWorld::initHumanIdList(){
    // el minimo son 10000, pero el max son 100 000
    for(int i = 0; i < 10000; i++){
        usedNumbers[i] = false;
    }
}

void TheWorld::initNamesList(){
    QString filePath = QDir::currentPath() + "/../Names.txt";
    QFile file(filePath);
    QTextStream in(&file);
    int i = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        namesList[i] = line;
        i++;
    }
    file.close();
}

void TheWorld::initLastNamesList(){
    QString filePath = QDir::currentPath() + "/../Lastnames.txt";
    QFile file(filePath);
    QTextStream in(&file);
    int i = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        lastNamesList[i] = line;
        qDebug() << line;
        i++;
    }
    file.close();
}

void TheWorld::initBeliefsList(){
    QString filePath = QDir::currentPath() + "/../Beliefs.txt";
    QFile file(filePath);
    QTextStream in(&file);
    int i = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        beliefsList[i] = line;
        qDebug() << line;
        i++;
    }
    file.close();
}

void TheWorld::initCountriesList(){
    QString filePath = QDir::currentPath() + "/../Countries.txt";
    QFile file(filePath);
    QTextStream in(&file);
    int i = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        countriesList[i] = line;
        qDebug() << line;
        i++;
    }
    file.close();
}

void TheWorld::initJobsList(){
    QString filePath = QDir::currentPath() + "/../Works.txt";
    QFile file(filePath);
    QTextStream in(&file);
    int i = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        namesList[i] = line;
        qDebug() << line;
        i++;
    }
    file.close();
}


