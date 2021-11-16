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
    father = NULL; // todos nacen sin ser papas
    actions = new Actions();
    childList = new HumanList();
}

// impresion en consola de la informacion del humano
void Human::print(){
    QString str = "Humano:";
    str += name + " " + lastName + " pais:" + country;

    qDebug() << str.toUtf8();
}
