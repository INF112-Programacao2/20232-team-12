#include "../include/Administrador.h"
#include "../include/Leitor.h"
#include "../include/Autor.h"
#include "../include/Comentario.h"
#include "../include/Anuncio.h"
#include "../include/Tirinha.h"
#include "../include/Texto.h"

#include <iostream>
#include <cstring>

int main (void) {
    std::string nome, email, data;
    int senha, opcao;
    
    std::cout << "Bem vindo! Informe seus dados de cadastro." << std::endl;

    std::cout << "Nome: ";
    std::getline(std::cin, nome);

    std::cout << "Email: ";
    std::cin >> email;

    std::cout << "Você é leitor(1) ou administrador(2)? " << std::endl;
    std::cin >> opcao;

    //Fluxo do Leitor
    if(opcao == 1){

        //Verificação da data
        while(true){
            std::cout << "Data do inicio da assinatura: ";
            std::cin >> data;

            if(data.find('/') != std::string::npos){
                if(Usuario::validar_data(data)) 
                    break;
                else 
                    std::cout << "Informe uma data válida!" << std::endl;
            } else 
                std::cout << "Informe uma data do formato DD/MM/AAAA." << std::endl;
        }

        Leitor *leitor = new Leitor(nome, email, true, data);
        leitor->salvar_no_banco();

        //Menu de opções do leitor
        while(true){
            std::cout << "-------------------------" << std::endl;
            std::cout << "O que deseja fazer agora? " << std::endl;
            std::cout << "1 - Ver jornal" << std::endl;
            std::cout << "2 - Postar comentário" << std::endl;
            std::cout << "3 - Favoritar artigo" << std::endl;
            std::cout << "4 - Remover favorito de artigo" << std::endl;
            std::cout << "5 - Sair" << std::endl;
            std::cout << "Sua escolha: ";

            int escolha;
            std::cin >> escolha;
            std::cout << "-------------------------" << std::endl;

            switch (escolha)  {
            case 1:
                leitor->ver_jornal();
                break;

            case 2:
                leitor->postar_comentario();
                break;
            
            case 3:
                leitor->favoritar_artigo();
                break;

            case 4:
                leitor->remover_artigo_dos_favoritos();
                break;

            case 5:
                exit(0);
                break;
            
            default:
                std::cout << "Escolha inválida!" << std::endl;
                exit(0);
                break;
            }
        }

        delete leitor;

    } else if(opcao == 2){
        //Fluxo do ADM
        std::cout << "Senha numérica: ";
        std::cin >> senha;

        Administrador *adm = new Administrador(nome, email, senha);
        adm->salvar_no_banco();

        //Menu de opções do ADM
        while(true){
            std::cout << "-------------------------" << std::endl;
            std::cout << "O que deseja fazer agora? " << std::endl;
            std::cout << "1 - Postar artigo" << std::endl;
            std::cout << "2 - Remover artigo" << std::endl;
            std::cout << "3 - Apagar comentário" << std::endl;
            std::cout << "4 - Sair" << std::endl;
            std::cout << "Sua escolha: ";

            int escolha;
            std::cin >> escolha;
            std::cout << "-------------------------" << std::endl;

            switch (escolha)  {
            case 1:
                adm->postar_artigo();
                break;

            case 2:
                adm->remover_artigo();
                break;
            
            case 3:
                adm->apagar_comentario();
                break;
            
            case 4:
                exit(0);
                break;
            
            default:
                std::cout << "Escolha inválida!" << std::endl;
                exit(0);
                break;
            }
        }

        delete adm;

    } else {
        std::cout << "Eita! O que você é então?" << std::endl;
    }
}