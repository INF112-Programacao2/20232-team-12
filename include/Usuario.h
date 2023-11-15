#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <iostream>

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

    virtual void salvar_no_banco_de_dados();
};
#endif