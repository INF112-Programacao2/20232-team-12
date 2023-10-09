#include "../include/Administrador.hpp"
#include <iostream>

Administrador::Administrador(std::string nome, std::string email, int senha):
    Usuario(nome, email), _senha(senha) {}

Administrador::~Administrador(){
    std::cout << "Destruindo administrador..." << std::endl;
}

void Administrador::adicionar_artigo(){

}
void Administrador::remover_artigo(){

}
void Administrador:: apagar_comentario(){

}