#ifndef COMENTARIO_H
#define COMENTARIO_H

#include "../include/Leitor.h"
#include "../include/Artigo.h"
#include <iostream>
#include <vector>

class Comentario {
    private: 
    int _id;
    std::string _texto;
    int _id_autor;
    int _id_artigo;
    static int _numero_de_comentarios;

    public:
    Comentario(std::string texto, int id_autor, int id_artigo);
    ~Comentario();

    int get_id();
    std::string get_texto();
    int get_id_autor();
    int get_id_artigo();

    static int get_ultimo_id();
    void salvar_no_banco();
};
#endif