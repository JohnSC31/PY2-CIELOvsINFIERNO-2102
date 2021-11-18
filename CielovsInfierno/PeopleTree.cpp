#include "structs.h"

// genera un arbol vacio
PeopleTree::PeopleTree(){
    root = NULL;
}


// funcion para generar un arbol a partir de
// una lista doblemente enlazada de personas
// convierte el arbol actual en uno nuevo
PeopleTree::PeopleTree(HumanList * humanList){
    root = NULL;

    int nodeAmount = getNodeTreeAmount(humanList->length); // iteraciones
    int moveNode = humanList->length / 2;
    HumanNode * midNode = humanList->moveToNode(moveNode, true, humanList->firstNode);
    qDebug() << "mid id: " + QString::number(midNode->human->id);

    generateTree(humanList, midNode, moveNode, 1, nodeAmount);
}


void PeopleTree::generateTree(HumanList * list, HumanNode * node, int moveNode, int nodes, int totalAmount){
    if(node != NULL && nodes < totalAmount / 2){
        qDebug() << "Se insertara";
        insert(node); // inserta este nodo
        // recursion
        generateTree(list, list->moveToNode(moveNode / 2, false, node), moveNode / 2, nodes + 1, totalAmount);
        generateTree(list, list->moveToNode(moveNode / 2, true, node), moveNode / 2, nodes + 1, totalAmount);
    }
}

// determinar la cantidad de nodos a insertar para la lista dada y que sea completo
int PeopleTree::getNodeTreeAmount(int lengthList){
    int powCounter = 0;

    while(1 * lengthList / 100 > pow(2, powCounter)){
        powCounter++;
    }

    // retorna la potencia de 2 mayor mas cercana al uno por ciento
    // se le resta uno ya que se inserta la raiz antes
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
    return auxLevels(root) + 1;
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
QString PeopleTree::getLastLvlHumans(){

    return auxGetLastLvlHumans(root);
}

QString PeopleTree::auxGetLastLvlHumans(TreeNode * node){
        if (node == NULL){
            return "";
       }else if (isLeaf(node)){
            return node->humanNode->human->toString() + "\n";
       }else{
           return auxGetLastLvlHumans(node->leftChild) + auxGetLastLvlHumans(node->rightChild);
       }
}

int PeopleTree::getLeafAmount(TreeNode * node){
        if (node == NULL){
            return 0;
       }else if (isLeaf(node)){
            return 1;
       }else{
           return getLeafAmount(node->leftChild) + getLeafAmount(node->rightChild);
       }
}

void PeopleTree::printPreOrden(TreeNode * node){
    if (node != NULL){
         qDebug() << node->personId << "  ";
         printPreOrden(node->leftChild);
         printPreOrden(node->rightChild);
    }
}

