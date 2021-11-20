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


// coloca solo la primera letra en mayuscula y el resto en minusculas
QString capitalize(QString str){
    QString newStr;
    for(int i = 0; i < str.length(); i++){
        if(i == 0){
            newStr.append(str.at(i).toUpper());
        }else{
            newStr.append(str.at(i).toLower());
        }
    }

    return newStr;
}


// retorna el mayor entre 2 numeros enteros
int maxInt(int a, int b){
    return a > b ? a : b;
}

// escribir en un archivo txt
bool writeFile(QString fileName, QString text){
    QFile file(QDir::currentPath() + "/../" + fileName + ".txt");
    /*
     * If file not exit it will create
     * */
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text | QIODevice::ReadWrite)){
        qDebug() << "FAIL TO CREATE FILE / FILE NOT EXIT***";
        return false;
    }

    /*for writing line by line to text file */
//    if (file.open(QIODevice::ReadWrite)){
        QTextStream stream(&file);
        stream << text;
//    }

    return true;

}




