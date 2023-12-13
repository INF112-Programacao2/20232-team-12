#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "../include/Usuario.h"
#include "../include/Autor.h"

#include <iostream>
#include <sqlite3.h>

class Administrador : public Usuario {
    private: 
    int _senha;

    public:
    Administrador(std::string nome, std::string email, int senha);
    ~Administrador();
    
    void postar_artigo();
    Autor* criar_autor();
    void remover_artigo();
    void apagar_comentario();

    virtual void salvar_no_banco() override;
};
#endif