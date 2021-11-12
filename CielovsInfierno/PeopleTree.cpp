#include "structs.h"

// genera un arbol vacio
PeopleTree::PeopleTree(){
    root = NULL;
}


// funcion para generar un arbol a partir de
// una lista doblemente enlazada de personas
// convierte el arbol actual en uno nuevo
PeopleTree::PeopleTree(HumanList * humanList){

    int nodeAmount = getNodeTreeAmount(humanList->length); // iteraciones
    HumanNode * rootHumanNode = humanList->getMidHuman(); // debe ser el que esta en la mitad
    root = new TreeNode(rootHumanNode, rootHumanNode->human->id);
    int insertJump = humanList->length / nodeAmount;

    HumanNode * pastTmp = rootHumanNode; // inician en el medio
    HumanNode * nextTmp = rootHumanNode; // inician en el medio

    bool nextInsert = true; // cuando llega al final de a lista ya no inserta mas
    bool pastInsert = true; // cunado llega al inicio de la lista no inserta mas

    for(int i = 0; i < nodeAmount; i++){
        while(insertJump > 0){
            if(nextTmp != humanList->lastNode){
               nextTmp = nextTmp->next; // se mueve a la derecha
            }else{
                nextInsert = false;
            }

            if(pastTmp != humanList->firstNode){
                pastTmp = pastTmp->past; // se mueve a la izq
            }else{
                pastInsert = false;
            }
        } // while

        if(nextInsert){
            insert(nextTmp); // se insertan en el arbol
        }

        if(pastInsert){
            insert(pastTmp); // se insertan en el arbol
        }

         insertJump = humanList->length / nodeAmount; // recetea el salto de inserccion

    }//for
}

// determinar la cantidad de nodos a insertar para la lista dada y que sea completo
int PeopleTree::getNodeTreeAmount(int lengthList){
    int powCounter = 0;

    while(1 * lengthList / 100 > pow(2, powCounter)){
        powCounter++;
    }

    // retorna la potencia de 2 mayor mas cercana al uno por ciento
    return pow(2, powCounter);
}


void PeopleTree::insert(HumanNode * newHumanNode){
     root = insert(newHumanNode->human->id, newHumanNode, root);
    // descomentar despues de que se completen las estructuras para las personas y
    // la lista de personas
}

TreeNode * PeopleTree::insert(int _personId, HumanNode * _personeNode, TreeNode * node){

          if (node == NULL){
                    return new TreeNode(_personeNode, _personId);

          }else if (node->personId < _personId){
            node->rightChild = insert(_personId, _personeNode, node->rightChild);

          }else if (node->personId >= _personId){
             node->leftChild = insert(_personId, _personeNode, node->leftChild);

          }

          return node;
}


HumanNode * PeopleTree::search(int personId, TreeNode * node)
 {
     // cuando el nodo es nulo, quiere decir que allí debe
     // ubicar el valor, en un nuevo nodo
     if (isLeaf(node)){
         // llegamos al final del arbol
         return node->humanNode;

     }else if (node->personId == personId){
        return node->humanNode;

     }else if (node->personId < personId){
        return search(personId, node->rightChild);

     }else{
        return search(personId, node->leftChild);

     }

 }


// para saber si el nodo es hoja del arbol o no
bool PeopleTree::isLeaf(TreeNode *node){
    return node->leftChild == NULL && node->rightChild == NULL;
}
