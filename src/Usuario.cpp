#include "../include/Usuario.h"

//Variavel que garante ids únicos para cada usuário
//Ao inicializar busca no banco pelo ultimo (maior) id inserido e o incrementa
int Usuario::_numero_de_usuarios = Usuario::get_ultimo_id() + 1;

//Construtor do Usuario
Usuario::Usuario(std::string nome, std::string email):
    _id(_numero_de_usuarios),
    _nome(nome),
    _email(email)
{
    _numero_de_usuarios++;
}

//Destrutor do Usuario
Usuario::~Usuario(){}

//Métodos get e set
int Usuario::get_id(){
    return this->_id;
}

std::string Usuario::get_nome(){
    return this->_nome;
}

std::string Usuario::get_email(){
    return this->_email;
}

void Usuario::set_nome(std::string nome){
    _nome = nome;
}

void Usuario::set_email(std::string email){
    _email = email;
}

//Método que verifica se a data está nos intervalos válidos
bool Usuario::validar_data(std::string a){
    std::string delimiter = "/";
    std::vector<int> numeros;

    size_t pos;
    try {
        while ((pos = a.find(delimiter)) != std::string::npos) {
            numeros.push_back(std::stoi(a.substr(0, pos)));
            a.erase(0, pos + delimiter.length());
        }
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
    }

    if (!a.empty()) {
    numeros.push_back(std::stoi(a));
    }

    //Retorna se o dia está entre 1 e 31, o mês entre 1 e 12 e o ano entre 1900 e 2023
    return (numeros[0] >= 1 && numeros[0] <= 31) && (numeros[1] >= 1 && numeros[1] <= 12) && (numeros[2] >= 1900 && numeros[2] <= 2023);
}

//Método que consulta o banco de dados para encontrar o maior id inserido dentre os usuários
int Usuario::get_ultimo_id(){
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
                            "SELECT id FROM core_adm "
                              "UNION "
                              "SELECT id FROM core_leitor "
                              "UNION "
                              "SELECT id FROM core_autor"
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