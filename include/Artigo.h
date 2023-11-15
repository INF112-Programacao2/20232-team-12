#ifndef ARTIGO_HPP
#define ARTIGO_HPP

#include "../include/Autor.h"

#include <iostream>
#include <vector>

class Artigo {
    protected: 
    int _id;
    std::string _titulo;
    std::vector<Autor*>_autores;
    int _data;
    std::string _link;
    static int _numero_de_artigos;

    public:
    Artigo(std::string titulo, Autor *autor, int data, std::string link);
    ~Artigo();

    int get_id();
    std::string get_titulo();
    int get_data();
    std::string get_link();

    void set_titulo(std::string titulo);
    void set_data(int data);
    void set_link(std::string link);

    void adicionar_autor(Autor *autor);
    void ver_autores();
    void ver_artigos_por_autor(Autor *autor);
    void salvar_no_banco_de_dados();
};
#endif