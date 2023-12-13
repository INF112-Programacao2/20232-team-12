#include "../include/Comentario.h"
#include <iostream>

//Variavel que garante ids únicos para cada comentario
//Ao inicializar busca no banco pelo ultimo (maior) id inserido e o incrementa
int Comentario::_numero_de_comentarios = Comentario::get_ultimo_id() + 1;

//Construtor do Comentario
Comentario::Comentario(std::string texto, int id_autor, int id_artigo):
    _id(_numero_de_comentarios), _texto(texto), _id_autor(id_autor), _id_artigo(id_artigo) 
{
    _numero_de_comentarios++;
}

//Destrutor do Comentario
Comentario::~Comentario(){}

//Métodos get e set
int Comentario:: get_id(){
    return this->_id;
}

std::string Comentario::get_texto(){
    return this->_texto;
}

int Comentario::get_id_autor(){
    return this->_id_autor;
}

int Comentario::get_id_artigo(){
    return this->_id_artigo;
}

//Método que consulta o banco de dados para encontrar o maior id inserido dentre os comentários
int Comentario::get_ultimo_id(){
   int recordCount = 0;

    try {
        sqlite3* db;
        char* zErrMsg = 0;
        int rc;

        rc = sqlite3_open("./db.sqlite3", &db);

        if (rc != SQLITE_OK) {
            throw std::invalid_argument("Erro ao abrir o banco de dados");
        }

        //Query para consultar o maior id
        std::string countQuery = "SELECT MAX(id) FROM core_comentario";

        rc = sqlite3_exec(db, countQuery.c_str(), [](void* data, int argc, char** argv, char** /*azColName*/) -> int {
            //Função callback que recupera o resultado
            int* count = static_cast<int*>(data);
            
            //Verifica se o valor não é nulo antes de converter
            if (argv[0] != nullptr) {
                *count = std::stoi(argv[0]);
            }

            return SQLITE_OK;
        }, &recordCount, &zErrMsg);

        if (rc != SQLITE_OK) {
            throw std::invalid_argument(zErrMsg);
        }

        sqlite3_close(db);
    }
    catch (std::exception& e) {
        std::cout << "Erro ao acessar banco de dados: " << e.what() << std::endl;
    }

    //Retorna o maior id 
    return recordCount;
}

//Método de registro do Comentário no banco de dados
void Comentario::salvar_no_banco(){
    try {
        sqlite3* db;
        char* zErrMsg = 0;
        int rc;

       std::string query = "INSERT INTO core_comentario (id, texto, artigo_id, autor_id) VALUES ('" + std::to_string(_id) + "','" + _texto + "','" + std::to_string(_id_artigo) + "','" + std::to_string(_id_autor) +"')";
        
        rc = sqlite3_open("./db.sqlite3", &db);
        rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &zErrMsg);
        
        if (rc != SQLITE_OK) {
            sqlite3_close(db);
            throw std::invalid_argument(zErrMsg);
        }
        else {
            sqlite3_close(db);
            if(!zErrMsg && sqlite3_changes(db) > 0)
                std::cout << "Comentario salvo com sucesso!" << std::endl;
            else
                std::cout << "Não foi possível concluir alteração."<<std::endl;
        }
    }
    catch (std::exception &e) {
        std::cout << "Erro ao acessar banco de dados: "<<e.what() << std::endl;
    }
}