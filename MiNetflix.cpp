#include <fstream>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include "MiNetflix.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"
#include "Video.h"

using namespace std;

enum attributes { TIPO, NOMBRE, GENERO, CALIFICACION, AÑO, DURACION, ESTUDIO_PRODUCTORA, DIRECTOR, ACTORES, NACIONALIDAD, NUMERO_TEMP, TEMPORADA, NUMERO_EPI, NOMBRE_SERIE};

MiNetflix::MiNetflix(string fileName) {
  
    ifstream in_stream;
    in_stream.open(fileName);
    
    if (in_stream.fail()) {
        cout << "No se pudo abrir el archivo " << fileName << endl;
        exit(1);
    }

    string input{};
    while(getline(in_stream,input)) {
        generaVideo(input);
    }

    in_stream.close();
}

MiNetflix::~MiNetflix() {
    for (auto video: videos)
        delete video;
}

void MiNetflix::generaVideo(string input) {
    stringstream input_stringstream(input);
    string elemento{};
    int counter{};
    string atributos [14];
    while (getline(input_stringstream, elemento, ',')) {
        atributos[counter] = elemento;
        counter++;
    }
    if (atributos[TIPO] == "pelicula") {
        Video *nuevo = new Pelicula(
            atributos[NOMBRE],
            atributos[GENERO],
            stoi(atributos[CALIFICACION]),
            stoi(atributos[AÑO]),
            stoi(atributos[DURACION]),
            atributos[ESTUDIO_PRODUCTORA],
            atributos[DIRECTOR],
            atributos[ACTORES],
            atributos[NACIONALIDAD]
        );
        videos.push_back(nuevo);
    } else if (atributos[TIPO] == "serie") {
        Video *nuevo = new Serie(
            atributos[NOMBRE],
            atributos[GENERO],
            stoi(atributos[CALIFICACION]),
            stoi(atributos[AÑO]),
            stoi(atributos[DURACION]),
            atributos[ESTUDIO_PRODUCTORA],
            atributos[DIRECTOR],
            atributos[ACTORES],
            atributos[NACIONALIDAD],
            stoi(atributos[NUMERO_TEMP])
        );
        videos.push_back(nuevo);
    } else if (atributos[TIPO] == "episodio") {
        for (auto video : videos) {
            if(video->getNombre() == atributos[NOMBRE_SERIE] && video->getTipo() == "serie") {
              /*
                video->addEpisode(
                    atributos[NOMBRE],
                    atributos[GENERO],
                    stoi(atributos[CALIFICACION]),
                    stoi(atributos[AÑO]),
                    stoi(atributos[DURACION]),
                    stoi(atributos[TEMPORADA]),
                    stoi(atributos[NUMERO_EPI]),
                    atributos[ACTORES]
                    
                );*/
              Video *nuevo = new Episodio(
                    atributos[NOMBRE],
                    atributos[GENERO],
                    stoi(atributos[CALIFICACION]),
                    stoi(atributos[AÑO]),
                    stoi(atributos[DURACION]),
                    stoi(atributos[TEMPORADA]),
                    stoi(atributos[NUMERO_EPI]),
                    atributos[ACTORES],
                    atributos[NOMBRE_SERIE]
              );
              videos.push_back(nuevo);
                break;
            }
        }
    }
  
}

void MiNetflix::mostrarVideos(){
  for(auto video: videos){
      cout << endl;
      video->muestraDatos();
    }
  cout << endl;
}

void MiNetflix::mostrarEpi(){
  int a=0;
  int c;
  cin.ignore();
  string nombre;
  cout << "Ingrese el nombre de la serie a buscar: ";
  getline(cin,nombre);
  cout<<"ingrese la calificacion a buscar:";
  cin>>c;
  
  for (auto video : videos) {
    if (video->getTipo() == "episodio" && video->getCalif() == c && video->getNombreSerie() == nombre  ){
      video->muestraDatos();
    }
   
  }
     
}



void MiNetflix::mostrarCalificacion(){
    cin.ignore();
    int calif =0;
    int contador = 0;
    int tamaño = videos.size();
    cout << "Introduzca la calificacion para los videos: " << endl;
    cin >> calif;
    if(calif >= 1 && calif <= 5){
        for(auto video: videos){
        if(calif == video->getCalif()){
            cout << endl;
            video->muestraDatos();
            cout << endl;
        }
        else{
            contador++;
        }
        }
        if(contador == tamaño) {
            cout << "No se encontraron videos con esa calificacion " << endl;
        }
    }
    else {
        cout << "calificacion invalida" << endl;
    }
}
void MiNetflix::mostrarGenero(){
    cin.ignore();
    string genero;
    int contador = 0;
    int tamaño = videos.size();
    cout << "Introduzca el genero para los videos: " << endl;
    getline(cin,genero);
    for(auto video: videos){
      if(genero == video->getGenero()){
        video->muestraDatos();
        cout << endl;
      }
      else{
        contador++;
      }
    }
    if(contador == tamaño) {
        cout << "No se encontraron videos de ese genero " << endl;
    }
}

void MiNetflix::mostrarPeliculaTipo(){
    cin.ignore();
    int calif = 0;
    int contador = 0;
    int tamaño = videos.size();
    cout << "Calificacion de cierta pelicula: ";
    cin >> calif;
    if(calif >= 1 && calif <= 5){
        for(auto video: videos){
        if("pelicula" == video->getTipo() && calif == video->getCalif()){
            video->muestraDatos();
            cout << endl;
        }
        else{
            contador++;
        }
        }
        if(contador == tamaño) {
            cout << "No se encontraron peliculas con esa calificacion " << endl;
        }
    }
    else {
        cout << "calificacion invalida" << endl;
    }
}
void MiNetflix::calificaVideos(){
    cin.ignore();
    string videoCalificar;
    int calificacionNueva;
    int contador = 0;
    int tamaño = videos.size();
    mostrarVideos();
    cout << "Que video desea calificar: ";
    getline(cin,videoCalificar);
    for(auto video: videos){
      if(video->getNombre() == videoCalificar){
        cout << "Por cual cantidad desea cambiar su calificación de " << video->getCalif() << " : ";
        cin >> calificacionNueva;
        cout << endl;
        video->calificaVideo(calificacionNueva);
        cout << "NUEVOS DATOS" << endl;
        video->muestraDatos();
        cout << endl;
      }
      else{
        contador++;
      }
    }
    if(contador == tamaño) {
        cout << "No se encontraron videos con ese nombre " << endl;
    }
}




