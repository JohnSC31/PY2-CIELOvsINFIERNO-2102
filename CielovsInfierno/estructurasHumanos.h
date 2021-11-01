#ifndef ESTRUCTURASHUMANOS_H
#define ESTRUCTURASHUMANOS_H

#endif // ESTRUCTURASHUMANOS_H
#include <QString>
#include <ctime>

struct Humano{
    int id;
    QString nombre;
    QString apellido;
    QString pais;
    QString creencia;
    QString profesion;
    QString correo;
    tm fecha;
    //Lista Pecados
    //Lista Buenas Acciones
    //Lista Hijos

    Humano(){
        id = 0;
        nombre = "";
        apellido = "";
        pais = "";
        creencia = "";
        profesion = "";
        correo = "";
    }

    void generarHumano(void);
};

struct NodoHumano{
    Humano* humano;
    NodoHumano* anterior;
    NodoHumano* siguiente;
};

struct ListaHumanos{
    NodoHumano* primerNodo;
    int cantidadHumanos;
};
