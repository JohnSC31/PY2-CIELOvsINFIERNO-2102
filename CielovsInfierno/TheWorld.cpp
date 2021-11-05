#include "structs.h"


TheWorld::TheWorld(){
    humanList = new HumanList();
    peopleTree = new PeopleTree();
    treeCounter = 0; // contador para la generacion del arbol
    genTree = 100; // el minimo y cada cuanto se genera un nuevo arbol
}


// generacion de humanos
void TheWorld::generateHumans(int numHumans){

    for(int i = 0; i < numHumans; i++){
        //humanList->generateHuman();
    }

    // determinar cuando se genera un arbol nuevo
    treeCounter += numHumans;
    if(treeCounter >= genTree){
        // genera un arbol con la lista de humanos que este
        peopleTree = new PeopleTree(humanList);
        treeCounter = 0;
    }

}

// Hace pecar y realizar buenas acciones a todos los humanos
void TheWorld::sumOfActions(){
    // recorre la lista de humanos llamando a una funcion que le sume a cada uno
    // las buenas acciones y los pecados (con herencia)
}
