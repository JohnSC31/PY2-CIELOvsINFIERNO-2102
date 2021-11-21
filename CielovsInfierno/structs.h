#ifndef STRUCTS_H
#define STRUCTS_H

#include <QString>
#include <QQueue>
#include <QtCore>
#include <QDebug>
#include <QFile>
#include <QtGlobal>
#include <QList>

// ui
#include <QLabel>
#include <QComboBox>

#include "helper.h"

// Definicion de las todas las estructuras para el proyecto


// -------------------------------------- PROTOTIPOS -----------------------------------------------//
struct Human; // persona
struct HumanNode; // nodo de personas
struct HumanList; // la lista de personas
struct Country;
struct CountryList;
struct Actions; // Pecados y buenas acciones
struct Action;

struct PeopleTree; // arbol binario de busqueda
struct TreeNode; // nodos del arbol

struct TheWorld;

struct Demon;
struct Family;

struct Universe; // contiene a todas las estructuras


// -------------------------------------- ESTRUCTURAS DEL MUNDO ------------------------------------ //
struct Human{
public:
    int id;
    int state; //0 - mundo; 1 - infierno; 2 - cielo;
    QString name;
    QString lastName;
    QString country;
    QString belief;
    QString profession;
    QString email;
    QString dateBrith;
    Human * father; // para asignarle o saber si ya tiene un padre
    QList<Action * > goods; // lista de buenas acciones
    QList<Action * > sins; // lista de pecados
    HumanList * childList; // lista de hijos

public:
    Human();
    Human(int _id, QString _name, QString _lastName, QString _country, QString belief, QString _profession, QString email);
    void addSin(QString sin, int amount);
    QString sinsToString();
    QString goodsToString();
    void addGood(QString good, int amount);
    int getActionAmount(QString action);
    int getNetSin(QString sin);
    QString toString();
    void print();
    int countSins();
    int countGoods();
};

struct HumanNode{
public:
    Human* human;
    HumanNode* next;
    HumanNode* past; //Se puede cambiar por last, etc.

public:
    HumanNode(Human * _human){
        human = _human;
        past = next = NULL;
    }
};

struct HumanList{
public:
    HumanNode * firstNode;
    HumanNode * lastNode;
    int length;


public:
    HumanList();
    void insertHuman(Human * newHuman); // sin arbol
    void insertInOrder(Human * newHuman, HumanNode * refNode); // en orden a partir de nodo de referencia
    HumanNode * getMidHuman(); // obtiene el nodo en el medio de la lista
    HumanNode * moveToNode(int move, bool right, HumanNode * refNode);
    // inserciones especiales
    void insertBeginning(Human * newHuman);
    void insertEnd(Human * newHuman);
    void insertMiddle(Human * newHuman, HumanNode * refNode);
    HumanNode * searchHuman(int humanId, HumanNode * refNode);
    HumanList * getFamilyOf(HumanNode * human);
    void getFamilyOf(HumanNode * human, HumanList * family);
    void countActions(void);
    bool isEmpty();
    int getLength();
};

struct Country{
    QString name;
    int totalGoods;
    int totalSins;
    bool taken;
    bool takenLess;

public:
    Country(QString theName){
        name = theName;
        totalGoods = 0;
        totalSins = 0;
        taken = false;
        takenLess = false;
    }
};

struct CountryList{
    QList <Country*> countries;

public:
    void addCountry(QString);
    void addActions(QString, int, int);
    Country* getMax();
    Country* getMin();
    CountryList* getTopTen();
    CountryList* getLastFive();


};

struct ListCountry{
    QList <Country*> countries;

public:
    void addCountry(QString);
    void addActions(QString, int, int);
    Country* getMax();
    Country* getMaxSin();
    Country* getMinSin();
    Country* getMin();
    ListCountry* getTopTen();
    ListCountry* getLastFive();
    ListCountry* getTopTenSinners();
    ListCountry* getLastFiveSinners();

};

// ----------------------- ESTRUCTURAS PARA EL ARBOL DE HUMANOS -----------
struct TreeNode{
public:
    int personId;
    HumanNode * humanNode;
    TreeNode * leftChild; // hijo izquierdo
    TreeNode * rightChild; // hijo derecho

public:
    TreeNode(HumanNode * _humanNode, int _personId){
        humanNode = _humanNode;
        personId = _personId;
        leftChild = rightChild = NULL;
    }
};

