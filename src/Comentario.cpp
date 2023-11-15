#include "../include/Comentario.h"
#include <iostream>

int Comentario::_numero_de_comentarios = 0;

Comentario::Comentario(std::string texto, Leitor* autor_do_comentario, Artigo* artigo_comentado):
    _id(_numero_de_comentarios), _texto(texto), _autor_do_comentario(autor_do_comentario), _artigo_comentado(artigo_comentado) 
{
    _numero_de_comentarios++;
}

Comentario::~Comentario(){
    std::cout << "Destruindo comentario..." << std::endl;
}

int Comentario:: get_id(){
    return this->_id;
}

std::string Comentario::get_texto(){
    return this->_texto;
}

Leitor Comentario::get_autor_do_comentario(){
    return *(this->_autor_do_comentario);
}

Artigo Comentario::get_artigo_comentado(){
    return *(this->_artigo_comentado);
}

void Comentario::set_texto(std::string texto){
    _texto = texto;
}

void Comentario::set_autor_do_comentario(Leitor* autor_do_comentario){
    _autor_do_comentario = autor_do_comentario;
}

void Comentario::set_artigo_comentado(Artigo* artigo_comentado){
    _artigo_comentado = artigo_comentado;
}