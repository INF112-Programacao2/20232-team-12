#ifndef LEITOR_HPP
#define LEITOR_HPP

#include "../include/Usuario.h"
#include "../include/Artigo.h"
#include <iostream>
#include <vector>

class Leitor : public Usuario {
    private: 
    std::vector<Artigo*> _favoritos;
    bool _assinatura_ativada;
    std::string _data_inicial_contrato;

    public:
    Leitor(std::string nome, std::string email, bool assinatura_ativada, std::string _data_inicial_contrato);
    ~Leitor();

    void get_favoritos();
    bool get_assinatura_ativada();
    std::string get_data_inicial_contrato();

    void set_assinatura_ativada(bool assinatura_ativada);
    void set_data_inicial_contrato(std::string data_inicial_contrato);
    
    void ver_jornal();
    void postar_comentario();
    void adicionar_artigo_aos_favoritos(Artigo *artigo);
    void remover_artigo_dos_favoritos();
};
#endif