struct PeopleTree{
public:
    TreeNode * root;

public:
    PeopleTree();
    PeopleTree(HumanList * humanList);
    void generateTree(HumanList * list, HumanNode * node, int moveNode, int jmp);
    void insert(HumanNode * _humanNode);
    int getNodeTreeAmount(int lengthList);
    TreeNode * insert(int _personId, HumanNode * _personeNode, TreeNode * node);
    HumanNode * search(int personId, TreeNode * node);
    bool isLeaf(TreeNode * node);
    int levels();
    int auxLevels(TreeNode * node);
    int nodesAmount();
    int auxNodesAmount(TreeNode * node);
    QString getLastLvlHumans();
    QString auxGetLastLvlHumans(TreeNode * node);
    void printPreOrden(TreeNode * node);
    int getLeafAmount(TreeNode * node);
};

// -------------------------------------- ESTRUCTURA PARA LAS BUENAS Y MALAS ACCIONES ----------------------------- //
struct Actions{

public:
    QString type = "";
    int goods[7] = {0,0,0,0,0,0,0}; // Contador de buenas acciones
    int sinsCommited[7] = {0,0,0,0,0,0,0}; // Contador de pecaados


public:
    //Procedimientos
    Actions(); // constructor
    void addAction(QString actionName, int actionAmount);
    void addGoods();
    void addSins();
    void printGoods();
    void printSins();
    int countGoods();
    int countSins();

};


struct Action{
public:
    QString action;
    int amount;

public:
    Action(QString _action){
        action = _action;
        amount = 0;
    }
};

// --------------------- ESTRUCTURAS DEL MUNDO -----------------
struct TheWorld{
public:
    Human * humans[100000];
    int indexHumansArray = 0;
    HumanList * humanList; // lista de humanos doblemente enlazada
    PeopleTree * peopleTree; // arbol de personas
    int treeCounter; // contador actual hasta llegar a generar un arbol
    int genTree; // cada cuanto se genera un arbol

    // deben ser iguales al largo de la lista, para manejar todas las iteraciones
    int namesLength = 100; // para los nombres y apellidos
    int beliefLength = 10;
    int countriesLength = 10;
    int jobsLength = 20;
    // Lista de datos para la generacion de un humano
    QString namesList[100];
    QString lastNamesList[100];
    QString beliefsList[10];
    QString countriesList[10];
    QString jobsList[20];
    bool usedNumbers[100000];

    // pecados para los humanos
    //Estos QString sirven para imprimir los pecados e identificarlos en el programa
    QString goodActions[7];
    QString sinsActions[7];

    //Lista de paises para consulta

    ListCountry * countryList;

    //ui
    QLabel * lblTreeData;
    QLabel * lblLastLvlTree;

public:
    TheWorld(QString goods[7], QString sins[7]);
    void generateHumans(int numHumans);
    void initActions(Human * human);
    HumanNode * searchHuman(int humanId);
    void printData();
    bool validHumanId(); // si se puede crear un humano con ese id
    void asignChilds(Human * human);

    void sumOfActions(); // suma de pecados y buenas acciones
    void sumOfSins(Human * human); // recorrido y suma de cada pecado
    void sumOfGoods(Human * human); // recorrido y suma de cada buena accion
    void sumOfGood(Human * human, QString good, int amount, int generation); // suma de un buena accion a un humano
    void sumOfSin(Human * human, QString sin, int amount, int generation); // suma de un pecado a un humano
    int genHumanId();
    bool validHumanId(int newHumanId);
    void printPeopleTreeData();
    void queryFamilyActions(int humanId, QString actionType);
    void countActions(void);
    void getBestCountry();
    void getLastCountry();



    // inicializacion para los datos para la generacion de humanos
    void initHumanIdList();
    void initNamesList();
    void initLastNamesList();
    void initBeliefsList();
    void initCountriesList();
    void initJobsList();


};



// -------------------------------------- ESTRUCTURAS PARA EL INFIERNO ----------------------------- //
struct Family{
public:
    QString country;
    QString lastname;
    HumanList * members;
    int totalAction; // se almacenara el total para la accion especificada


public:
    Family(QString lastname, QString country);
    int getTotalAction(QString action);
    void insert(Human * newHuman);
};

