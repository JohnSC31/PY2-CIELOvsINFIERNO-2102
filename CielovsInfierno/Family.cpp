#include "structs.h"



Family::Family(QString _lastname, QString _country){
    lastname = _lastname;
    country = _country;
    members = new HumanList();
    totalAction = 0;
}


int Family::getTotalAction(QString action){
    int total  = 0;
    HumanNode * tmp = members->firstNode;
    while(tmp != NULL){
        total += tmp->human->getActionAmount(action);

        tmp = tmp->next;
    }

    return total;
}

// agrega un miembro a la familia del infierno
void Family::insert(Human * human){
    members->insertHuman(human);
}

QString Family::membersToString(){
    QString str = "";
    HumanNode * tmp = members->firstNode;
    while(tmp != NULL){
        str += tmp->human->toString() + "\n";
        tmp = tmp->next;
    }

    return str;
}
