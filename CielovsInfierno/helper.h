#ifndef HELPER_H
#define HELPER_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>


bool validStr(QString str);
bool validNumber(QString strNumber);

QString capitalize(QString str);

int maxInt(int a, int b);

bool writeFile(QString path, QString text);


#endif // HELPER_H
