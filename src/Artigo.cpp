#include "../include/Artigo.hpp"
#include "../include/Autor.hpp"
#include <iostream>

int Artigo::_numero_de_artigos = 0;

Artigo::Artigo(std::string titulo, Autor *autor, int data, std::string link):
    _id(_numero_de_artigos), _titulo(titulo), _data(data), _link(link)
{
    _autores.push_back(autor);
    _numero_de_artigos++;
}
   
Artigo::~Artigo(){
    std::cout << "Destruindo artigo..." << std::endl;
}
int Artigo::get_id(){
    return this->_id;
}
std::string Artigo::get_titulo(){
    return this->_titulo;
}
void Artigo::get_autores(){
    for(Autor *i : _autores){
        std::cout << i->get_nome() << ", ";
    }
    std::cout << std::endl;
}
int Artigo::get_data(){
    return this->_data;
}
std::string Artigo::get_link(){
    return this->_link;
}
void Artigo::set_titulo(std::string titulo){
    _titulo = titulo;
}
void Artigo::set_data(int data){
    _data = data;
}
void Artigo::set_link(std::string link){
    _link = link;
}
void Artigo::adicionar_autor(Autor *autor){
    _autores.push_back(autor);
}
void Artigo::ver_artigos_por_autor(Autor *autor){
    
}