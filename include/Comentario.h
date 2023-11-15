#ifndef COMENTARIO_HPP
#define COMENTARIO_HPP

#include "../include/Leitor.h"
#include "../include/Artigo.h"
#include <iostream>
#include <vector>

class Comentario {
    private: 
    int _id;
    std::string _texto;
    Leitor* _autor_do_comentario;
    Artigo* _artigo_comentado;
    static int _numero_de_comentarios;

    public:
    Comentario(std::string texto, Leitor* autor_do_comentario, Artigo* artigo_comentado);
    ~Comentario();

    int get_id();
    std::string get_texto();
    Leitor get_autor_do_comentario();
    Artigo get_artigo_comentado();

    void set_texto(std::string texto);
    void set_autor_do_comentario(Leitor* autor_do_comentario);
    void set_artigo_comentado(Artigo* artigo_comentado);
};
#endif