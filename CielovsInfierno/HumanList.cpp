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

// a partir de un nodo de referencia un numero y direccion se mueve el numero indicado y retorna el nodo en el que quedo
// retornara nulo si se sale de la lista
HumanNode * HumanList::moveToNode(int move, bool right, HumanNode * refNode){
    HumanNode * tmp = refNode;
    for(int i = 0; i < move; i++){
        if(right){
            // se mueve a su derecha
            if(tmp->next != NULL){
                tmp = tmp->next;
            }else{
                return NULL; // llega al final de la lista
            }
        }else{
            // se mueve a su izquierda
            if(tmp->past != NULL){
                 tmp = tmp->past;
            }else{
                return NULL; // llega al inicio de la lista
            }
        }
    }

    return tmp;

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

// busca un humano
HumanNode * HumanList::searchHuman(int humanId, HumanNode * refNode){
    while(true){
        if(refNode->human->id == humanId){
            // lo encuentra
            return refNode;
        }else if(refNode->human->id < humanId){
            if(refNode->next == NULL){
                // llega al final de la lista
                return NULL;

            }else if(refNode->next->human->id > humanId){
                // deberia esta en el medio de dos nodos
                return NULL;

            }else{
                // se mueve a la derecha
                refNode = refNode->next;
            }
        }else if(refNode->past == NULL){
            //llega al inicio de la lista
            return NULL;

        }else{
            // se mueve a la izquierda
            refNode = refNode->past;
        }
    }
}


// obtiene he inserta en la lista de familia a todos los humanos de esa familia
HumanList * HumanList::getFamilyOf(HumanNode * human){
    HumanNode * tmp = firstNode;
    HumanList * family = new HumanList();
    while(tmp != NULL){

        if(tmp->human->country == human->human->country && tmp->human->lastName == human->human->lastName){
            family->insertHuman(tmp->human);
            // se agrega a la familia
        }

        tmp = tmp->next;
    }

    return family;
}



// obtiene si la list esta vacia
bool HumanList::isEmpty(){
    return firstNode == NULL;
}

// cantidad de humanos totales de la lista
int HumanList::getLength(){
    return length;
}

