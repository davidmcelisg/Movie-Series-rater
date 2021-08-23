//
//  main.cpp
//  Sit_Problema
//
// Creado por David Martinez Celis González A01721021
// 01/06/2021-07/06/2021
/*
 El programa para la Situación Problema se encarga de desplegar un menú donde el usuario puede utilizar diferentes funciones. El código recibe dos archivos en un formato específico, uno con información acerca de videos, específicamente de Películas y Episodios de series, y otro con la información de Series. Con las funciones del menú, el usuario puede desplegar los videos de maneras diferentes, y siempre con sus respectivas calificaciones.
 */

#include <iostream>
#include<fstream>
using namespace std;
#include"Video.h"
#include"Pelicula.h"
#include"Episodio.h"
#include"Serie.h"

//Listado de variables a utilizar a lo largo del programa
Video *arrVideos[50];
Pelicula arrPeliculas[50];
Serie arrSeries[10];
int opcion = 1;
ifstream arch ("/Users/davidmartinezcelis/Desktop/Xcode/Sit_Problema/datosVideos.txt");
ifstream arch2 ("/Users/davidmartinezcelis/Desktop/Xcode/Sit_Problema/datosSeries.txt");
string tipo, nomSerie;
int id, idS;
string nombre, genero;
int duracion, calificacion;
string serie, ep, temp;
int numVid=0, numPeli=0, numSer=0;
int califEsc=0;
string genEsc, serEsc;
bool verificaSerie=false, verificaGenero=false;

//cargarArchivos: permite guardar los datos proporcionados dentro de los archivo de texto de datosVideos y datosSeries. Si los datos son correspondientes de una pelicula, se guardan en arreglo de apuntadores Video y en arreglo de objetos de Peliculas, si son episodios se guardan en arreglo de apuntadores Video y en arreglo de series, dentro de su arreglo de episodios correspondiente
//Parámetros entrada: Ninguno
//Parámetros salida: Ninguno
void cargaArchivos() {
    while (arch2 >> idS >> nomSerie) {
        arrSeries[numSer].setIdSerie(idS);
        arrSeries[numSer].setNombreSerie(nomSerie);
        numSer++;
    }
    
    while (arch >> tipo >> id >> nombre >> genero >> duracion >> calificacion) {
        if (tipo == "e") {
            arch >> serie >> ep >> temp;
            arrVideos[numVid]=new Episodio(id, nombre, duracion, genero, calificacion, serie, temp, ep);
            Episodio epi(id, nombre, duracion, genero, calificacion, serie, temp, ep);
            for (int i=0;i<numSer;i++) {
                if (arrSeries[i].getNombreSerie() == epi.getNombreSerie()) {
                    arrSeries[i].agregarEpisodio(epi);
                }
            }
            } else {
                arrVideos[numVid]=new Pelicula(id, nombre, duracion, genero, calificacion);
                arrPeliculas[numPeli].setID(id);
                arrPeliculas[numPeli].setNombre(nombre);
                arrPeliculas[numPeli].setGenero(genero);
                arrPeliculas[numPeli].setDuracion(duracion);
                arrPeliculas[numPeli].setCalificacion(calificacion);
                numPeli++;
            }
        numVid++;
        }
    arch.close();
    arch2.close();
}

//listaPeliculas: permite desplegar todas las peliculas incluidas dentro del archivo de texto
//Parámetros entrada: Ninguno
//Parámetros salida: Ninguno
void listaPeliculas() {
    for (int i=0;i<numPeli;i++) {
        arrPeliculas[i].imprimir();
    }
}

//listaSeries: permite desplegar todas las series incluidas dentro del archivo de texto
//Parámetros entrada: Ninguno
//Parámetros salida: Ninguno
void listaSeries() {
    for (int i=0;i<numSer;i++){
        arrSeries[i].imprimirS();
    }
}

//videosxCalificacion: permite desplegar todos los videos de una calificacion específica. Si el usuario ingresa algun número que no está dentro del rango de opciones se le vuelve a pedir que ingrese un numero adecuado
//Parámetros entrada: Ninguno
//Parámetros salida: Ninguno
void videosxCalificacion() {
    cout << "Ingresa la calificación de los videos que deseas ver (1-5): ";
    cin >> califEsc;
    while (califEsc < 1 || califEsc > 5) {
        cout << endl << "Error. Ingrese digito del 1-5. Intente de nuevo:  ";
        cin >> califEsc;
    }
    
    for (int i=0;i<numVid;i++) {
        if (arrVideos[i]->getCalificacion() == califEsc) {
            arrVideos[i]->imprimir();
        }
    }
}

