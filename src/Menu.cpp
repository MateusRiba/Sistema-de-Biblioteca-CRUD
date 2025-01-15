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
                std::cin >> novoTelefone; //Testar (há)
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

void gerenciarLivros() {

    int opcao = 0;

        do {
            std::cout << "\n=== Gerenciamento de Livros ===\n";
            std::cout << "1. Cadastrar Livro\n";
            std::cout << "2. Remover Livro por ISBN\n";
            std::cout << "3. Editar Livro existente\n";
            std::cout << "4. Listar livros\n";
            std::cout << "0. Voltar\n";
            std::cout << "Escolha uma opção: ";
            std::cin >> opcao;

            switch(opcao){
        
                //Cadastro de livro
                case 1: {
                    int tipoLivro;
                    
                    //Verificação do tipo de livro
                    std::cout << "Escolha o tipo de livro para cadastrar:\n";
                    std::cout << "1. Livro Físico\n";
                    std::cout << "2. Livro Digital\n";
                    std::cout << "Escolha uma opção: ";
                    std::cin >> tipoLivro;

                    //Se for Fisico
                    if(tipoLivro == 1){
                    std::string titulo, autor, isbn, editora, tipoCapa;
                    double valorDiaria;
                    int ano, pesoGrama, quantidadeEstoque;

                    std::cout << "=== Cadastro de Livro Físico ===\n";
                    std::cout << "Título: ";
                    std::cin.ignore(); // Ignorar newline residual
                    std::getline(std::cin, titulo);
                    std::cout << "Autor: ";
                    std::getline(std::cin, autor);
                    std::cout << "ISBN: ";
                    std::getline(std::cin, isbn);
                    std::cout << "Ano de Publicação: ";
                    std::cin >> ano;
                    std::cout << "Editora: ";
                    std::cin.ignore(); 
                    std::getline(std::cin, editora);
                    std::cout << "Valor Diário: ";
                    std::cin >> valorDiaria;
                    std::cout << "Peso (gramas): ";
                    std::cin >> pesoGrama;
                    std::cout << "Tipo de Capa: ";
                    std::cin.ignore(); 
                    std::getline(std::cin, tipoCapa);
                    std::cout << "Quantidade em Estoque: ";
                    std::cin >> quantidadeEstoque;

                    LivroFisico* livroFisico = new LivroFisico(titulo, autor, isbn, ano, editora, valorDiaria, pesoGrama, tipoCapa, quantidadeEstoque);
                    sis.adicionarLivroFisico(livroFisico);

                    std::cout << "Livro físico cadastrado com sucesso!\n";
                }

                //Se for Digital
                else if(tipoLivro == 2){
                    std::string titulo, autor, isbn, editora, formatoArquivo;
                    double valorDiaria;
                    int ano, tamanhoArquivoKB, licencaDigital;

                    std::cout << "=== Cadastro de Livro Digital ===\n";
                    std::cout << "Título: ";
                    std::cin.ignore(); // Ignorar newline residual
                    std::getline(std::cin, titulo);
                    std::cout << "Autor: ";
                    std::getline(std::cin, autor);
                    std::cout << "ISBN: ";
                    std::getline(std::cin, isbn);
                    std::cout << "Ano de Publicação: ";
                    std::cin >> ano;
                    std::cout << "Editora: ";
                    std::cin.ignore(); 
                    std::getline(std::cin, editora);
                    std::cout << "Valor Diário: ";
                    std::cin >> valorDiaria;
                    std::cout << "Tamanho do Arquivo (KB): ";
                    std::cin >> tamanhoArquivoKB;
                    std::cout << "Formato do Arquivo: ";
                    std::cin.ignore(); 
                    std::getline(std::cin, formatoArquivo);
                    std::cout << "Licença Digital: ";
                    std::cin >> licencaDigital;

                    LivroDigital* livroDigital = new LivroDigital(titulo, autor, isbn, ano, editora, valorDiaria, tamanhoArquivoKB, formatoArquivo, licencaDigital);
                    sis.adicionarLivroDigital(livroDigital);

                    std::cout << "Livro digital cadastrado com sucesso!\n";
                }
                else{
                    std::cout << "Opção inválida para tipo de livro.\n";
                }

                std::cout << "Pressione Enter para continuar...";
                std::cin.ignore();
                std::cin.get();
                limparTerminal();
                break;
                }
                
                //Remoção de Livro por ISBN
                case 2: {
                    std::string isbn;
                    std::cout << "Digite o ISBN do livro a ser removido: ";
                    std::cin.ignore(); 
                    std::getline(std::cin, isbn);

                    bool removidoFisico = sis.removerLivroFisicoPorISBN(isbn);
                    bool removidoDigital = sis.removerLivroDigitalPorISBN(isbn);
                                    //OU
                    if(removidoFisico || removidoDigital){
                        std::cout << "Livro removido com sucesso.\n";
                    }
                    else{
                        std::cout << "Livro com ISBN " << isbn << " não encontrado.\n";
                    }

                    std::cout << "Pressione Enter para continuar...";
                    std::cin.ignore();
                    std::cin.get();
                    limparTerminal();
                    break;
                }

                // Editar Livro existente
                case 3: {
                    std::string isbn;
                    std::cout << "Digite o ISBN do livro a ser editado: ";
                    std::cin.ignore(); 
                    std::getline(std::cin, isbn);

                    Livro* livro = sis.buscarLivroPorISBN(isbn);
                    if(livro == nullptr){
                        std::cout << "Livro com ISBN " << isbn << " não encontrado.\n";
                        std::cout << "Pressione Enter para continuar...";
                        std::cin.ignore();
                        std::cin.get();
                        limparTerminal();
                        break;
                    }
                    
                    //Menu de Edição de Livro
                    std::cout << "=== Edição de Livro ===\n";
                    std::cout << "Digite o novo título (vazio para não alterar): ";
                    std::string novoTitulo;
                    std::getline(std::cin, novoTitulo);

                    std::cout << "Digite o novo autor (vazio para não alterar): ";
                    std::string novoAutor;
                    std::getline(std::cin, novoAutor);

                    std::cout << "Digite a nova editora (vazio para não alterar): ";
                    std::string novaEditora;
                    std::getline(std::cin, novaEditora);

                    std::cout << "Digite o novo valor diário (0 para não alterar): ";
                    double novoValorDiaria;
                    std::cin >> novoValorDiaria;

                    if(LivroFisico* lf = dynamic_cast<LivroFisico*>(livro)){
                        std::cout << "Digite o novo peso (gramas) (-1 para não alterar): ";
                        int novoPesoGrama;
                        std::cin >> novoPesoGrama;
                        std::cout << "Digite o novo tipo de capa (vazio para não alterar): ";
                        std::cin.ignore(); // Ignorar newline residual
                        std::string novaCapa;
                        std::getline(std::cin, novaCapa);
                        std::cout << "Digite a nova quantidade em estoque (-1 para não alterar): ";
                        int novoEstoque;
                        std::cin >> novoEstoque;

                        // Atualizar atributos
                        if(!novoTitulo.empty()) lf->setTitulo(novoTitulo);
                        if(!novoAutor.empty()) lf->setAutor(novoAutor);
                        if(!novaEditora.empty()) lf->setEditora(novaEditora);
                        if(novoValorDiaria != 0) lf->setValorDiaria(novoValorDiaria);
                        if(novoPesoGrama != -1) lf->setPesoGrama(novoPesoGrama);
                        if(!novaCapa.empty()) lf->setTipoCapa(novaCapa);
                        if(novoEstoque != -1) lf->setQuantidadeEstoque(novoEstoque);

                        std::cout << "Livro físico atualizado com sucesso.\n";
                    }
                    else if(LivroDigital* ld = dynamic_cast<LivroDigital*>(livro)){
                        std::cout << "Digite o novo tamanho do arquivo (KB) (-1 para não alterar): ";
                        int novoTamanhoArquivoKB;
                        std::cin >> novoTamanhoArquivoKB;
                        std::cout << "Digite o novo formato do arquivo (vazio para não alterar): ";
                        std::cin.ignore(); // Ignorar newline residual
                        std::string novoFormatoArquivo;
                        std::getline(std::cin, novoFormatoArquivo);
                        std::cout << "Digite a nova licença digital (-1 para não alterar): ";
                        int novaLicencaDigital;
                        std::cin >> novaLicencaDigital;

                        // Atualizar atributos
                        if(!novoTitulo.empty()) ld->setTitulo(novoTitulo);
                        if(!novoAutor.empty()) ld->setAutor(novoAutor);
                        if(!novaEditora.empty()) ld->setEditora(novaEditora);
                        if(novoValorDiaria != 0) ld->setValorDiaria(novoValorDiaria);
                        if(novoTamanhoArquivoKB != -1) ld->setTamanhoArquivoKB(novoTamanhoArquivoKB);
                        if(!novoFormatoArquivo.empty()) ld->setFormatoArquivo(novoFormatoArquivo);
                        if(novaLicencaDigital != -1) ld->setLicensaDigital(novaLicencaDigital);

                        std::cout << "Livro digital atualizado com sucesso.\n";
                    }

                    std::cout << "Pressione Enter para continuar...";
                    std::cin.ignore();
                    std::cin.get();
                    limparTerminal();
                    break;
                }

                // Listar Livros
                case 4: {
                    int subOpcao = 0;

                    do {
                        std::cout << "\n=== Listagem de Livros ===\n";
                        std::cout << "1. Listar Livros Físicos\n";
                        std::cout << "2. Listar Livros Digitais\n";
                        std::cout << "0. Voltar\n";
                        std::cout << "Escolha uma opção: ";
                        std::cin >> subOpcao;

                        switch(subOpcao){
                            case 1:
                                sis.listarLivrosFisicos();
                                std::cout << "Pressione Enter para continuar...";
                                std::cin.ignore();
                                std::cin.get();
                                limparTerminal();
                                break;
                            case 2:
                                sis.listarLivrosDigitais();
                                std::cout << "Pressione Enter para continuar...";
                                std::cin.ignore();
                                std::cin.get();
                                limparTerminal();
                                break;
                            case 0:
                                std::cout << "Voltando à listagem principal de livros...\n";
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
                    } while(subOpcao != 0);

                    break;
                }

                // Voltar ao Menu Anterior
                case 0:
                    std::cout << "Voltando ao menu anterior...\n";
                    std::cout << "Pressione Enter para continuar...";
                    std::cin.ignore();
                    std::cin.get();
                    limparTerminal();
                    break;

                // Opção Inválida
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

        gerenciarLivros();    
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