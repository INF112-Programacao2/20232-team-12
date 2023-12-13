#ifndef TEXTO_H
#define TEXTO_H

#include "../include/Artigo.h"

#include <iostream>

class Texto : public Artigo {
    private: 
    std::string _resumo;
    std::string _area;
    std::string _keywords;

    public:
    Texto(std::string titulo, Autor autor, std::string data, std::string link, std::string resumo, std::string area, std::string keywords);
    ~Texto();

    std::string get_resumo();
    std::string get_area();
    std::string get_keywords();

    void set_resumo(std::string resumo);
    void set_area(std::string area);
    void set_keywords(std::string keywords);

    virtual void salvar_no_banco() override;
};
#endif