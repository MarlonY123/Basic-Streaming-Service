#ifndef _EPISODIO_H_
#define _EPISODIO_H_
#include "Video.h"
#include <vector>
#include <string>

class Episodio: public Video {
friend std::ostream &operator<<(std::ostream &os, const Episodio &episodio);
    private:
        std::vector<std::string> actores;
        int temporada;
        int numero;
        std::string nombre_serie;
    public:
        Episodio(
            std::string nombre = "",
            std::string gen = "",
            int calif = 0,
            int año = 9999,
            int dur = 0,
            int temp = 1, 
            int num = 1, 
            std::string actores_val = "",
            std::string nom_ser = "");
        ~Episodio();
        int getTemporada();
        void setTemporada(int);
        int getNumero();
        void setNumero(int);
        void muestraDatos();
        std::string getNombreSerie();
};

#endif