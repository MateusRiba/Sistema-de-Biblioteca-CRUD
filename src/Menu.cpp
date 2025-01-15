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

//Define o Administrador
Usuario* admin = new Administrador("Admin", "701.678.104-64", "Rua Senador Fabio de Barros 163", "081 99999-6117", "1230", &sis);

struct Inicializador { //Adiciona o admin
    Inicializador() {
        sis.adicionarUsuario(admin);
    }
} inicializador;

// Função para limpar o terminal
void limparTerminal() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}

//Funções de Cadastro
void cadastrarLivroFisico() {
    std::string titulo, autor, isbn, editora, tipoCapa;
    double valorDiaria; // Alterado para double
    int ano, pesoGrama, quantidadeEstoque;

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

    LivroFisico* livroFisico = new LivroFisico(titulo, autor, isbn, ano, editora, valorDiaria, pesoGrama, tipoCapa, quantidadeEstoque);
    sis.adicionarLivroFisico(livroFisico);
    
    std::cout << "Livro físico cadastrado com sucesso!\n";
}

void cadastrarLivroDigital() {
    std::string titulo, autor, isbn, editora, formatoArquivo;
    double valorDiaria; // Alterado para double
    int ano, tamanhoArquivoKB, licencaDigital;

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

    LivroDigital* livroDigital = new LivroDigital(titulo, autor, isbn, ano, editora, valorDiaria, tamanhoArquivoKB, formatoArquivo, licencaDigital);
    sis.adicionarLivroDigital(livroDigital);

    std::cout << "Livro digital cadastrado com sucesso!\n";
}

//Função de exibição de Livro
ResultadoLogin exibirMenuLogin(){
    while(true) {
        int opcao;

        std::string nome, cpf, endereco, telefone, senha;
        Usuario* u1 = nullptr;
        bool isADM = false;

        std::cout << "=== Tela de Login ===\n";
        std::cout << "1. Possuo Cadastro\n";
        std::cout <<"2 . Cadastrar-se\n";
        std::cout << "3. Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;
        
        switch(opcao){
            case 1:
                std::cout << "CPF: ";
                std::getline(std::cin >> std::ws, cpf);
                std::cout << "Senha: ";
                std::getline(std::cin >> std::ws, senha);
                
                u1 = sis.autenticarUsuarioCPFSenha(cpf,senha);
                
                if(u1 == nullptr){
                    std::cout <<"Credenciais inválidas ou usuário não encontrado!\n";
                    std::cout<<"Pressione qualquer tecla para continuar...";
                    std::cin.ignore();
                    std::cin.get();
                    limparTerminal();
                    break;
                }
                std::cout << "Login efetuado com sucesso!\n";
                std::cout << "Bem-vindo, " << u1->getNome() << "!\n";
                std::cout<<"Pressione qualquer tecla para continuar...";
                std::cin.ignore();
                std::cin.get();
                limparTerminal();

                // Identifica o tipo de usuário
                if(sis.isAdministrador(u1)){
                    isADM = true;
                }
                else {
                    // Chama a interface do Leitor Comum
                    isADM = false;
                }

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

            case 3:
                std::cout << "Encerrando o sistema. Até mais!\n";
                return ResultadoLogin{nullptr, false}; // Indica que o programa deve encerrar

            default:
                std::cout << "Opção inválida! Tente novamente.\n";
                std::cout << "Pressione Enter para continuar...";
                std::cin.ignore();
                limparTerminal();
                exibirMenuLogin();
                break;
        }
        limparTerminal();
    }
}

