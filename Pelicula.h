#ifndef _PELICULA_H_
#define _PELICULA_H_
#include <string>
#include <vector>
#include "Video.h"

class Pelicula: public Video {
friend std::ostream &operator<<(std::ostream &os, const Pelicula &pelicula);
    private:
        std::string estudio;
        std::string director;
        std::vector<std::string> actores;
        std::string nacionalidad;
    public:
        Pelicula(
            std::string nombre = "",
            std::string gen = "",
            int calif = 0,
            int año = 9999,
            int dur = 0,
            std::string est = "",
            std::string dir = "",
            std::string act = "",
            std::string nac = "");
        void muestraDatos();
};

#endif