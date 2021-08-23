//
//  main.cpp
//  Sit_Problema
//
// Creado por by David Martinez Celis González A01721021
// 01/06/2021-07/06/2021
/*
 La clase Serie define a una serie en general, en donde por medio de composición incluye un arreglo de objetos de tipo episodio, donde se guardan los episodios de dicha serie
 */

#ifndef Serie_h
#define Serie_h
#pragma once
#include"Episodio.h"

class Serie {
  private:
    string nombreSerie;
    int idSerie;
    Episodio arrEpisodios[100];
    int numEpisodios;
public:
    Serie();
    Serie(string, int, int);
    void setNombreSerie(string);
    string getNombreSerie();
    void setIdSerie(int);
    int getIdSerie();
    void setNumEpisodios(int);
    int getNumEpisodios();
    void imprimirS();
    void imprimirEpisodios();
    void agregarEpisodio(Episodio);
};

//Constructor: constructir sin parámetros de objeto Serie
//Parámetros entrada: Ninguno
//Parámetros salida: Ninguno
Serie::Serie() {
    nombreSerie = "";
    idSerie = 0;
    numEpisodios = 0;
}

//Constructor: constructir con parámetros de objeto Serie
//Parámetros entrada: string nS, int iS, int nE
//Parámetros salida: Ninguno
Serie::Serie(string nS, int iS, int nE) {
    nombreSerie = nS;
    idSerie = iS;
    numEpisodios = nE;
}

//setNombreSerie: permite redefinir el atributo nombreSerie
//Parámetros entrada: nombreSerie de tipo string
//Parámetros salida: Ninguno
void Serie::setNombreSerie(string nS) {
    nombreSerie = nS;
}

//getNombreSerie: permite recibir el atributo nombreSerie
//Parámetros entrada: Ninguno
//Parámetros salida: nombreSerie de tipo string
string Serie::getNombreSerie() {
    return nombreSerie;
}

//setIdSerie: permite redefinir el atributo idSerie
//Parámetros entrada: idSerie de tipo int
//Parámetros salida: Ninguno
void Serie::setIdSerie(int iS) {
    idSerie = iS;
}

//getIdSerie: permite recibir el atributo idSerie
//Parámetros entrada: Ninguno
//Parámetros salida: idSerie de tipo int
int Serie::getIdSerie() {
    return idSerie;
}

//setNumEpisodios: permite redefinir el atributo numEpisodios
//Parámetros entrada: numEpisodios de tipo int
//Parámetros salida: Ninguno
void Serie::setNumEpisodios(int nE) {
    numEpisodios = nE;
}

//getNumEpisodios: permite recibir el atributo numEpisodios
//Parámetros entrada: Ninguno
//Parámetros salida: numEpisodios de tipo int
int Serie::getNumEpisodios() {
    return numEpisodios;
}

//imprimirS: permite imprimir los atributos de una serie en un formato especial
//Parámetros entrada: Ninguno
//Parámetros salida: Ninguno
void Serie::imprimirS() {
    cout << "Serie " << nombreSerie << "con ID de: " << idSerie << " . Total de episodios: " << numEpisodios << endl;
}

//imprimirEpisodios: permite imprimir los episodios del arreglo de episodios una serie utilizando un for para imprimir cada uno, y pues aprovechando utilizar el método de imprimir de episodios
//Parámetros entrada: Ninguno
//Parámetros salida: Ninguno
void Serie::imprimirEpisodios() {
    for (int i=0;i<numEpisodios;i++) {
        arrEpisodios[i].imprimir();
    }
}

//agregarEpisodios: permite agregar un episodio al arreglo de episodios una serie
//Parámetros entrada: Ninguno
//Parámetros salida: Ninguno
void Serie::agregarEpisodio(Episodio e) {
    arrEpisodios[numEpisodios]=e;
    numEpisodios++;
}

#endif /* Serie_h */
