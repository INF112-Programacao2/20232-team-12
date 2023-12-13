#include "../include/Artigo.h"
#include "../include/Autor.h"

//Variavel que garante ids únicos para cada artigo
//Ao inicializar busca no banco pelo ultimo (maior) id inserido e o incrementa
int Artigo::_numero_de_artigos = Artigo::get_ultimo_id() + 1;

//Construtor do Artigo
Artigo::Artigo(std::string titulo, Autor autor, std::string data, std::string link):
    _id(_numero_de_artigos), _titulo(titulo), _autor(autor), _data(data), _link(link)
{
    _numero_de_artigos++;
}
   
//Destrutor do Artigo
Artigo::~Artigo(){}

//Métodos get e set
int Artigo::get_id(){
    return this->_id;
}

std::string Artigo::get_titulo(){
    return this->_titulo;
}

std::string Artigo::get_data(){
    return this->_data;
}

std::string Artigo::get_link(){
    return this->_link;
}

void Artigo::set_titulo(std::string titulo){
    _titulo = titulo;
}

void Artigo::set_data(std::string data){
    _data = data;
}

void Artigo::set_link(std::string link){
    _link = link;
}

//Método que consulta o banco de dados para encontrar o maior id inserido dentre os artigos
int Artigo::get_ultimo_id(){
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
        std::string countQuery = "SELECT MAX(id) FROM ("
                            "SELECT id FROM core_texto "
                              "UNION "
                              "SELECT id FROM core_tirinha "
                              "UNION "
                              "SELECT id FROM core_anuncio"
                              ") AS max_ids";
       

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