#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <vector>
#include <sqlite3.h>

class Usuario {
    protected: 
    int _id;
    std::string _nome;
    std::string _email;
    static int _numero_de_usuarios;

    public:
    Usuario(std::string nome, std::string email);
    ~Usuario();

    int get_id();
    std::string get_nome();
    std::string get_email();
    
    void set_nome(std::string nome);
    void set_email(std::string email);

    static bool validar_data(std::string a);

    static int get_ultimo_id();
    virtual void salvar_no_banco() = 0;
};
#endif