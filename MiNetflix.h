#ifndef _MINETFLIX_H_
#define _MINETFLIX_H_
#include <list>
#include <string>
#include "Video.h"
#include "Serie.h"

class MiNetflix {
    private:
        std::list<Video *> videos;
        void generaVideo(std::string);
    public:
        MiNetflix(std::string fileName = "videos.txt");
        ~MiNetflix();
        void addVideo(const Video *video);
        void mostrarVideos();
        void mostrarEpi();
        //std::list<Video *> series;
        
        std::vector<Serie *> series;
        void mostrarCalificacion();
        void mostrarGenero();
        void mostrarPeliculaTipo();
        void calificaVideos();
        void display(const std::list<Video*> &video);
     
};

#endif