//episodiosSerieyCalificacion: permite desplegar los episodios de una serie, cada uno con su calificacion respectiva
//Parámetros entrada: Ninguno
//Parámetros salida: Ninguno
void episodiosSerieyCalificacion() {
    verificaSerie=false;
    cout << "Series disponibles en este momento: " << endl;
    for (int i=0;i<numSer;i++) {
        cout << arrSeries[i].getNombreSerie() << endl;
    }
    
    cout << "Selecciona el nombre de la Serie para ver sus episodios: ";
    cin >> serEsc;
    for (int i=0;i<numSer;i++) {
        if (arrSeries[i].getNombreSerie() == serEsc) {
            arrSeries[i].imprimirEpisodios();
            verificaSerie = true;
        }
    }
    
    if (verificaSerie == false) {
        cout << "Lo sentimos. La serie " << serEsc << " no se encuentra disponible aún. Verifique con uno de los títulos presentados anteriormente." << endl;
    }
}

//videosxGenero: permite desplegar los videos de un género en específico. Se agrega una lista de las opciones de los géneros disponibles para que el usuario ingrese el que desee
//Parámetros entrada: Ninguno
//Parámetros salida: Ninguno
void videosxGenero() {
    verificaGenero=false;
    cout << "Ciencia_ficcion" << endl;
    cout << "Accion" << endl;
    cout << "Drama" << endl;
    cout << "Musical" << endl;
    cout << "Animacion" << endl;
    cout << "Comedia" << endl;
    cout << "Ingrese el Género que busca: ";
    cin >> genEsc;
    for (int i=0;i<numVid;i++) {
        if (arrVideos[i]->getGenero() == genEsc) {
            arrVideos[i]->imprimir();
            verificaGenero = true;
        }
    }
    
    if (verificaGenero == false) {
        cout << "Lo sentimos. Aún no se cuenta con videos del género " << genEsc << ". Intente con uno de los géneros previamente incluidos." << endl;
    }
}

//peliculasxCalificacion: permite desplegar películas con una calificación en específico
//Parámetros entrada: Ninguno
//Parámetros salida: Ninguno
void peliculasxCalificacion() {
    cout << "Ingresa la calificación de las Películas que deseas ver (1-5): ";
    cin >> califEsc;
    while (califEsc < 1 || califEsc > 5) {
        cout << endl << "Error. Ingrese digito del 1-5. Intente de nuevo:  ";
        cin >> califEsc;
    }
    
    for (int i=0;i<numPeli;i++) {
        if (arrPeliculas[i].getCalificacion() == califEsc) {
            arrPeliculas[i].imprimir();
        }
    }
}

//main: despliega menú con las 8 opciones a seleccionar, ciclado para que la única manera que el usuario pueda salir es seleccionando dicha opcion en el menú
//Parámetros entrada: int argc, const char * argv[] (valores por default de documento de c++)
//Parámetros salida: Ninguno
int main(int argc, const char * argv[]) {
    do{
      cout << endl << endl << "1. Cargar archivo de datos" << endl;
      cout << "2. Mostrar lista de Películas" << endl;
      cout << "3. Mostrar lista de Series" << endl;
      cout << "4. Mostrar Videos con cierta Calificación" << endl;
      cout << "5. Mostrar Videos de cierto Género" << endl;
      cout << "6. Mostrar Episodios de una Serie con sus Calificaciones" << endl;
      cout << "7. Mostrar Películas con cierta Calificación" << endl;
      cout << "8. Salir" << endl;
      cout << "Ingrese operación deseada (1-8)" << endl;
      cin >> opcion;

      switch(opcion) {
          case 1:
              cout << "Carga de Archivo";
              cargaArchivos();
              break;
          case 2:
              cout << "Lista de Peliculas" << endl;
              listaPeliculas();
              break;
          case 3:
              cout << "Lista de Series" << endl;
              listaSeries();
              break;
          case 4:
              cout << "Videos por cierta Calificación" << endl;
              videosxCalificacion();
              break;
          case 5:
              cout << "Videos por Género" << endl;
              videosxGenero();
              break;
          case 6:
              cout << "Episodios de Serie con sus Calificaciones" << endl;
              episodiosSerieyCalificacion();
              break;
          case 7:
              cout << "Peliculas con cierta Calificacion" << endl;
              peliculasxCalificacion();
              break;
      }
        
    } while (opcion != 8);
    return 0;
}
