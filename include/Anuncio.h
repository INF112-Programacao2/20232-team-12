#ifndef ANUNCIO_H
#define ANUNCIO_H

#include "../include/Artigo.h"

#include <iostream>

class Anuncio : public Artigo {
    private: 
    std::string _texto;
    std::string _logo;

    public:
    Anuncio(std::string titulo, Autor autor, std::string data, std::string link, std::string texto, std::string logo);
    ~Anuncio();

    std::string get_texto();
    std::string get_logo();

    void set_texto(std::string texto);
    void set_logo(std::string logo);

    virtual void salvar_no_banco() override; 
};
#endif