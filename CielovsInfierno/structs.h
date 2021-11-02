#ifndef STRUCTS_H
#define STRUCTS_H

#include <QString>
#include <QQueue>
#include <QtCore>
#include <QDebug>

// Definicion de las todas las estructuras para el proyecto


// -------------------------------------- PROTOTIPOS -----------------------------------------------//
struct Person; // persona
struct PersonNode; // nodo de personas
struct World; // la lista de personas

struct PeopleTree; // arbol binario de busqueda
struct TreeNode; // nodos del arbol


// -------------------------------------- ESTRUCTURAS DEL MUNDO ------------------------------------ //
struct TreeNode{
public:
    int personId;
    PersonNode * personNode;
    TreeNode * leftChild; // hijo izquierdo
    TreeNode * rightChild; // hijo derecho

public:
    TreeNode(PersonNode * _personNode, int _personId){
        personNode = _personNode;
        personId = _personId;
        leftChild = rightChild = NULL;
    }
};

struct PeopleTree{
public:
    TreeNode * root;

public:
    PeopleTree(World * world, PeopleTree * oldPeopleTree);
    void insert(PersonNode * _personNode);
    TreeNode * insert(int _personId, PersonNode * _personeNode, TreeNode * node);
    PersonNode * search(int personId, TreeNode * node);
    PeopleTree * generateTree(World * world);
    bool isLeaf(TreeNode * node);
};

// -------------------------------------- ESTRUCTURAS PARA EL INFIERNO ----------------------------- //


// -------------------------------------- ESTRUCTURAS PARA EL CIELO -------------------------------- //





#endif // STRUCTS_H
