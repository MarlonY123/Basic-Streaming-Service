#include <string>
#include<iostream>
#include "Video.h"

using namespace std;

int Video::nextId = 0;

Video::Video(string tipo, string nombre, string gen, int calif, int año, int dur) :
    tipoVideo(tipo), 
    nombreVideo(nombre),
    genero(gen),
    calificacion(calif),
    añoLanzamiento(año),
    duracion(dur) {
        id = ++nextId;
}

Video::Video() : Video("pelicula", "untitled", "comedia", 1, 1989, 120) {
}

Video::~Video(){
}

void Video::calificaVideo(int calif) {
    
    if (calif < 1 || calif > 5) {
        cout << "calificacion invalida" << endl;
        return;
    }
    calificacion = calif;
}

int Video::getId() {
    return id;
}

int Video::getNumero() {
    
    return 0;
}

string Video::getNombre() {
    return nombreVideo;
}

string Video::getTipo() {
    return tipoVideo;
}
string Video::getGenero() {
    return genero;
}
int Video::getCalif(){
    return calificacion;
}
void Video::muestraDatos() {
    cout << "ID: " << id << endl;
    cout << "Tipo: " << tipoVideo << endl;
    cout << "Nombre: " << nombreVideo << endl;
    cout << "Genero: " << genero << endl;
    cout << "Calificacion: " << calificacion << endl;
    cout << "Año: " << añoLanzamiento << endl;
    cout << "Duracion: " << duracion << endl;
}


void Video::addEpisode(
            std::string nombre,
            std::string gen,
            int calif,
            int año,
            int dur,
            int temp, 
            int num, 
            std::string act){ 
  // Video *e = new Episodio(nombre, gen, calif, año, dur, temp, num);
   // episodios.push_back(e);
    cout << " ";
            }

string Video::getNombreSerie(){
    return "nombre";
}

ostream &operator<<(ostream &os, const Video &video) {
    cout <<  "Hola";
    os << "Tipo: " << video.tipoVideo << "\nNombre: " << video.nombreVideo 
    << "\nGenero: " << video.genero << "\nCalificacion: " << video.calificacion
    << "\nAño: " << video.añoLanzamiento << "\nDuracion: " << video.duracion << endl;
    return os;
}
