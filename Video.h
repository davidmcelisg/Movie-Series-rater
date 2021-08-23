//
//  main.cpp
//  Sit_Problema
//
// Creado por by David Martinez Celis González A01721021
// 01/06/2021-07/06/2021
/*
 La clase video es la clase padre de película y episodio, donde se crean los atributos y métodos correspondientes, que aplican de la misma manera tanto para las películas como para los episodios, esto con el fin de reducir la cantidad de código escrito
 */

#ifndef Video_h
#define Video_h
#pragma once
#include"Video.h"

class Video {
  public:
    int id;
    string nombre;
    double duracion;
    string genero;
    int calificacion;
  public:
    Video();
    Video(int, string, double, string, int);
    void setID(int);
    int getID();
    void setNombre(string);
    string getNombre();
    void setDuracion(double);
    double getDuracion();
    void setGenero(string);
    string getGenero();
    void setCalificacion(int);
    int getCalificacion();
    virtual void imprimir()=0;
};

//Constructor: constructir sin parámetros de objeto Video
//Parámetros entrada: Ninguno
//Parámetros salida: Ninguno
Video::Video() {
  id = 0;
  nombre = "";
  duracion = 0;
  genero = "";
  calificacion = 0;
}

//Constructor: constructir con parámetros de objeto Video
//Parámetros entrada: int i, string n, double d, string g, int c
//Parámetros salida: Ninguno
Video::Video(int i, string n, double d, string g, int c) {
  id = i;
  nombre = n;
  duracion = d;
  genero = g;
  calificacion = c;
}

//setID: permite redefinir el atributo id
//Parámetros entrada: id de tipo int
//Parámetros salida: Ninguno
void Video::setID(int i) {
  id = i;
}

//getID: permite recibir el atributo id
//Parámetros entrada: Ninguno
//Parámetros salida: id de tipo int
int Video::getID(){
  return id;
}

//setNombre: permite redefinir el atributo nombre
//Parámetros entrada: nombre de tipo string
//Parámetros salida: Ninguno
void Video::setNombre(string n) {
  nombre = n;
}

//getNombre: permite recibir el atributo nombre
//Parámetros entrada: Ninguno
//Parámetros salida: nombre de tipo string
string Video::getNombre() {
  return nombre;
}

//setDuracion: permite redefinir el atributo duracion
//Parámetros entrada: duracion de tipo double
//Parámetros salida: Ninguno
void Video::setDuracion(double d) {
  duracion = d;
}

//getDuracion: permite recibir el atributo duracion
//Parámetros entrada: Ninguno
//Parámetros salida: duracion de tipo double
double Video::getDuracion() {
  return duracion;
}

//setGenero: permite redefinir el atributo genero
//Parámetros entrada: genero de tipo string
//Parámetros salida: Ninguno
void Video::setGenero(string g) {
  genero = g;
}

//getGenero: permite recibir el atributo genero
//Parámetros entrada: Ninguno
//Parámetros salida: genero de tipo string
string Video::getGenero() {
  return genero;
}

//setCalificacion: permite redefinir el atributo calificacion
//Parámetros entrada: calificacion de tipo int
//Parámetros salida: Ninguno
void Video::setCalificacion(int c) {
  calificacion = c;
}

//getCalificacion: permite recibir el atributo calificaion
//Parámetros entrada: Ninguno
//Parámetros salida: calificacion de tipo int
int Video::getCalificacion() {
  return calificacion;
}

//el método imprimir() no se define ya que es de tipo virutal, y por polimorfismo se definirá dentro de sus clases hijas para aplicar funciones diferentes

#endif /* Video_h */
