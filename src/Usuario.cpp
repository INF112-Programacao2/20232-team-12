#include "../include/Usuario.h"
#include <iostream>

int Usuario::_numero_de_usuarios = 0;

Usuario::Usuario(std::string nome, std::string email):
    _id(_numero_de_usuarios),
    _nome(nome),
    _email(email)
{
    _numero_de_usuarios++;
}

Usuario::~Usuario(){
    std::cout << "Destruindo usuário..." << std::endl;
}

int Usuario::get_id(){
    return this->_id;
}

std::string Usuario::get_nome(){
    return this->_nome;
}

std::string Usuario::get_email(){
    return this->_email;
}

void Usuario::set_nome(std::string nome){
    _nome = nome;
}

void Usuario::set_email(std::string email){
    _email = email;
}

void Usuario::salvar_no_banco_de_dados(){
    
}

