#include "structs.h"

HumanList::HumanList(){
        firstNode = NULL;
        lastNode = NULL;
        length = 0;
}

// insercion de un humano en la lista en orden sin el arbol
void HumanList::insertHuman(Human * newHuman){
    // cuando la lista esta vacia
    if(isEmpty()){
        insertBeginning(newHuman);
    }else if(firstNode == lastNode){
        // solo hay un nodo en la lista
        if(firstNode->human->id > newHuman->id){
            insertBeginning(newHuman);
        }else{
            insertEnd(newHuman);
        }
    }else{
        insertInOrder(newHuman, firstNode);
    }

}

// obtiene el humano que esta en el centro de la lista (o casi el centro)
HumanNode * HumanList::getMidHuman(){
    int counter = length / 2; // donde esta el medio de la lista
    HumanNode * tmp = firstNode;
    for(int i = 0; i < counter; i++){
        tmp = tmp->next; // corre haacia la derecha
    }
    return tmp; // retorna el que esta relativamente en el medio
}
\
// busca la posicion en la que se debe insertar el humano con el id cuando hay muchos nodos
void HumanList::insertInOrder(Human * newHuman, HumanNode * refNode){
    while(true){
        if(refNode->human->id < newHuman->id){
            if(refNode->next == NULL){
                insertEnd(newHuman);
                break;
            }else if(refNode->next->human->id > newHuman->id){
                insertMiddle(newHuman, refNode);
                break;
            }else{
                // se mueve a la derecha
                refNode = refNode->next;
            }
        }else if(refNode->past == NULL){
            insertBeginning(newHuman);
            break;
        }else{
            // se mueve a la izquierda
            refNode = refNode->past;
        }
    }
}



// inserciones especiales de la lista
void HumanList::insertBeginning(Human * newHuman){
    if(isEmpty()) firstNode = lastNode = new HumanNode(newHuman);

    else{
        firstNode->past = new HumanNode(newHuman);
        firstNode->past->next = firstNode;
        firstNode = firstNode->past;
    }

    length++;
}

void HumanList::insertEnd(Human * newHuman){
    if(isEmpty()) firstNode = lastNode = new HumanNode(newHuman);

    else{
        lastNode->next = new HumanNode(newHuman);
        lastNode->next->past = lastNode;
        lastNode = lastNode->next;
    }
    length++;
}

// la lista no debe estar vacia
// el nodo de referencia no puede ser el ultimo
// realiza una insercion en medio de 2 nodos con la referencia del que esta justo antes de donde ira el nuevo
void HumanList::insertMiddle(Human * newHuman, HumanNode * refNode){
    if(refNode != NULL && refNode->next != NULL){
        HumanNode * newNode = new HumanNode(newHuman);
        newNode->past = refNode;
        newNode->next = refNode->next;
        refNode->next = newNode;
        newNode->next->past = newNode;
    }

    length++;

}



// obtiene si la list esta vacia
bool HumanList::isEmpty(){
    return firstNode == NULL;
}

