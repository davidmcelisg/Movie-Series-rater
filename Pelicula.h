//
//  main.cpp
//  Sit_Problema
//
// Creado por by David Martinez Celis González A01721021
// 01/06/2021-07/06/2021
/*
 La clase Pelicula, derivada o hija de la clase Video, hereda los atributos y métodos de esa y pues también aplica los que aplican únicamente para los videos, que en este caso consiste de puros métodos
 */

#ifndef Pelicula_h
#define Pelicula_h
#pragma once
#include"Video.h"

class Pelicula : public Video {
  public:
    Pelicula();
    Pelicula(int, string, double, string, int);
    void imprimir();
};

//Constructor: constructir sin parámetros de objeto Pelicula
//Parámetros entrada: Ninguno
//Parámetros salida: Ninguno
Pelicula::Pelicula() : Video() {
}

//Constructor: constructir con parámetros de objeto Pelicula
//Parámetros entrada: int i, string n, double d, string g, int c
//Parámetros salida: Ninguno
Pelicula::Pelicula(int i, string n, double d, string g, int c) : Video(i, n, d, g, c) {
}

//imprimir: permite imprimir los atributos de una película en un formato especial por polimorfismo
//Parámetros entrada: Ninguno
//Parámetros salida: Ninguno
void Pelicula::imprimir() {
  cout << "Película: " << Video::getNombre() << " con ID: " << Video::getID() << " del género: " << Video::getGenero() << ", con duración de " << Video::getDuracion() <<  " y con calificación de: " << Video::getCalificacion() << endl;
}

#endif /* Pelicula_h */
