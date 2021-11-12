#ifndef STRUCTS_H
#define STRUCTS_H

#include <QString>
#include <QQueue>
#include <QtCore>
#include <QDebug>
#include <QFile>
#include <QtGlobal>

// Definicion de las todas las estructuras para el proyecto


// -------------------------------------- PROTOTIPOS -----------------------------------------------//
struct Human; // persona
struct HumanNode; // nodo de personas
struct HumanList; // la lista de personas
struct Actions; // Pecados y buenas acciones

struct PeopleTree; // arbol binario de busqueda
struct TreeNode; // nodos del arbol

struct TheWorld;

struct Demon;
struct FamilyNode;
struct DemonFamilies; // heap donde se almacenan las familias


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
    HumanNode * father; // para asignarle o saber si ya tiene un padre
    Actions * actions;
    HumanList * childList; // lista de hijos

public:
    Human();
    Human(int _id, QString _name, QString _lastName, QString _country, QString belief, QString _profession, QString email);
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
    void insertMiddle(Human * newHuman, HumanNode * preInsertNode);
    bool isEmpty();
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
};

// -------------------------------------- ESTRUCTURA PARA LAS BUENAS Y MALAS ACCIONES ----------------------------- //

struct Actions{

public:
    QString type = "";
    int goods[7] = {0,0,0,0,0,0,0}; // Contador de buenas acciones
    int sinsCommited[7] = {0,0,0,0,0,0,0}; // Contador de pecaados
    //Estos QString sirven para imprimir los pecados e identificarlos en el programa
    QString goodActions[7] = {"Castidad", "Ayuno", "Donación", "Diligencia", "Calma", "Solidaridad", "Humildad" };
    QString sins[7] = {"Lujuria",  "Gula", "Avaricia", "Pereza", "Ira", "Envidia", "Soberbia"};

public:
    //Procedimientos
    Actions(); // constructor
    void addGoods();
    void addSins();
    void printGoods();
    void printSins();
    int countGoods();
    int countSins();

};


// --------------------- ESTRUCTURAS DEL MUNDO -----------------
struct TheWorld{
public:
    HumanList * humanList; // lista de humanos doblemente enlazada
    PeopleTree * peopleTree; // arbol de personas
    int treeCounter; // contador actual hasta llegar a generar un arbol
    int genTree; // cada cuanto se genera un arbol
    // Lista de datos para la generacion de un humano
    QString namesList[100];
    QString lastNamesList[100];
    QString beliefsList[10];
    QString countriesList[10];
    QString jobsList[20];
    bool usedNumbers[100000];

    //ui

public:
    TheWorld();
    void generateHumans(int numHumans);
    HumanNode * searchHuman(int humanId);
    void printData();
    bool validHumanId(); // si se puede crear un humano con ese id
    void asignChilds(int childNum, HumanNode * humanNode);

    // suma de pecados y buenas acciones
    void sumOfActions();
    int genHumanId();
    bool validHumanId(int newHumanId);

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





#endif // STRUCTS_H
