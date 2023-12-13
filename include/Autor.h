#ifndef AUTOR_H
#define AUTOR_H

#include "../include/Usuario.h"

#include <iostream>
#include <vector>

class Autor : public Usuario {
    private: 
    std::string _formacao;
    std::string _area;

    public:
    Autor(std::string nome, std::string email, std::string formacao, std::string area);
    ~Autor();

    std::string get_formacao();
    std::string get_area();

    void set_formacao(std::string formacao);
    void set_area(std::string area);

    virtual void salvar_no_banco() override;
};
#endif