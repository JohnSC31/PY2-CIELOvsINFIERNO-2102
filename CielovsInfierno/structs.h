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
struct World; // la lista de personas

struct PeopleTree; // arbol binario de busqueda
struct TreeNode; // nodos del arbol


// -------------------------------------- ESTRUCTURAS DEL MUNDO ------------------------------------ //
struct Human{
public:
    int id;
    QString name;
    QString lastName;
    QString country;
    QString belief;
    QString profession;
    QString email;
    tm fecha; //Componente ctime para tiempo actual
    //Lista Pecados
    //Lista Buenas Acciones
    //Lista Hijos

public:
    Human(){
        id = 0;
        name = "";
        lastName = "";
        country = "";
        belief = "";
        profession = "";
        email = "";
    }
};

struct HumanNode{
public:
    Human* human;
    HumanNode* next;
    HumanNode* past; //Se puede cambiar por last, etc.
};

struct World{
public:
    HumanNode* firstNode;
    int numHumans;
};

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
    PeopleTree(World * world, PeopleTree * oldPeopleTree);
    void insert(HumanNode * _humanNode);
    TreeNode * insert(int _personId, HumanNode * _personeNode, TreeNode * node);
    HumanNode * search(int personId, TreeNode * node);
    PeopleTree * generateTree(World * world);
    bool isLeaf(TreeNode * node);
};

// -------------------------------------- ESTRUCTURAS PARA EL INFIERNO ----------------------------- //


// -------------------------------------- ESTRUCTURAS PARA EL CIELO -------------------------------- //





#endif // STRUCTS_H
