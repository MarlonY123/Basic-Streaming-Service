#ifndef _VIDEO_H_
#define _VIDEO_H_
#include <string>
//#include "Episodio.h"


class Video {
    friend std::ostream &operator<<(std::ostream &os, const Video &video);
    protected:
        static int nextId;
        int id;
        std::string tipoVideo;
        std::string nombreVideo;
        std::string genero;
        int calificacion;
        int añoLanzamiento;
        int duracion;
    public:
        Video();
        Video(std::string, std::string, std::string, int, int, int);
        ~Video();
        int getId();
        std::string getGenero();
        virtual int getCalif();
        std::string getNombre();
        std::string getTipo();
        void calificaVideo(int);
        virtual void muestraDatos();
        virtual int getNumero();
        virtual void addEpisode(
            std::string nombre,
            std::string gen,
            int calif,
            int año,
            int dur,
            int temp, 
            int num, 
            std::string act 
        );
        //int getCalificacion();
        //std::string getGenero();
        virtual std::string getNombreSerie();
};

#endif