#ifndef _SERIE_H_
#define _SERIE_H_
#include "Episodio.h"
#include "Video.h"
#include <string>
#include <vector>
#include <list>
class Serie: public Video {
friend std::ostream &operator<<(std::ostream &os, const Serie &serie);
    private:
        int numTemporadas;
        std::string productora;
        std::vector<Video *> episodios;
        std::string director;
        std::vector<std::string> actores;
        std::string nacionalidad;
    public:
        Serie(
            std::string nombre = "",
            std::string gen = "",
            int calif = 0,
            int año = 9999,
            int dur = 0,
            std::string prod = "",
            std::string dir = "",
            std::string act = "",
            std::string nac = "",
            int numTemp = 1
        );
        ~Serie();
            void addEpisode(
            std::string nombre,
            std::string gen,
            int calif,
            int año,
            int dur,
            int temp, 
            int num, 
            std::string act
        );
        void muestraEpisodios();
        virtual void muestraDatos();
        //std::list<Serie > series;
};
#endif