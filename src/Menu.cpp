#include "Menu.h"
#include "LivroFisico.h"
#include "LivroDigital.h"
#include "Sistema.h"
#include "Usuario.h"
#include "LeitorComum.h"
#include "Administrador.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

Sistema sis;

// Vetores para armazenar os livros
std::vector<LivroFisico> livrosFisicos;
std::vector<LivroDigital> livrosDigitais;


// Função para limpar o terminal
void limparTerminal() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}


void cadastrarLivroFisico() {
    std::string titulo, autor, isbn, editora, tipoCapa;
    int ano, valorDiaria, pesoGrama, quantidadeEstoque;

    std::cout << "=== Cadastro de Livro Físico ===\n";
    std::cout << "Título: ";
    std::getline(std::cin >> std::ws, titulo);
    std::cout << "Autor: ";
    std::getline(std::cin >> std::ws, autor);
    std::cout << "ISBN: ";
    std::getline(std::cin >> std::ws, isbn);
    std::cout << "Ano de Publicação: ";
    std::cin >> ano;
    std::cout << "Editora: ";
    std::getline(std::cin >> std::ws, editora);
    std::cout << "Valor Diário: ";
    std::cin >> valorDiaria;
    std::cout << "Peso (gramas): ";
    std::cin >> pesoGrama;
    std::cout << "Tipo de Capa: ";
    std::getline(std::cin >> std::ws, tipoCapa);
    std::cout << "Quantidade em Estoque: ";
    std::cin >> quantidadeEstoque;

    livrosFisicos.emplace_back(titulo, autor, isbn, ano, editora, valorDiaria, pesoGrama, tipoCapa, quantidadeEstoque);
    std::cout << "Livro físico cadastrado com sucesso!\n";
}

void cadastrarLivroDigital() {
    std::string titulo, autor, isbn, editora, formatoArquivo;
    int ano, valorDiaria, tamanhoArquivoKB, licencaDigital;

    std::cout << "=== Cadastro de Livro Digital ===\n";
    std::cout << "Título: ";
    std::getline(std::cin >> std::ws, titulo);
    std::cout << "Autor: ";
    std::getline(std::cin >> std::ws, autor);
    std::cout << "ISBN: ";
    std::getline(std::cin >> std::ws, isbn);
    std::cout << "Ano de Publicação: ";
    std::cin >> ano;
    std::cout << "Editora: ";
    std::getline(std::cin >> std::ws, editora);
    std::cout << "Valor Diário: ";
    std::cin >> valorDiaria;
    std::cout << "Tamanho do Arquivo (KB): ";
    std::cin >> tamanhoArquivoKB;
    std::cout << "Formato do Arquivo: ";
    std::getline(std::cin >> std::ws, formatoArquivo);
    std::cout << "Licença Digital: ";
    std::cin >> licencaDigital;

    livrosDigitais.emplace_back(titulo, autor, isbn, ano, editora, valorDiaria, tamanhoArquivoKB, formatoArquivo, licencaDigital);
    std::cout << "Livro digital cadastrado com sucesso!\n";
}

void exibirMenuLogin(){
    

    int opcao;

    std::string nome, cpf, endereco, telefone, senha;
    Usuario* u1 = nullptr;

    std::cout << "=== Tela de Login ===\n";
    std::cout << "1. Possuo Cadastro: ";
    std::cout <<"2 . Cadastrar-se: ";
    std::cin >> opcao;
    switch(opcao){
        case 1:
            std::cout << "CPF: ";
            std::getline(std::cin >> std::ws, cpf);
            std::cout << "Senha: ";
            std::getline(std::cin >> std::ws, senha);
            sis.buscarUsuarioPorCPF(cpf);
            if(sis.buscarUsuarioPorCPF(cpf) == nullptr){
                std::cout << "Usuario nao encontrado!\n";
                std::cout<<"Pressione qualquer tecla para continuar...";
                std::cin.ignore();
                limparTerminal();
                exibirMenuLogin();
                return;
            }
            std::cout << "Login efetuado com sucesso!\n";
            std::cout << "Bem-vindo, " << sis.buscarUsuarioPorCPF(cpf)->getNome() << "!\n";
            std::cout<<"Pressione qualquer tecla para continuar...";
            std::cin.ignore();

            break;
        case 2:
            std::cout << "Nome: ";
            std::getline(std::cin >> std::ws, nome);
            std::cout << "CPF: ";
            std::getline(std::cin >> std::ws, cpf);
            std::cout << "Endereço: ";
            std::getline(std::cin >> std::ws, endereco);
            std::cout << "Telefone: ";
            std::getline(std::cin >> std::ws, telefone);
            std::cout << "Senha: ";
            std::getline(std::cin >> std::ws, senha);

            u1 = new LeitorComum(nome, cpf, endereco, telefone, senha);
            sis.adicionarUsuario(u1);

            std::cout << "Cadastro efetuado com sucesso!\n";
            std::cout<<"Pressione qualquer tecla para voltar ao menu ...";
            std::cin.ignore();
            limparTerminal();
            exibirMenuLogin();
            break;
        default:
            std::cout << "Opção inválida! Tente novamente.\n";
            break;
    }
    limparTerminal();


}

void listarLivrosFisicos() {
    std::cout << "=== Livros Físicos ===\n";
    for (const auto& livro : livrosFisicos) {
        livro.exibir();
        std::cout << "----------------------\n";
    }
}

void listarLivrosDigitais() {
    std::cout << "=== Livros Digitais ===\n";
    for (const auto& livro : livrosDigitais) {
        livro.exibir();
        std::cout << "----------------------\n";
    }
}

void exibirMenuPrincipal() {
    std::cout << "\n=== Sistema de Gerenciamento de Livros ===\n";
    std::cout << "1. Cadastrar Livro Físico\n";
    std::cout << "2. Cadastrar Livro Digital\n";
    std::cout << "3. Listar Livros Físicos\n";
    std::cout << "4. Listar Livros Digitais\n";
    std::cout << "5. Gerenciar Usuários (não implementado)\n";
    std::cout << "0. Sair\n";
}

void gerenciarLivros() {
    int opcao = 0;

    do {
        std::cout << "\n=== Gerenciamento de Livros ===\n";
        std::cout << "1. Cadastrar Livro Físico\n";
        std::cout << "2. Cadastrar Livro Digital\n";
        std::cout << "3. Listar Livros Físicos\n";
        std::cout << "4. Listar Livros Digitais\n";
        std::cout << "0. Voltar\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrarLivroFisico();
                break;
            case 2:
                cadastrarLivroDigital();
                break;
            case 3:
                listarLivrosFisicos();
                break;
            case 4:
                listarLivrosDigitais();
                break;
            case 0:
                std::cout << "Voltando ao menu principal...\n";
                break;
            default:
                std::cout << "Opção inválida! Tente novamente.\n";
                break;
        }
    } while (opcao != 0);
}

void gerenciarUsuarios() {
    std::cout << "Gerenciamento de usuários ainda não foi implementado.\n";
}