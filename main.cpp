

#include "Episodio.h"
#include "MiNetflix.h"
#include "Serie.h"
#include "Video.h"
#include <iostream>
using namespace std;

int main() {
  //MiNetflix systema;
  //Video hola;
  //hola.muestraDatos();
  MiNetflix systema;
  cout << "Bienvendio a calificatuvideo.com" << endl;
    cout << "================================" << endl;
int opcion{};
  do {
    
    cout << "Elige la opcion deseada" << endl;
    cout << "1 - Revisa los videos" << endl;
    cout << "2 - Mostrar videos con una cierta calificacion o genero" << endl;
    cout << "3 - Mostrar los episodios de una determinada serie con una calificacion determinada" << endl;
    cout << "4 - Mostrar las peliculas con cierta calificacion" << endl;
    cout << "5 - Califica tu video" << endl;
    cout << "6 - Salir" << endl;
    cin >> opcion;
    switch (opcion)
    {
    case 1:
      systema.mostrarVideos();
      break;
    case 2:
      int escoger;
      cout << "Mostrar por 1. calificacion o 2. genero: ";
      cin >> escoger;
      if(escoger == 1)
        systema.mostrarCalificacion();
      else if(escoger ==2)
        systema.mostrarGenero();
    break;
    case 3:
      systema.mostrarEpi();
    break;
    case 4:
      systema.mostrarPeliculaTipo();
    break;
    case 5:
      systema.calificaVideos();
    break;
    default:
      break;
    }
  } while (opcion != 6);
  return 0;
}
