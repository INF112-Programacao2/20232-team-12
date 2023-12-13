#include "../include/Administrador.h"
#include "../include/Anuncio.h"
#include "../include/Tirinha.h"
#include "../include/Texto.h"

#include <iostream>

//Construtor do ADM
Administrador::Administrador(std::string nome, std::string email, int senha):
    Usuario(nome, email), _senha(senha) {}

//Destrutor do ADM
Administrador::~Administrador(){}

//Método de instanciação e registro no BD de todos os tipos de artigo
void Administrador::postar_artigo(){
    std::string titulo, data, link, info1, info2, info3;
    int escolha;

    std::cout << "Qual o título do artigo? ";
    std::cin.ignore();
    std::getline(std::cin, titulo);

    //Salva o endereço de objeto Autor armazenado no Heap
    Autor *autor = criar_autor();

    //Validação da data
    while(true){
        std::cout << "Qual a data de publicação? ";
        std::cin >> data;

        if(data.find('/') != std::string::npos){
            if(validar_data(data)) 
                break;
            else 
                std::cout << "Informe uma data válida!" << std::endl;
        } else 
            std::cout << "Informe uma data do formato DD/MM/AAAA." << std::endl;
    }

    std::cout << "Qual o link de acesso? ";
    std::cin >> link;

    std::cout << "É um anúncio(1), tirinha(2) ou texto(3)? ";
    std::cin >> escolha;

    //Fluxo dos três tipos de artigo
    if(escolha == 1){
        //Instanciação do Anuncio
        std::cout << "Informe o texto do anuncio:  ";
        std::cin.ignore();
        std::getline(std::cin, info1);

        std::cout << "Informe a logo do anunciante:  ";
        std::cin >> info2;

        Anuncio *a = new Anuncio(titulo, *autor, data, link, info1, info2);
        a->salvar_no_banco();

        delete a;

    } else if(escolha == 2){
        //Instanciação da Tirinha
        std::cout << "Informe a imagem da tirinha:  ";
        std::cin >> info1;

        Tirinha *a = new Tirinha(titulo, *autor, data, link, info1);
        a->salvar_no_banco();

        delete a;

    } else if(escolha == 3){
        //Instanciação do Texto
        std::cout << "Informe o resumo do texto:  ";
        std::cin.ignore();
        std::getline(std::cin, info1);

        std::cout << "Qual a área do conhecimento do texto? ";
        std::cin.ignore();
        std::cin >> info2;

        std::cout << "Informe as palavras-chave do texto: ";
        std::cin.ignore();
        std::getline(std::cin, info3);

        Texto *a = new Texto(titulo, *autor, data, link, info1, info2, info3);
        a->salvar_no_banco();

        delete a;
    } else {
        std::cout << "Escolha inválida!";
    }
    delete autor;
}

//Método que instancia e registra o autor do artigo criado
Autor* Administrador::criar_autor(){
    std::string nome, email, formacao, area;

    std::cout << "Informe o nome do autor: ";
    std::getline(std::cin, nome);

    std::cout << "Informe o email do autor: ";
    std::cin >> email;

    std::cout << "Informe a formação do autor: ";
    std::cin.ignore();
    std::getline(std::cin, formacao);

    std::cout << "Informe a area do autor: ";
    std::getline(std::cin, area);

    Autor *autor = new Autor(nome, email, formacao, area);
    autor->salvar_no_banco();

    return autor;
}

//Método de exclusão de artigo por id no banco de dados
void Administrador::remover_artigo(){
    int id, escolha;
    std::string tabela;

    std::cout << "Deseja remover um anuncio(1), tirinha(2) ou um texto(3)? ";
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

    std::cout << "Informe o id do artigo a ser removido: ";
    std::cin >> id;

    try {
        sqlite3* db;
        char* zErrMsg = 0;
        int rc;

        std::string query = "DELETE FROM core_"+ tabela +" WHERE id = " + std::to_string(id) +"";

        rc = sqlite3_open("./db.sqlite3", &db);
        rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &zErrMsg);
        
        if (rc != SQLITE_OK) {
            sqlite3_close(db);
            throw std::invalid_argument(zErrMsg);
        }
        else {
            sqlite3_close(db);
            if(!zErrMsg && sqlite3_changes(db) > 0)
                std::cout << "Artigo removido com sucesso!" << std::endl;
            else
                std::cout << "Não foi possível concluir alteração."<<std::endl;
        }
    }
    catch (std::exception &e) {
        std::cout << "Erro ao acessar banco de dados: " << e.what() << std::endl;
    }
}

//Método de exclusão de comentário por id no banco de dados
void Administrador:: apagar_comentario(){
    int id;
    
    std::cout << "Informe o id do comentario a ser removido: ";
    std::cin >> id;

    try {
        sqlite3* db;
        char* zErrMsg = 0;
        int rc;

       std::string query = "DELETE FROM core_comentario WHERE id = " + std::to_string(id) +"";

        rc = sqlite3_open("./db.sqlite3", &db);
        rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &zErrMsg);
        
        if (rc != SQLITE_OK) {
            sqlite3_close(db);
            throw std::invalid_argument(zErrMsg);
        }
        else {
            sqlite3_close(db);
            if(!zErrMsg && sqlite3_changes(db) > 0)
                std::cout << "Comentario removido com sucesso!" << std::endl;
            else
                std::cout << "Não foi possível concluir alteração."<<std::endl;
        }
    }
    catch (std::exception &e) {
        std::cout << "Erro ao acessar banco de dados: " << e.what() << std::endl;
    }
}

//Método sobrescrito de registro do ADM no banco de dados
void Administrador::salvar_no_banco(){
    try {
        sqlite3* db;
        char* zErrMsg = 0;
        int rc;

       std::string query = "INSERT INTO core_adm (id, nome, email, senha) VALUES ('" + std::to_string(_id) + "','" + _nome + "','" + _email + "','" + std::to_string(_senha) + "')";

        rc = sqlite3_open("./db.sqlite3", &db);
        rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &zErrMsg);
        
        if (rc != SQLITE_OK) {
            sqlite3_close(db);
            throw std::invalid_argument(zErrMsg);
        }
        else {
            sqlite3_close(db);
            if(!zErrMsg && sqlite3_changes(db) > 0)
                std::cout << "ADM cadastrado com sucesso!" << std::endl;
            else
                std::cout << "Não foi possível concluir alteração."<<std::endl;
        }
    }
    catch (std::exception &e) {
        std::cout << "Erro ao acessar banco de dados: " << e.what() << std::endl;
    }
}