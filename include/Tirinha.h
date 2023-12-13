#ifndef TIRINHA_H
#define TIRINHA_H

#include "../include/Artigo.h"
#include <iostream>

class Tirinha : public Artigo {
    private: 
    std::string _imagem;

    public:
    Tirinha(std::string titulo, Autor autor, std::string data, std::string link, std::string imagem);
    ~Tirinha();

    std::string get_imagem();

    void set_imagem(std::string imagem);
    
    virtual void salvar_no_banco() override;
};
#endif