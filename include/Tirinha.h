#ifndef TIRINHA_HPP
#define TIRINHA_HPP

#include "../include/Artigo.h"
#include <iostream>

class Tirinha : public Artigo {
    private: 
    std::string _imagem;

    public:
    Tirinha(std::string titulo, Autor *autor, int data, std::string link, std::string imagem);
    ~Tirinha();

    std::string get_imagem();

    void set_imagem(std::string imagem);
};
#endif