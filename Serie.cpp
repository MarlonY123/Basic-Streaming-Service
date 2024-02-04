#include "Serie.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;


Serie::Serie(
    string nombre,
    string gen,
    int calif,
    int año,
    int dur,
    string prod,
    string dir,
    string act,
    string nac,
    int numTemp
) : Video{"serie", nombre, gen, calif, año, dur},
    numTemporadas{numTemp}, 
    productora{prod}, director{dir}, nacionalidad{nac}
{
    string actor;
    stringstream input_stringstream(act);
    while (getline(input_stringstream, actor, ';')) {
        actores.push_back(actor);
    }
}

Serie::~Serie() {
    for (size_t i = 0; i < episodios.size(); i++) {
        delete episodios.at(i);
    }
}

void Serie::addEpisode(
    string nombre,
    string gen,
    int calif,
    int año,
    int dur,
    int temp, 
    int num, 
    string actores_val
) {
    Video *e = new Episodio(nombre, gen, calif, año, dur, temp, num, actores_val);
    episodios.push_back(e);
}

void Serie::muestraEpisodios() {
    for (auto episodio : episodios)
        cout << episodio->getNumero() << endl;
}

void Serie::muestraDatos(){
  Video::muestraDatos();
  cout << "Numero de Temporadas " << numTemporadas << endl;
  cout << "Productora: "<< productora <<endl;
  cout << "Actores: "; 
      for(auto actor: actores){
        cout << actor << ", ";
    }
  cout << "\nNacionalidad: "<< nacionalidad << endl;
}

ostream &operator<<(ostream &os, const Serie &video) {
    os << "Tipo: " << video.tipoVideo << "\nNombre: " << video.nombreVideo 
    << "\nGenero: " << video.genero << "\nCalificacion: " << video.calificacion
    << "\nAño: " << video.añoLanzamiento << "\nDuracion: " << video.duracion
    << "\nNumero de Temporadas " << video.numTemporadas 
    << "\n Productora: " << video.productora << "\nActores: ";
    os << "Actores: "; 
      for(auto actor: video.actores){
        os << actor << ", ";
    }
    os << "\nNacionalidad: "<< video.nacionalidad << endl;
    return os;
}