struct Demon{

public:
    QString name;
    QString sin;
    int heapSize = 100000; // para las iteraciones y validaciones
    int familiesLength; // insertar en length + 1 si es menor que heapSize
    // 1000000 de espacios para familias
    Family * families[100000];

public:
    Demon();
    Demon(QString name, QString sin);

    void initFamilyHeap();
    void demonCondemnation(QList<Human *> humans, int fivePorcent, QString antagonistic);
    void demonQuery();
    // algorimos para el heap de familias
    int leftChild(int k);
    int rightChild(int k);
    int father(int k);
    bool validK(int k);
    void exchange(int a, int b);
    void insertFamily(Family * newFamily);
    void deleteFamily(); // se elimina la raiz
    void inverseOrderFamily();
    void orderFamily(int k);
    void orderHeap(); // ordena el heap de familias para que este ordenado
    void insertHumanFamily(Human * human);
    Family * searchFamily(QString lastname, QString country);
};


struct Hell{
public:
    QString demonsName[7];
    QString demonsSin[7];
    QString antagonistic[7]; // buenas acciones
    Demon * demons[7]; // lista de demonios
    HumanList * humansWorld; // referencia de la lista de humanos en el mundo


public:
    Hell(HumanList * humanListWorld, QString demonsName[7], QString sinsActions[7], QString goodActions[7]);
    void initDemons();
    void condemnation(QString demonName); // condenacion del mundo
    Demon * searchDemon(QString name);
    QString getAntagonistic(QString sin);
    void demonQuery(QString denomName);
};





// -------------------------------------- ESTRUCTURAS PARA EL CIELO -------------------------------- //
struct HeavenNode{
    Human* human;
    HeavenNode* leftChild;
    HeavenNode* rightChild;

public:
    HeavenNode(Human* theHuman){
        human = theHuman;
    }
};


struct HeavenTree{
    HeavenNode* root;


public:
    int height(HeavenNode* t);
    int difference(HeavenNode* t);
    /*
    avl *rr_rotat(avl *);
    avl *ll_rotat(avl *);
    avl *lr_rotat(avl*);
    avl *rl_rotat(avl *);
    */
    HeavenNode* rrRot(HeavenNode* r);
    HeavenNode* llRot(HeavenNode* r);
    HeavenNode* lrRot(HeavenNode* r);
    HeavenNode* rlRot(HeavenNode* r);
    HeavenNode* balance(HeavenNode* r);
    HeavenNode* insert(HeavenNode* r, Human* theHuman);
    void show(HeavenNode* r, int l);
    void inorder(HeavenNode* r);

public:
    HeavenTree(){
        root= NULL;
    }

};

struct Heaven{

    HeavenTree* heavenList[1000];
    HumanList* humanWorld;

public:
    Heaven(HumanList* worldList);
    int hashFunction(int);
    void insert(Human*);

};

struct Angel{
    QString name;
    int version;
    int generation;
    Human* savedHuman;
    Angel* leftChild;
    Angel* middleChild;
    Angel* rightChild;
};

struct AngelTree{
    int levels;
    int generations;
    Angel* root;
    QString angelNames[10] =  {"Miguel", "Nuriel", "Aniel", "Rafael", "Gabriel", "Shamsiel", "Raguel", "Uriel", "Azael", "Sariel"};
};


// -------------------------------------- ESTRUCTURA PRINCIPAL ------------------------------------- //
// estructura principal que contiene todas las demas estructuras
struct Universe{
public:
    // las estructuras principales el mundo, infierno y cielo
    TheWorld * world;
    Hell * hell;
    Heaven* heaven;

    // esta en orden los demonios con su pecado y el pecado con su antagonico
    QString goodActions[7] = {"Castidad", "Ayuno", "Donación", "Diligencia", "Calma", "Solidaridad", "Humildad"};

    QString sinsActions[7] = {"Lujuria",  "Gula", "Avaricia", "Pereza", "Ira", "Envidia", "Soberbia"};

    QString demonsName[7] = {"Asmodeo", "Belfegor", "Mammon", "Abadon", "Satan", "Belcebu", "Lucifer" };

public:
    Universe();


};




#endif // STRUCTS_H
