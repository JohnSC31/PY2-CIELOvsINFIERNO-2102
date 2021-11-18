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

    Human * newHuman;

    for(int i = 0; i < numHumans; i++){
        id = genHumanId();
        if(id < 0){
            qDebug() << "No hay mas espacio para humanos";
            break;
        }
        // se asigna los valores de forma aleatoria
        name = namesList[rand() % namesLength]; // se asigna nombre aleatorio
        lastName = lastNamesList[rand() % namesLength];
        country = countriesList[rand() % countriesLength];
        belief = beliefsList[rand() % beliefLength];
        profession = jobsList[rand() % jobsLength];
        email = "estudiante@estudiantec.cr";
        newHuman = new Human(id, name, lastName, country, belief, profession, email);

        initActions(newHuman);

        // asignacion de hijos
        asignChilds(newHuman);
        humans[indexHumansArray] = newHuman;
        indexHumansArray++;
        qDebug() << "Humano agregado al array. ";

        if(peopleTree->root == NULL){
            // no hay arbol
            humanList->insertHuman(newHuman);
        }else{
            // baja por el arbol y lo inserta
            humanList->insertInOrder(newHuman, peopleTree->search(id, peopleTree->root));
        }

    } // for human

    // determinar cuando se genera un arbol nuevo
    treeCounter += numHumans;
    if(treeCounter >= genTree){
        // genera un arbol con la lista de humanos que este
        qDebug () << "se genera un arbol ";
        peopleTree = new PeopleTree(humanList);
        treeCounter = 0;
    }

}

// inicializacion de las buenas acciones y pecados de los humanos con respecto a los del mundo
void TheWorld::initActions(Human * human){
    for(int i = 0; i < 7; i++){
        human->goods.append(new Action(goodActions[i]));
        human->sins.append(new Action(sinsActions[i]));
    }
}



// Hace pecar y realizar buenas acciones a todos los humanos
void TheWorld::sumOfActions(){
    HumanNode * temp = humanList->firstNode;
    while(temp != NULL){
        // suma de pecados
        sumOfSins(temp->human);
        // suma de buenas acciones
        sumOfGoods(temp->human);

        temp = temp->next;
    }
}

// la suma de pecados
void TheWorld::sumOfSins(Human * human){
    for(int i = 0; i < 7; i++){
        sumOfSin(human, sinsActions[i], rand() % 101, 0);
    }
}

// suma de buenas acciones
void TheWorld::sumOfGoods(Human * human){
    for(int i = 0; i < 7; i++){
        sumOfGood(human, goodActions[i], rand() % 101, 0);
    }
}


// la suma de una accion en especifico y su herencia
void TheWorld::sumOfGood(Human * human, QString good, int amount, int generation){
    human->addGood(good, amount);

    if(generation > 2){
        return;
    }else{
        // se realiza la herencia
        HumanNode * tempChild = human->childList->firstNode;
        while(tempChild != NULL){
            sumOfSin(tempChild->human, good, (amount / 2), generation + 1);
        }
        return;
    }
}

// la suma de una accion en especifico y su herencia
// mediante una llamada recursiva le hereda la mitad de su pecado a sus hijos y el 25% a sus nietos
void TheWorld::sumOfSin(Human * human, QString sin, int amount, int generation){
    human->addSin(sin, amount);

    if(generation > 2){
        return;
    }else{
        // se realiza la herencia
        HumanNode * tempChild = human->childList->firstNode;
        while(tempChild != NULL){
            sumOfSin(tempChild->human, sin, (amount / 2), generation + 1);
        }
        return;
    }
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


// valida si un id ya esta usado si no, lo coloca como ya usado
bool TheWorld::validHumanId(int newHumanId){
    if(usedNumbers[newHumanId])
        return false;

    usedNumbers[newHumanId] = true; // se ocupa el espacio
    return true; // retorna que esta asignado
}


// asigna hijos de forma aleatoria de la lista de humanos
void TheWorld::asignChilds(Human * human){
    int numChilds = rand() % 9; // random de 0 a 8

    HumanNode * temp = humanList->firstNode;

    while(temp != NULL){

        if(numChilds == 0){
            break;
            // se sale cuando ya haya asignado la cantidad de hijo correspondientes
            // o no haya hijos que asignar
        }

        if(human->country == temp->human->country && human->lastName == temp->human->lastName
                && temp->human->father == NULL){
            human->childList->insertHuman(temp->human); // al papa se el agrega un hijo a su lista de hijos
            temp->human->father = human; // al hijo se le agrega un papa
            numChilds--;
        }


        temp = temp->next;
    }

}

// busca y retona el humano o nullo si no lo encontro
HumanNode * TheWorld::searchHuman(int humanId){
    if(peopleTree->root != NULL){
        // se baja por el arbol y lo busca en la lista
        // se busca en la human list
        return humanList->searchHuman(humanId, peopleTree->search(humanId, peopleTree->root));
    }else{
        // lo busca desde el inicio de la lista sin nodo de referencia
        return humanList->searchHuman(humanId, humanList->firstNode);
    }

}



// ------------ funciones para llenar los arreglos de datos para la generacion de humanos ---------------------------
void TheWorld::initHumanIdList(){
    // el minimo son 10000, pero el max son 100 000
    for(int i = 0; i < 100000; i++){
        usedNumbers[i] = false;
    }
}

void TheWorld::initNamesList(){
    QString filePath = QDir::currentPath() + "/../Names.txt";
    QFile file(filePath);
    if(file.open(QIODevice::ReadOnly)){
        QTextStream in(&file);
        int i = 0;

        while (!in.atEnd() && i < namesLength) {
            QString line = in.readLine();
            namesList[i] = line;
            i++;
        }

        file.close();
    }

}

void TheWorld::initLastNamesList(){
    QString filePath = QDir::currentPath() + "/../Lastnames.txt";
    QFile file(filePath);
    if(file.open(QIODevice::ReadOnly)){
        QTextStream in(&file);
        int i = 0;
        while (!in.atEnd() && i < namesLength) {
            QString line = capitalize(in.readLine());
            lastNamesList[i] = line;
            i++;
        }
        file.close();
    }

}

void TheWorld::initBeliefsList(){
    QString filePath = QDir::currentPath() + "/../Beliefs.txt";
    QFile file(filePath);
    if(file.open(QIODevice::ReadOnly)){
        QTextStream in(&file);
        int i = 0;
        while (!in.atEnd() && i < beliefLength) {
            QString line = in.readLine();
            beliefsList[i] = line;
            i++;
        }
        file.close();
    }

}

void TheWorld::initCountriesList(){
    QString filePath = QDir::currentPath() + "/../Countries.txt";
    QFile file(filePath);
    if(file.open(QIODevice::ReadOnly)){
        QTextStream in(&file);
        int i = 0;
        while (!in.atEnd() && i < countriesLength) {
            QString line = in.readLine();
            countriesList[i] = line;
            i++;
        }
        file.close();
    }

}

void TheWorld::initJobsList(){
    QString filePath = QDir::currentPath() + "/../Works.txt";
    QFile file(filePath);
    if(file.open(QIODevice::ReadOnly)){
        QTextStream in(&file);
        int i = 0;
        while (!in.atEnd() && i < jobsLength) {
            QString line = in.readLine();
            jobsList[i] = line;
            i++;
        }
        file.close();
    }

}


