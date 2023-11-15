#include "../include/Leitor.h"
#include <iostream>

Leitor::Leitor(std::string nome, std::string email, bool assinatura_ativada, std::string data_inicial_contrato):
    Usuario(nome, email), _assinatura_ativada(assinatura_ativada), _data_inicial_contrato(data_inicial_contrato) {}

Leitor::~Leitor(){
    std::cout << "Destruindo leitor..." << std::endl;
}

void Leitor::get_favoritos(){
    for(Artigo *i : _favoritos){
        std::cout << i->get_titulo() << ", ";
    }
    std::cout << std::endl;
}
bool Leitor::get_assinatura_ativada(){
    return this->_assinatura_ativada;
}
std::string Leitor::get_data_inicial_contrato(){
    return this->_data_inicial_contrato;
}
void Leitor::set_assinatura_ativada(bool assinatura_ativada){
    _assinatura_ativada = assinatura_ativada;
}
void Leitor::set_data_inicial_contrato(std::string data_inicial_contrato){
    _data_inicial_contrato = data_inicial_contrato;
}
void Leitor::ver_jornal(){

}
void Leitor::postar_comentario(){

}
void Leitor::adicionar_artigo_aos_favoritos(Artigo *artigo){
    _favoritos.push_back(artigo);
}
void Leitor::remover_artigo_dos_favoritos(){

}