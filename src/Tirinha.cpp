#include "../include/Tirinha.hpp"
#include <iostream>

Tirinha::Tirinha(std::string titulo, Autor *autor, int data, std::string link, std::string imagem):
    Artigo(titulo, autor, data, link), _imagem(imagem) {}

Tirinha::~Tirinha(){
    std::cout << "Destruindo tirinha..." << std::endl;
}
std::string Tirinha::get_imagem(){
    return this->_imagem;
}
void Tirinha::set_imagem(std::string imagem){
    _imagem = imagem;
}