#include "../include/Autor.h"

//Construtor do Autor
Autor::Autor(std::string nome, std::string email, std::string formacao, std::string area):
    Usuario(nome, email), _formacao(formacao), _area(area) {}
    
//Destrutor do Autor
Autor::~Autor(){}

//Métodos get e set
std::string Autor::get_formacao(){
    return this->_formacao;
}

std::string Autor::get_area(){
    return this->_area;
}

void Autor::set_formacao(std::string formacao){
    _formacao = formacao;
}

void Autor::set_area(std::string area){
    _area = area;
}

////Método sobrescrito de registro do Autor no banco de dados
void Autor::salvar_no_banco(){
    try {
        sqlite3* db;
        char* zErrMsg = 0;
        int rc;

       std::string query = "INSERT INTO core_autor (id, nome, email, formacao, area) VALUES ('" + std::to_string(_id) + "','" + _nome + "','" + _email + "','" + _formacao + "','" + _area + "')";
        
        rc = sqlite3_open("./db.sqlite3", &db);
        rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &zErrMsg);
        
        if (rc != SQLITE_OK) {
            sqlite3_close(db);
            throw std::invalid_argument(zErrMsg);
        }
        else {
            sqlite3_close(db);
            if(!zErrMsg && sqlite3_changes(db) > 0)
                std::cout << "Autor cadastrado com sucesso!" << std::endl;
            else
                std::cout << "Não foi possível concluir alteração."<<std::endl;
        }
    }
    catch (std::exception &e) {
        std::cout << "Erro ao acessar banco de dados: " << e.what() << std::endl;
    }
}