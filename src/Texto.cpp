#include "../include/Texto.h"
#include <iostream>

Texto::Texto(std::string titulo, Autor *autor, int data, std::string link, std::string resumo, std::string area, std::vector<std::string> keywords):
    Artigo(titulo, autor, data, link), _resumo(resumo), _area(area)
{
    for(std::string i : keywords){
        _keywords.push_back(i);
    }
}

Texto::~Texto(){
    std::cout << "Destruindo texto..." << std::endl;
}

std::string Texto::get_resumo(){
    return this->_resumo;
}

std::string Texto::get_area(){
    return this->_area;
}

void Texto::get_keywords(){
    for(std::string i : _keywords){
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}

void Texto::set_resumo(std::string resumo){
    _resumo = resumo;
}

void Texto::set_area(std::string area){
    _area = area;
}

void Texto::set_keywords(std::string keywords){

}