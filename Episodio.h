//
//  main.cpp
//  Sit_Problema
//
// Creado por by David Martinez Celis González A01721021
// 01/06/2021-07/06/2021
/*
 La clase Episodio, derivada o hija de la clase Video, hereda los atributos y métodos de esa y pues también aplica los que aplican únicamente para los episodios
 */

#ifndef Episodio_h
#define Episodio_h
#pragma once
#include"Video.h"

class Episodio : public Video {
  private:
    string nombreSerie;
    string temporada;
    string numEpisodio;
  public:
    Episodio();
    Episodio(int, string, double, string, int, string, string, string);
    void setTemporada(string);
    string getTemporada();
    void setNumEp(string);
    string getNumEp();
    void setNombreSerie(string);
    string getNombreSerie();
    void imprimir();
};

//Constructor: constructir sin parámetros de objeto Pelicula
//Parámetros entrada: Ninguno
//Parámetros salida: Ninguno
Episodio::Episodio() : Video() {
    nombreSerie = "";
    temporada = "";
    numEpisodio = "";
}

//Constructor: constructir con parámetros de objeto Pelicula
//Parámetros entrada: int i, string n, double d, string g, int c, string nS, string t, string nE
//Parámetros salida: Ninguno
Episodio::Episodio(int i, string n, double d, string g, int c, string nS, string t, string nE) : Video(i, n, d, g, c) {
  temporada = t;
  numEpisodio = nE;
  nombreSerie = nS;
}

//setTemporada: permite redefinir el atributo temporada
//Parámetros entrada: temporada de tipo string
//Parámetros salida: Ninguno
void Episodio::setTemporada(string t) {
  temporada = t;
}

//getTemporada: permite recibir el atributo temporada
//Parámetros entrada: Ninguno
//Parámetros salida: temporada de tipo string
string Episodio::getTemporada() {
  return temporada;
}

//setNumEp: permite redefinir el atributo numEpisodio
//Parámetros entrada: numEpisodio de tipo string
//Parámetros salida: Ninguno
void Episodio::setNumEp(string nE) {
  numEpisodio = nE;
}

//getNumEp: permite recibir el atributo numEpisodio
//Parámetros entrada: Ninguno
//Parámetros salida: numEpisodio de tipo string
string Episodio::getNumEp() {
  return numEpisodio;
}

//setNombreSerie: permite redefinir el atributo nombreSerie
//Parámetros entrada: nombreSerie de tipo string
//Parámetros salida: Ninguno
void Episodio::setNombreSerie(string nS) {
  nombreSerie = nS;
}

//getNombreSerie: permite recibir el atributo nombreSerie
//Parámetros entrada: Ninguno
//Parámetros salida: nombreSerie de tipo string
string Episodio::getNombreSerie() {
  return nombreSerie;
}

//imprimir: permite imprimir los atributos de un episodio en un formato especial por polimorfismo
//Parámetros entrada: Ninguno
//Parámetros salida: Ninguno
void Episodio::imprimir() {
  cout << "Episodio: " << Video::getNombre() << " con ID: " << Video::getID() << " de la serie " << nombreSerie << ", temp: " << temporada << ", ep: " << numEpisodio << ". Duración: " << Video::getDuracion() << ". Género: " << Video::getGenero() << ". Calificación del episodio: " << Video::getCalificacion() << endl;
}

#endif /* Episodio_h */
