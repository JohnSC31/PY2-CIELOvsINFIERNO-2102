#include <structs.h>

int Heaven::hashFunction(int id){
    //int id = theHuman->id;
    int sum = 0;
    while(id != 0){
        sum = sum + id%10;
        id = id/10;
    }
    return sum;
}

void Heaven::insert(Human * theHuman){
    int hashId = hashFunction(theHuman->id);
    //heavenList[hashId]->insert(heavenList[hashId], theHuman);
    HeavenTree* hashNode = heavenList[hashId];
    hashNode->insert(hashNode->root, theHuman);
}
