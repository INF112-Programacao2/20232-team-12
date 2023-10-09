#include "../include/Autor.hpp"
#include <iostream>

Autor::Autor(std::string nome, std::string email, std::string formacao, std::string area):
    Usuario(nome, email), _formacao(formacao), _area(area) {}
    
Autor::~Autor(){
    std::cout << "Destruindo autor..." << std::endl;
}

std::string Autor::get_formacao(){
    return this->_formacao;
}
std::string Autor::get_area(){
    return this->_area;
}
void Autor::set_formacao(std::string formacao){
    _formacao = formacao;
}
void Autor::set_area(std::string area){
    _area = area;
}