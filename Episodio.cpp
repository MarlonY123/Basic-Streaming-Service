#include "Episodio.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

Episodio::Episodio(
    string nombre,
    string gen,
    int calif,
    int año,
    int dur,
    int temp, 
    int num, 
    string actores_val, string nom_ser
) : Video{"episodio", nombre, gen, calif, año, dur},
    temporada{temp},
    numero{num}, nombre_serie{nom_ser} {
    
    string actor;
    stringstream input_stringstream(actores_val);
    while (getline(input_stringstream, actor, ';')) {
        actores.push_back(actor);
    }
}

  void Episodio::muestraDatos(){
      Video::muestraDatos();
      cout << "Temporada: "<< temporada << endl;
      cout << "Numero episodio: "<< numero << endl;
      cout << "Actores: "; 
      for(auto actor: actores){
        cout << actor << ", ";
    }
      cout << "\nNombre de la serie: " << nombre_serie <<endl;
  }

Episodio::~Episodio() {
}

int Episodio::getNumero() {
    return numero;
}

string Episodio::getNombreSerie(){
    return nombre_serie;
}

ostream &operator<<(ostream &os, const Episodio &video) {
    os << "Tipo: " << video.tipoVideo << "\nNombre: " << video.nombreVideo 
    << "\nGenero: " << video.genero << "\nCalificacion: " << video.calificacion
    << "\nAño: " << video.añoLanzamiento << "\nDuracion: " << video.duracion
    << "\nTemporada " << video.temporada    << "\nNumero episodio " << video.numero <<endl;
    return os;
}
