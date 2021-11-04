#include "structs.h"

// funcion para generar un arbol a partir de
// una lista doblemente enlazada de personas
// convierte el arbol actual en uno nuevo
PeopleTree::PeopleTree(World * world, PeopleTree * oldPeopleTree){

    // determinar los nodos a insertar en el nuevo arbol
    // sacando el 1% de la lista y tomando la potencia de 2 mayor mas cercana

    // colocar la raiz que sea el nodo persona que esta en el medio de la lista
    // dividir en 2 el length de world y recorrelo y tomar el del medio (redondear hacia arriba)

    // determinar los saltos para la inserccion en el arbol
    // world.length / nodos a insertar (indicara cada cuantos hay que insertar un nodo)

    // for para world y cada que el contador de saltos llegue a cero se hace la insercion del nodo persona en el que se
    // encuentra y se reestablece

}

void PeopleTree::insert(HumanNode * newPersoneNode){
//     root = insert(newPersoneNode->person->id, newPersoneNode, root);
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
