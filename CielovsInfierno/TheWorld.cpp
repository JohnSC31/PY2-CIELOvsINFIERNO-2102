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
    int id;
    QString name;
    QString lastName;
    QString country;
    QString belief;
    QString profession;
    QString email;

    for(int i = 0; i < numHumans; i++){
        id = genHumanId();
        if(id <= 0){
            qDebug() << "No hay mas espacio para humanos";
            break;
        }
        name = namesList[rand() % namesList->size()]; // se asigna nombre aleatorio
        lastName = lastNamesList[rand() % lastNamesList->size()];
        country = countriesList[rand() % countriesList->size()];
        belief = beliefsList[rand() % beliefsList->size()];
        profession = jobsList[rand() % jobsList->size()];
        email = "estudiante@estudiantec.cr";
        humanList->insertHuman(new Human(id, name, lastName, country, belief, profession, email), getPreHuman(id));
    }

    // determinar cuando se genera un arbol nuevo
    treeCounter += numHumans;
    if(treeCounter >= genTree){
        // genera un arbol con la lista de humanos que este
        peopleTree = new PeopleTree(humanList);
        treeCounter = 0;
    }

}


// busca el nodo de la lista de humanos anterior al espacio donde se insertara el nuevo humano
HumanNode * TheWorld::getPreHuman(int humanId){
    HumanNode * tmp = peopleTree->search(humanId, peopleTree->root);
    while(true){
        if(tmp->human->id < humanId){
            if(tmp->next->human->id < humanId){
                // se encontro
                break;
            }else{
                tmp = tmp->next;
            }
        }else{
            tmp = tmp->past;
        }
    }

    return tmp; // se encontro el nodo antes para insertar el humano

}


// Hace pecar y realizar buenas acciones a todos los humanos
void TheWorld::sumOfActions(){
    // recorre la lista de humanos llamando a una funcion que le sume a cada uno
    // las buenas acciones y los pecados (con herencia)
}


// genera de forma aleatoria un numero como nuevo id y verifica y ya esta usado
// si esta disponible lo coloca ocupado y lo retorna
int TheWorld::genHumanId(){
    int genCounter = 0; // cuando llegue al size de la cantidad de ids quiere decir que todos estan ocupados
    int newHumanId;
    do{
        newHumanId = rand() % 100000;
        genCounter++; // se incrementa por cada vez que genera un random
        if(genCounter >= 100000){
            return -1; // todos estan ocupados ya
        }
    }while(!validHumanId(newHumanId));

    return newHumanId;
}

bool TheWorld::validHumanId(int newHumanId){
    if(usedNumbers[newHumanId])
        return false;

    usedNumbers[newHumanId] = true; // se ocupa el espacio
    return true; // retorna que esta asignado
}




// funciones para llenar los arreglos de datos para la generacion de humanos
void TheWorld::initHumanIdList(){
    // el minimo son 10000, pero el max son 100 000
    for(int i = 0; i < 100000; i++){
        usedNumbers[i] = false;
    }
}

void TheWorld::initNamesList(){
    QString filePath = QDir::currentPath() + "/../Names.txt";
    QFile file(filePath);
    QTextStream in(&file);
    int i = 0;
    while (!in.atEnd() && i < namesList->size()) {
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
    while (!in.atEnd() && lastNamesList->size()) {
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
    while (!in.atEnd() && beliefsList->size()) {
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
    while (!in.atEnd() && countriesList->size()) {
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
    while (!in.atEnd() && jobsList->size()) {
        QString line = in.readLine();
        jobsList[i] = line;
        qDebug() << line;
        i++;
    }
    file.close();
}


