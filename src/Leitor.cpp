#include "../include/Leitor.h"

//Construtor do Leitor
Leitor::Leitor(std::string nome, std::string email, bool assinatura_ativada, std::string data_inicial_contrato):
    Usuario(nome, email), _assinatura_ativada(assinatura_ativada), _data_inicial_contrato(data_inicial_contrato) {}

//Destrutor do Leitor
Leitor::~Leitor(){}

//Métodos get e set
void Leitor::get_favoritos(){
    for(Artigo *i : _favoritos){
        std::cout << i->get_titulo() << ", ";
    }
    std::cout << std::endl;
}

bool Leitor::get_assinatura_ativada(){
    return this->_assinatura_ativada;
}

std::string Leitor::get_data_inicial_contrato(){
    return this->_data_inicial_contrato;
}

void Leitor::set_assinatura_ativada(bool assinatura_ativada){
    _assinatura_ativada = assinatura_ativada;
}

void Leitor::set_data_inicial_contrato(std::string data_inicial_contrato){
    _data_inicial_contrato = data_inicial_contrato;
}

//Método que retorna o endereço do site do jornal
void Leitor::ver_jornal(){
    std::cout << "Acesse http://127.0.0.1:8000/core" << std::endl;
}

//Método que instancia e registra um comentário
void Leitor::postar_comentario(){
    int id_artigo;
    std::string texto;

    std::cout << "Informe o id do artigo que deseja comentar: ";
    std::cin >> id_artigo;

    std::cout << "Escreva seu comentario: ";
    std::cin >> texto;

    Comentario a(texto, _id, id_artigo);
    a.salvar_no_banco();
}

//Método de favoritar um artigo
void Leitor::favoritar_artigo(){
    int id, escolha;
    std::string tabela;

    std::cout << "Deseja favoritar um anuncio(1), tirinha(2) ou um texto(3)? ";
    std::cin >> escolha;

    if(escolha == 1){
        tabela = "anuncio";
    } else if(escolha == 2){
        tabela = "tirinha";
    } else if(escolha == 3){
        tabela = "texto";
    } else {
        std::cout << "Escolha inválida!\n";
        exit(0);
    }
    std::cout << "Informe o id do artigo que deseja favoritar: ";
    std::cin >> id;

    try {
        sqlite3* db;
        char* zErrMsg = 0;
        int rc;
        
        //Cada artigo tem um campo booleano de 'favoritado', o método o torna true
        std::string query = "UPDATE core_"+ tabela +" SET favoritado = 'true' WHERE id = " + std::to_string(id) +"";

        rc = sqlite3_open("./db.sqlite3", &db);
        rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &zErrMsg);
        
        if (rc != SQLITE_OK) {
            sqlite3_close(db);
            throw std::invalid_argument(zErrMsg);
        }
        else {
            sqlite3_close(db);
            if(!zErrMsg && sqlite3_changes(db) > 0)
                std::cout << "Artigo favoritado com sucesso!" << std::endl;
            else
                std::cout << "Não foi possível concluir alteração."<<std::endl;
        }
    }
    catch (std::exception &e) {
        std::cout << "Erro ao acessar banco de dados: "<<e.what() << std::endl;
    }
}

//Método de desfavoritar um artigo
void Leitor::remover_artigo_dos_favoritos(){
    int id, escolha;
    std::string tabela;

    std::cout << "Deseja desfavoritar um anuncio(1), tirinha(2) ou um texto(3)? ";
    std::cin >> escolha;

    if(escolha == 1){
        tabela = "anuncio";
    } else if(escolha == 2){
        tabela = "tirinha";
    } else if(escolha == 3){
        tabela = "texto";
    } else {
        std::cout << "Escolha inválida!\n";
        exit(0);
    }
    std::cout << "Informe o id do artigo que deseja desfavoritar: ";
    std::cin >> id;

    try {
        sqlite3* db;
        char* zErrMsg = 0;
        int rc;
        
        //Cada artigo tem um campo booleano de 'favoritado', o método o torna false
        std::string query = "UPDATE core_"+ tabela +" SET favoritado = 'false' WHERE id = " + std::to_string(id) +"";

        rc = sqlite3_open("./db.sqlite3", &db);
        rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &zErrMsg);
        
        if (rc != SQLITE_OK) {
            sqlite3_close(db);
            throw std::invalid_argument(zErrMsg);
        }
        else {
            sqlite3_close(db);
            if(!zErrMsg && sqlite3_changes(db) > 0)
                std::cout << "Artigo desfavoritado com sucesso!" << std::endl;
            else
                std::cout << "Não foi possível concluir alteração."<<std::endl;
        }
    }
    catch (std::exception &e) {
        std::cout << "Erro ao acessar banco de dados: "<<e.what() << std::endl;
    }
}

//Método sobrescrito de registro do Leitor no banco de dados
void Leitor::salvar_no_banco(){
    try {
        sqlite3* db;
        char* zErrMsg = 0;
        int rc;

       std::string query = "INSERT INTO core_leitor (id, nome, email, assinatura_ativada, data_inicial_contrato) VALUES ('" + std::to_string(_id) + "','" + _nome + "','" + _email + "','" + std::to_string(_assinatura_ativada) + "', '" + _data_inicial_contrato + "')";

        rc = sqlite3_open("./db.sqlite3", &db);
        rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &zErrMsg);
        
        if (rc != SQLITE_OK) {
            sqlite3_close(db);
            throw std::invalid_argument(zErrMsg);
        }
        else {
            sqlite3_close(db);
            if(!zErrMsg && sqlite3_changes(db) > 0)
                std::cout << "Leitor cadastrado com sucesso!" << std::endl;
            else
                std::cout << "Não foi possível concluir alteração."<<std::endl;
        }
    }
    catch (std::exception &e) {
        std::cout << "Erro ao acessar banco de dados: "<<e.what() << std::endl;
    }
}