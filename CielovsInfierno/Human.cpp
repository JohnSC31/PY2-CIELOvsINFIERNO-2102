#include "structs.h"


Human::Human(){
        id = 0;
        name = "";
        lastName = "";
        country = "";
        belief = "";
        profession = "";
        email = "";
}

Human::Human(int _id, QString _name, QString _lastName, QString _country, QString _belief, QString _profession, QString _email){
    id = _id;
    state = 0; // inician todos en el mundo
    name = _name;
    lastName = _lastName;
    country = _country;
    belief = _belief;
    profession = _profession;
    email = _email;
    // fecha en la que el humano fue creado
    dateBrith = QDateTime::currentDateTime().toString("aaaa-MM-dd hh: mm: ss dddd");
    father = NULL; // todos nacen sin tener papa
    childList = new HumanList();
}

// se agrega al pecado la cantidad correspondiente
void Human::addSin(QString sin, int amount){

    for(int i = 0; i < sins.length(); i++){
        if(sins.at(i)->action == sin){
            sins.at(i)->amount += amount;
            return;
        }
    }

    qDebug() << "el pecado no existe " + sin;
}

// retorna un string con todos los pecados y sus valores correspondiente
QString Human::sinsToString(){
    QString str = "";

    for(int i = 0; i < sins.length(); i++){
        str += sins.at(i)->action + " " + QString::number(sins.at(i)->amount) + "\t";
    }

    return str;
}

// se agrega a la buena accion la cantidad correspondiente
void Human::addGood(QString good, int amount){
   for(int i = 0; i < goods.length(); i++){
        if(goods.at(i)->action == good){
            goods.at(i)->amount += amount;
            return;
        }
    }

   qDebug() << "buena accion no existe " + good;
}

// retorna un string con todos las buenas acciones y sus valores correspondiente
QString Human::goodsToString(){
    QString str = "";
    for(int i = 0; i < goods.length(); i++){
        str += goods.at(i)->action + " " + QString::number(goods.at(i)->amount) + "\t";
    }

    return str;
}


QString Human::toString(){
    return QString::number(id) + " " + name + " " + lastName + " - " + country;
}

// retorna la cantidad de esa accion en especifico
int Human::getActionAmount(QString action){

    for(int i = 0; i < 7; i++){
        if(goods.at(i)->action == action){
            return goods.at(i)->amount;
        }
        if(sins.at(i)->action == action){
            return sins.at(i)->amount;
        }
    }

    return -1; // no existe la accion
}

// realiza la resta del pecado y su antagonico para devolver el pecado puro
int Human::getNetSin(QString sin){

    for(int i = 0; i < 7; i++){
        if(sins.at(i)->action == sin){
            // se retorna la cantidad de pecado menos su antagonico
            return sins.at(i)->amount - goods.at(i)->amount;
        }
    }

    qDebug() << "pecado neto inexistente";
    return -1; // no existe el pecado
}


// impresion en consola de la informacion del humano
void Human::print(){
    QString str = "Humano:";
    str += name + " " + lastName + " pais:" + country;

    qDebug() << str.toUtf8();
}
