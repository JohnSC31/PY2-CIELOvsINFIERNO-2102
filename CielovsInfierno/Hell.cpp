#include "structs.h"


Hell::Hell(HumanList * humanListWorld, QString _demonsName[7], QString _sinsActions[7], QString _goodActions[7]){

    // se asigna los valores a los arreglos locales
    for(int i = 0; i < 7; i++){
        demonsName[i] = _demonsName[i];
        demonsSin[i] = _sinsActions[i];
        antagonistic[i] = _goodActions[i];
    }


    initDemons();
    humansWorld = humanListWorld;
}


// inicializa a los demonios con su pecado y nombre
void Hell::initDemons(){
    for(int i = 0; i < 7; i++){
        demons[i] = new Demon(demonsName[i], demonsSin[i]);
    }
}


// se realiza la condenacion del mundo
void Hell::condemnation(QString demonName){
    Demon * demon = searchDemon(demonName);
    HumanNode * tmpHuman = humansWorld->firstNode;
    QList<Human *> humans;
    QMultiMap<int, Human *> map;
    while(tmpHuman != NULL){
        if(tmpHuman->human->state == 0){
            map.insert(tmpHuman->human->getNetSin(demon->sin), tmpHuman->human);
        }
        tmpHuman = tmpHuman->next;
    }

    humans = map.values(); // estan acomodados de menor a mayor
    demon->demonCondemnation(humans, humansWorld->getLength() * 5 / 100, getAntagonistic(demon->sin));
}


Demon * Hell::searchDemon(QString name){
    for(int i = 0; i < 7; i++){
        if(demons[i]->name == name){
            // encontramos al demonio
            return demons[i];
        }
    }
    return NULL;
}


// obtiene el antagonico del pecado dado
QString Hell::getAntagonistic(QString sin){
    for(int i = 0; i < 7; i++){
        if(demonsSin[i] == sin){
            return antagonistic[i];
        }
    }

    return "X";
}


// Consulta de demonios y todos sus valores
void Hell::demonQuery(QString demonName){
    Demon * demon = searchDemon(demonName);
    if(demon != NULL){
        demon->demonQuery();
    }else{
        qDebug() << "Demonio no encontrado para consultar";
    }
}
