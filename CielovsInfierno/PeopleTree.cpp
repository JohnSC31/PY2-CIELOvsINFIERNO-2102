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

    for(int i = 0; i < nodeAmount / 2; i++){
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

            insertJump--;
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

TreeNode * PeopleTree::insert(int humanId, HumanNode * humanNode, TreeNode * node){

          if (node == NULL){
                    return new TreeNode(humanNode, humanId);

          }else if (node->personId < humanId){
            node->rightChild = insert(humanId, humanNode, node->rightChild);

          }else if (node->personId >= humanId){
             node->leftChild = insert(humanId, humanNode, node->leftChild);

          }

          return node;
}


HumanNode * PeopleTree::search(int humanId, TreeNode * node)
 {
     // cuando el nodo es nulo, quiere decir que allí debe
     // ubicar el valor, en un nuevo nodo
     if (isLeaf(node)){
         // llegamos al final del arbol
         return node->humanNode;

     }else if (node->personId == humanId){
        return node->humanNode;

     }else if (node->personId < humanId){
        return search(humanId, node->rightChild);

     }else{
        return search(humanId, node->leftChild);

     }

 }

// para saber si el nodo es hoja del arbol o no
bool PeopleTree::isLeaf(TreeNode *node){
    return node->leftChild == NULL && node->rightChild == NULL;
}


// retorna la cantidad de niveles del arbol
int PeopleTree::levels(){
    return auxLevels(root);
}

int PeopleTree::auxLevels(TreeNode * node){
    if (node == NULL){
        return -1;
    }else{
         return 1 + maxInt(auxLevels(node->leftChild),auxLevels(node->rightChild));

    }
}

// retorna la cantidad de nodos que tiene el arbol
int PeopleTree::nodesAmount(){
    return auxNodesAmount(root);
}

int PeopleTree::auxNodesAmount(TreeNode * node){
    if (node == NULL)
            return 0;
        else
             return 1 + auxNodesAmount(node->leftChild) + auxNodesAmount(node->rightChild);
}

// retona una qlist de los  humanos que estan en el ultimo nivel del arbol
QList<Human * > * PeopleTree::getLastLvlHumans(){
    QList<Human * > * lastLvlHumans = new QList<Human * >();
    auxGetLastLvlHumans(root, lastLvlHumans);
    return lastLvlHumans;
}

void PeopleTree::auxGetLastLvlHumans(TreeNode * node, QList<Human * > * humanList){
    if(node != NULL){
        if(isLeaf(node)){
            humanList->append(node->humanNode->human);
        }else{
            auxGetLastLvlHumans(node->leftChild, humanList);
            auxGetLastLvlHumans(node->rightChild, humanList);
        }
    }
}

