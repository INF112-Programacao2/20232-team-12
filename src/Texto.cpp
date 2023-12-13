#include "../include/Texto.h"

//Construtor do Texto
Texto::Texto(std::string titulo, Autor autor, std::string data, std::string link, std::string resumo, std::string area, std::string keywords):
    Artigo(titulo, autor, data, link), _resumo(resumo), _area(area), _keywords(keywords){}

//Destrutor do Texto
Texto::~Texto(){}

//Métodos get e set
std::string Texto::get_resumo(){
    return this->_resumo;
}

std::string Texto::get_area(){
    return this->_area;
}

std::string Texto::get_keywords(){
    return this->_keywords;
}

void Texto::set_resumo(std::string resumo){
    _resumo = resumo;
}

void Texto::set_area(std::string area){
    _area = area;
}

void Texto::set_keywords(std::string keywords){
    _keywords = keywords;
}

//Método sobrescrito de registro do Texto no banco de dados
void Texto::salvar_no_banco(){
    try {
        sqlite3* db;
        char* zErrMsg = 0;
        int rc;

        int autor_id = _autor.get_id();

       std::string query = "INSERT INTO core_texto (id, titulo, data, link, area, keywords, autor_id, favoritado, resumo) VALUES ('" + std::to_string(_id) + "','" + _titulo + "','" + _data + "','" + _link + "','" + _area + "','" + _keywords + "','" + std::to_string(autor_id) + "','false', '" + _resumo + "')";
        
        rc = sqlite3_open("./db.sqlite3", &db);
        rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &zErrMsg);
        
        if (rc != SQLITE_OK) {
            sqlite3_close(db);
            throw std::invalid_argument(zErrMsg);
        }
        else {
            sqlite3_close(db);
            if(!zErrMsg && sqlite3_changes(db) > 0)
                std::cout << "Texto salvo com sucesso!" << std::endl;
            else
                std::cout << "Não foi possível concluir alteração."<<std::endl;
        }
    }
    catch (std::exception &e) {
        std::cout << "Erro ao acessar banco de dados: "<<e.what() << std::endl;
    }
}