//Funções de Gerenciamento:
void gerenciarUsuarios() {
    int opcao = 0;

    do {
        std::cout << "\n=== Gerenciamento de Usuários ===\n";
        std::cout << "1. Cadastrar Usuário\n";
        std::cout << "2. Remover Usuário por CPF\n";
        std::cout << "3. Remover Usuário por Nome\n";
        std::cout << "4. Editar Usuário existente\n";
        std::cout << "5. Listar Usuários\n";
        std::cout << "0. Voltar\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch(opcao){
            //Cadastro de Usuario
            case 1: {
                std::string tipo, nome, cpf, endereco, telefone, senha;
                std::cout << "Digite o tipo de usuário (Administrador/LeitorComum): ";
                std::cin >> tipo;
                std::cout << "Digite o nome do Usuario: ";
                std::cin.ignore(); // Ignorar caractere residual
                std::getline(std::cin, nome);
                std::cout << "Digite o CPF: ";
                std::cin >> cpf;
                std::cout << "Digite o endereço: ";
                std::cin.ignore();
                std::getline(std::cin, endereco);
                std::cout << "Digite o telefone: ";
                std::cin >> telefone;
                std::cout << "Digite a senha: ";
                std::cin >> senha;

                Usuario* novoUsuario = nullptr;
                if (tipo == "Administrador" || tipo == "administrador") {
                    novoUsuario = new Administrador(nome, cpf, endereco, telefone, senha, &sis);
                }
                else if (tipo == "LeitorComum" || tipo == "leitorcomum") {
                    novoUsuario = new LeitorComum(nome, cpf, endereco, telefone, senha);
                }
                else {
                    std::cout << "Tipo de usuário inválido.\n";
                    std::cout << "Pressione Enter para continuar...";
                    std::cin.ignore();
                    std::cin.get();
                    limparTerminal();
                    break;
                }

                sis.adicionarUsuario(novoUsuario); //Adiciona o usuario para o Array no sistema
                std::cout << "Usuário cadastrado com sucesso.\n";
                std::cout << "Pressione Enter para continuar...";
                std::cin.ignore();
                std::cin.get();
                limparTerminal();
                break;
            }
            //Remoção de Usuario por CPF
            case 2: {
                std::string cpf;
                std::cout << "Digite o CPF do usuário a ser removido: ";
                std::cin >> cpf;
                if (sis.removerUsuarioPorCPF(cpf)) {
                    std::cout << "Usuário removido com sucesso.\n";
                }
                else {
                    std::cout << "Falha ao remover usuário.\n";
                }
                std::cout << "Pressione Enter para continuar...";
                std::cin.ignore();
                std::cin.get();
                limparTerminal();
                break;
            }
            //Remoção de Usuario por Nome
            case 3: {
                std::string nome;
                std::cout << "Digite o nome do usuário a ser removido: ";
                std::cin.ignore();
                std::getline(std::cin, nome);
                if (sis.removerUsuarioPorNome(nome)) {
                    std::cout << "Usuário removido com sucesso.\n";
                }
                else {
                    std::cout << "Falha ao remover usuário.\n";
                }
                std::cout << "Pressione Enter para continuar...";
                std::cin.ignore();
                std::cin.get();
                limparTerminal();
                break;
            }
            //Edição de Usuario Existente
            case 4: {
                std::string cpf, novoNome, novoEndereco, novoTelefone, novaSenha;
                std::cout << "Digite o CPF do usuário a ser editado: ";
                std::cin >> cpf;
                std::cout << "Digite o novo nome (vazio para não alterar): ";
                std::cin.ignore();
                std::getline(std::cin, novoNome);
                std::cout << "Digite o novo endereço (vazio para não alterar): ";
                std::getline(std::cin, novoEndereco);
                std::cout << "Digite o novo telefone (vazio para não alterar): ";
                std::cin >> novoTelefone; //Testar (há bug)
                std::cout << "Digite a nova senha (vazio para não alterar): ";
                std::cin >> novaSenha; //Testar (há bug)

                Usuario* usuario = sis.buscarUsuarioPorCPF(cpf);
                if (usuario == nullptr) {
                    std::cout << "Usuário não encontrado.\n";
                    std::cout << "Pressione Enter para continuar...";
                    std::cin.ignore();
                    std::cin.get();
                    limparTerminal();
                    break;
                }

                // é preciso subistituir as strings vazias por valores atuais
                std::string atualNome = usuario->getNome();
                std::string atualEndereco = usuario->getEndereco();
                std::string atualTelefone = usuario->getTelefone();
                std::string atualSenha = usuario->getSenha();

                bool sucesso = sis.atualizarUsuario(
                    cpf, 
                    novoNome.empty() ? atualNome : novoNome, //Se novoNome estiver Vazia: novoNome vira o nome atual
                    novoEndereco.empty() ? atualEndereco : novoEndereco, 
                    novoTelefone.empty() ? atualTelefone : novoTelefone, 
                    novaSenha.empty() ? atualSenha : novaSenha
                );

                if (sucesso) {
                    std::cout << "Usuário atualizado com sucesso.\n";
                }
                else {
                    std::cout << "Falha ao atualizar usuário.\n";
                }
                std::cout << "Pressione Enter para continuar...";
                std::cin.ignore();
                std::cin.get();
                limparTerminal();
                break;
            }
            //Listagem de Usuarios
            case 5:
                sis.listarUsuarios();
                std::cout << "Pressione Enter para continuar...";
                std::cin.ignore();
                std::cin.get();
                limparTerminal();
                break;
            case 0:
                std::cout << "Voltando ao menu anterior...\n";
                std::cout << "Pressione Enter para continuar...";
                std::cin.ignore();
                std::cin.get();
                limparTerminal();
                break;
            default:
                std::cout << "Opção inválida! Tente novamente.\n";
                std::cout << "Pressione Enter para continuar...";
                std::cin.ignore();
                std::cin.get();
                limparTerminal();
                break;
        }
    } while(opcao != 0);
}

