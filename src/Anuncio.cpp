#include "../include/Anuncio.hpp"
#include <iostream>

Anuncio::Anuncio(std::string titulo, Autor *autor, int data, std::string link, std::string texto, std::string logo):
    Artigo(titulo, autor, data, link), _texto(texto), _logo(logo) {}

Anuncio::~Anuncio(){
    std::cout << "Destruindo anuncio..." << std::endl;
}
std::string Anuncio::get_texto(){
    return this->_texto;
}
std::string Anuncio::get_logo(){
    return this->_logo;
}
void Anuncio::set_texto(std::string texto){
    _texto = texto;
}
void Anuncio::set_logo(std::string logo){
    _logo = logo;
}