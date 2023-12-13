#include "../include/Anuncio.h"
#include <iostream>

//Construtor do Anuncio
Anuncio::Anuncio(std::string titulo, Autor autor, std::string data, std::string link, std::string texto, std::string logo):
    Artigo(titulo, autor, data, link), _texto(texto), _logo(logo) {}

//Destrutor do Anuncio
Anuncio::~Anuncio(){}

//Métodos get e set
std::string Anuncio::get_texto(){
    return this->_texto;
}

std::string Anuncio::get_logo(){
    return this->_logo;
}

void Anuncio::set_texto(std::string texto){
    _texto = texto;
}

void Anuncio::set_logo(std::string logo){
    _logo = logo;
}

//Método sobrescrito de registro do Anuncio no banco de dados
void Anuncio::salvar_no_banco(){
    try {
        sqlite3* db;
        char* zErrMsg = 0;
        int rc;

        int autor_id = _autor.get_id();

       std::string query = "INSERT INTO core_anuncio (id, titulo, data, link, logo, autor_id, favoritado, texto) VALUES ('" + std::to_string(_id) + "','" + _titulo + "','" + _data + "','" + _link + "','" + _logo + "','" + std::to_string(autor_id) + "','false','" + _texto + "')";
        
        rc = sqlite3_open("./db.sqlite3", &db);
        rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &zErrMsg);
        
        if (rc != SQLITE_OK) {
            sqlite3_close(db);
            throw std::invalid_argument(zErrMsg);
        }
        else {
            sqlite3_close(db);
            if(!zErrMsg && sqlite3_changes(db) > 0)
                std::cout << "Anuncio salvo com sucesso!" << std::endl;
            else
                std::cout << "Não foi possível concluir alteração."<<std::endl;
        }
    }
    catch (std::exception &e) {
        std::cout << "Erro ao acessar banco de dados: " << e.what() << std::endl;
    }
}