void exibirInterfaceAdministrador(Sistema& sis, Administrador* admin) {
    //Verificação inicial
    if (!admin) {
        std::cout << "Erro: Administrador inválido.\n";
        return;
    }
    
    int opcao;
    
    std::cout << "\n=== Gerenciamento do Sistema ===\n";
    std::cout << "1. Gerenciar Usuarios\n";;
    std::cout << "2. Gerenciar Livros\n";
    std::cout << "3. Gerenciar Emprestimos ativos\n";
    std::cout << "4. Sair\n";
    std::cout << "Escolha uma opção: ";
    std::cin >> opcao;

    switch(opcao){
        //Gerenciar Usuario
        case 1:
            
        gerenciarUsuarios();
        break;
        //Gerenciar Livros
        case 2:

        std::cout << "\n=== Sistema de Gerenciamento de Usuarios ===\n";
            std::cout << "1. Visualizar Livros\n";;
            std::cout << "2. Adicionar Livro\n";
            std::cout << "3. Apagar Livro do Sistema\n";
            std::cout << "4. Modificar Livro por ISBN\n";
            std::cout << "5. Sair\n";
            std::cout << "Escolha uma opção: ";
            std::cin >> opcao;         
        break;

        //Gerenciar Emprestimos
        case 3:

        std::cout << "\n=== Sistema de Gerenciamento de Emprestimos ===\n";
            std::cout << "1. Visualizar Emprestimos ativos\n";;
            std::cout << "2. Criar Emprestimo\n";
            std::cout << "3. Encerrar Emprestimo\n";
            std::cout << "4. Modificar Emprestimo por CPF e ISBN\n";
            std::cout << "5. Sair\n";
            std::cout << "Escolha uma opção: ";        
        break;

        case 4:



            default:
                std::cout << "Opção inválida! Tente novamente.\n";
                std::cout << "Pressione Enter para continuar...";
                std::cin.ignore();
                limparTerminal();
                exibirMenuLogin();
                break;
        }
        limparTerminal();
}

/*void exibirInterfaceLeitorComum() {
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
                sis.listarLivrosFisicos();
                break;
            case 4:
                sis.listarLivrosDigitais();
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
*/