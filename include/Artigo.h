#ifndef ARTIGO_H
#define ARTIGO_H

#include "../include/Autor.h"

#include <iostream>
#include <vector>
#include <sqlite3.h>

class Artigo {
    protected: 
    int _id;
    std::string _titulo;
    Autor _autor;
    std::string _data;
    std::string _link;
    static int _numero_de_artigos;

    public:
    Artigo(std::string titulo, Autor autor, std::string data, std::string link);
    ~Artigo();

    int get_id();
    std::string get_titulo();
    std::string get_data();
    std::string get_link();

    void set_titulo(std::string titulo);
    void set_data(std::string data);
    void set_link(std::string link);

    static int get_ultimo_id();
    virtual void salvar_no_banco() = 0;
};
#endif