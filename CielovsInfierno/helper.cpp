#include "helper.h"

// validacion de los strings del usuario
bool validStr(QString str){
    return str != "";
}
// recibe un string y verifica si se puede convertir a number
bool validNumber(QString strNumber){
    try {
        if(validStr(strNumber)){
            double number = strNumber.toDouble();
            return true; // puede ser converido a double
        }else
            return false;

    }  catch (...) {
        return false;
    }
}
