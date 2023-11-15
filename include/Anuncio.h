#ifndef ANUNCIO_HPP
#define ANUNCIO_HPP

#include "../include/Artigo.h"

#include <iostream>

class Anuncio : public Artigo {
    private: 
    std::string _texto;
    std::string _logo;

    public:
    Anuncio(std::string titulo, Autor *autor, int data, std::string link, std::string texto, std::string logo);
    ~Anuncio();

    std::string get_texto();
    std::string get_logo();

    void set_texto(std::string texto);
    void set_logo(std::string logo);
};
#endif