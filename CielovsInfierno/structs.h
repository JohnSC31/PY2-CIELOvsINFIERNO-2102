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

#include "helper.h"

// Definicion de las todas las estructuras para el proyecto


// -------------------------------------- PROTOTIPOS -----------------------------------------------//
struct Human; // persona
struct HumanNode; // nodo de personas
struct HumanList; // la lista de personas
struct Actions; // Pecados y buenas acciones
struct Action;

struct PeopleTree; // arbol binario de busqueda
struct TreeNode; // nodos del arbol

struct TheWorld;

struct Demon;
struct FamilyNode;
struct DemonFamilies; // heap donde se almacenan las familias


struct Universe;


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
    void addGood(QString good, int amount);
    QString toString();
    void print();
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
    // inserciones especiales
    void insertBeginning(Human * newHuman);
    void insertEnd(Human * newHuman);
    void insertMiddle(Human * newHuman, HumanNode * refNode);
    HumanNode * searchHuman(int humanId, HumanNode * refNode);
    bool isEmpty();
    int getLength();
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
    QString goodActions[7] = {"Castidad", "Ayuno", "Donación", "Diligencia", "Calma", "Solidaridad", "Humildad" };
    QString sinsActions[7] = {"Lujuria",  "Gula", "Avaricia", "Pereza", "Ira", "Envidia", "Soberbia"};

    //ui
    QLabel * lblTreeData;
    QLabel * lblLastLvlTree;

public:
    TheWorld();
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
    // inicializacion para los datos para la generacion de humanos
    void initHumanIdList();
    void initNamesList();
    void initLastNamesList();
    void initBeliefsList();
    void initCountriesList();
    void initJobsList();


};



// -------------------------------------- ESTRUCTURAS PARA EL INFIERNO ----------------------------- //


// -------------------------------------- ESTRUCTURAS PARA EL CIELO -------------------------------- //



// -------------------------------------- ESTRUCTURA PRINCIPAL ------------------------------------- //
// estructura principal que contiene todas las demas estructuras
struct Universe{
public:
    // las estructuras principales el mundo, infierno y cielo
    TheWorld * world;
    // infierno
    // cielo

public:
    Universe();


};




#endif // STRUCTS_H
