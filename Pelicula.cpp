#include <string>
#include <iostream>
#include <sstream>
#include "Pelicula.h"

using namespace std;

Pelicula::Pelicula(
    string nombre,
    string gen,
    int calif,
    int año,
    int dur,
    string est,
    string dir,
    string act,
    string nac
) : Video{"pelicula", nombre, gen, calif, año, dur},
    estudio{est},
    director{dir},
    nacionalidad{nac} {
    
    string actor;
    stringstream input_stringstream(act);
    while (getline(input_stringstream, actor, ';')) {
        actores.push_back(actor);
    }
}

void Pelicula::muestraDatos() {
    Video::muestraDatos();
    cout << "Estudio: " << estudio << endl;
    cout << "Director: " << director << endl;
    //Vector Actores
    cout << "Actores: ";
    for(auto actor: actores){
      cout << actor << ", ";
    }
    cout <<  "\nnacionalidad: " << nacionalidad <<endl;
}

ostream &operator<<(ostream &os, const Pelicula &video) {
    os << "Tipo: " << video.tipoVideo << "\nNombre: " << video.nombreVideo 
    << "\nGenero: " << video.genero << "\nCalificacion: " << video.calificacion
    << "\nAño: " << video.añoLanzamiento << "\nDuracion: " << video.duracion
    << "\nEstudio " << video.estudio 
    << "\n Director " << video.director <<endl;
    return os;
}