#ifndef ADMINISTRADOR_HPP
#define ADMINISTRADOR_HPP

#include "../include/Usuario.hpp"
#include <iostream>

class Administrador : public Usuario {
    private: 
    int _senha;

    public:
    Administrador(std::string nome, std::string email, int senha);
    ~Administrador();
    
    void adicionar_artigo();
    void remover_artigo();
    void apagar_comentario();
};
#endif