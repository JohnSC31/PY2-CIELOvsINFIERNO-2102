#ifndef STRUCTS_H
#define STRUCTS_H

#include <QString>
#include <QQueue>
#include <QtCore>
#include <QDebug>
#include <QFile>

// Definicion de las todas las estructuras para el proyecto


// -------------------------------------- PROTOTIPOS -----------------------------------------------//
struct Human; // persona
struct HumanNode; // nodo de personas
struct HumanList; // la lista de personas
struct Actions; // Pecados y buenas acciones

struct PeopleTree; // arbol binario de busqueda
struct TreeNode; // nodos del arbol

struct TheWorld;

// condenación


struct Demons;
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
    //Lista Pecados
    //Lista Buenas Acciones
    //Lista Hijos

public:
    Human();
    Human(int _id, QString _name, QString _lastName, QString _country, QString belief, QString _profession);
};

struct HumanNode{
public:
    Human* human;
    HumanNode* next;
    HumanNode* past; //Se puede cambiar por last, etc.
};

struct HumanList{
public:
    HumanNode* firstNode;
    int length;


public:
    HumanList();
    void insertHuman(Human * newHuman);
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
    TreeNode * insert(int _personId, HumanNode * _personeNode, TreeNode * node);
    HumanNode * search(int personId, TreeNode * node);
    bool isLeaf(TreeNode * node);
};

// -------------------------------------- ESTRUCTURA PARA LAS BUENAS Y MALAS ACCIONES ----------------------------- //

struct Actions{
    QString type = "";
    int goods[7] = {0,0,0,0,0,0,0}; // Contador de buenas acciones
    int sinsCommited[7] = {0,0,0,0,0,0,0}; // Contador de pecaados
    //Estos QString sirven para imprimir los pecados e identificarlos en el programa
    QString goodActions[7] = {"Castidad", "Ayuno", "Donación", "Diligencia", "Calma", "Solidaridad", "Humildad" };
    QString sins[7] = {"Lujuria",  "Gula", "Avaricia", "Pereza", "Ira", "Envidia", "Soberbia"};
    //Procedimientos
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
    int treeCounter;
    int genTree;
    // Lista de datos para la generacion de un humano
    QString namesList[1000];
    QString lastNamesList[1000];
    QString beliefsList[10];
    QString countriesList[100];
    QString jobsList[65];
    bool usedNumbers[10000];

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

    // inicializacion para los datos para la generacion de humanos
    void initHumanIdList();
    void initNamesList();
    void initLastNamesList();
    void initBeliefsList();
    void initCountriesList();
    void initJobsList();


};

//Condenación

struct Demons{
    QString demons[7] = {"Lucifer", "Belcebú", "Satán", "Abadón", "Mammón", "Belfegor", "Asmodeo"};
};



// -------------------------------------- ESTRUCTURAS PARA EL INFIERNO ----------------------------- //


// -------------------------------------- ESTRUCTURAS PARA EL CIELO -------------------------------- //





#endif // STRUCTS_H
