#include "../include/Tirinha.h"

//Construtor da Tirinha
Tirinha::Tirinha(std::string titulo, Autor autor, std::string data, std::string link, std::string imagem):
    Artigo(titulo, autor, data, link), _imagem(imagem) {}

//Destrutor da Tirinha
Tirinha::~Tirinha(){}

//Métodos get e set
std::string Tirinha::get_imagem(){
    return this->_imagem;
}

void Tirinha::set_imagem(std::string imagem){
    _imagem = imagem;
}

//Método sobrescrito de registro da Tirinha no banco de dados
void Tirinha::salvar_no_banco(){
    try {
        sqlite3* db;
        char* zErrMsg = 0;
        int rc;

        int autor_id = _autor.get_id();

       std::string query = "INSERT INTO core_tirinha (id, titulo, data, link, imagem, autor_id, favoritado) VALUES ('" + std::to_string(_id) + "','" + _titulo + "','" + _data + "','" + _link + "','" + _imagem + "','" + std::to_string(autor_id) + "','false')";
        
        rc = sqlite3_open("./db.sqlite3", &db);
        rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &zErrMsg);
        
        if (rc != SQLITE_OK) {
            sqlite3_close(db);
            throw std::invalid_argument(zErrMsg);
        }
        else {
            sqlite3_close(db);
            if(!zErrMsg && sqlite3_changes(db) > 0)
                std::cout << "Tirinha salva com sucesso!" << std::endl;
            else
                std::cout << "Não foi possível concluir alteração."<<std::endl;
        }
    }
    catch (std::exception &e) {
        std::cout << "Erro ao acessar banco de dados: "<<e.what() << std::endl;
    }
}
