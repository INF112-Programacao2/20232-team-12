#ifndef TEXTO_HPP
#define TEXTO_HPP

#include "../include/Artigo.hpp"

#include <iostream>
#include <vector>

class Texto : public Artigo {
    private: 
    std::string _resumo;
    std::string _area;
    std::vector<std::string> _keywords;

    public:
    Texto(std::string titulo, Autor *autor, int data, std::string link, std::string resumo, std::string area, std::vector<std::string> keywords);
    ~Texto();

    std::string get_resumo();
    std::string get_area();
    void get_keywords();

    void set_resumo(std::string resumo);
    void set_area(std::string area);
    void set_keywords(std::string keywords);
};
#endif