#include <structs.h>

void HumanList::generaterNumList(){
    // el minimo son 10000, pero el max son 100 000
    for(int i = 0; i < 10000; i++){
        usedNumbers[i] = false;
    }
}

void HumanList::generateNames(){
    QString filePath = QDir::currentPath() + "/../Names.txt";
    QFile file(filePath);
    QTextStream in(&file);
    int i = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        namesList[i] = line;
        i++;
    }
    file.close();
}

void HumanList::generateLastNames(){
    QString filePath = QDir::currentPath() + "/../Lastnames.txt";
    QFile file(filePath);
    QTextStream in(&file);
    int i = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        lastNamesList[i] = line;
        qDebug() << line;
        i++;
    }
    file.close();
}

void HumanList::generateBeliefs(){
    QString filePath = QDir::currentPath() + "/../Beliefs.txt";
    QFile file(filePath);
    QTextStream in(&file);
    int i = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        beliefsList[i] = line;
        qDebug() << line;
        i++;
    }
    file.close();
}

void HumanList::generateCountries(){
    QString filePath = QDir::currentPath() + "/../Countries.txt";
    QFile file(filePath);
    QTextStream in(&file);
    int i = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        countriesList[i] = line;
        qDebug() << line;
        i++;
    }
    file.close();
}

void HumanList::generateJobs(){
    QString filePath = QDir::currentPath() + "/../Works.txt";
    QFile file(filePath);
    QTextStream in(&file);
    int i = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        namesList[i] = line;
        qDebug() << line;
        i++;
    }
    file.close();
}


