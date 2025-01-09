// Administrador.cpp
#include "Administrador.h"
#include <iostream>

// Construtor
Administrador::Administrador(const std::string& nome,
                             const std::string& cpf,
                             const std::string& endereco,
                             const std::string& telefone,
                             const std::string& senha,
                             Sistema* sis)
    : Usuario(nome, cpf, endereco, telefone, senha), sistema(sis) 
{
    // nenhuma implementação inicial
}

// Implementação do método exibir()
void Administrador::exibir() const {
    std::cout << "=== Administrador ===\n";
    std::cout << "Nome: " << this->nome << "\n";
    std::cout << "CPF: " << this->cpf << "\n";
    std::cout << "Endereço: " << this->endereco << "\n";
    std::cout << "Telefone: " << this->telefone << "\n";
}

// Cadastrar um novo usuário
bool Administrador::cadastrarUsuario(Usuario* novoUsuario) {
    if (!sistema) {
        std::cerr << "Sistema não está configurado.\n";
        return false;
    }
    sistema->adicionarUsuario(novoUsuario);
    std::cout << "Usuário cadastrado com sucesso.\n";
    return true;
}

// Remover usuário por CPF
bool Administrador::removerUsuarioPorCPF(const std::string& cpf) {
    if (!sistema) {
        std::cerr << "Sistema não está configurado.\n";
        return false;
    }
    bool removido = sistema->removerUsuarioPorCPF(cpf);
    if (removido) {
        std::cout << "Usuário com CPF " << cpf << " removido com sucesso.\n";
    } else {
        std::cout << "Falha ao remover usuário com CPF " << cpf << ".\n";
    }
    return removido;
}

// Remover usuário por Nome
bool Administrador::removerUsuarioPorNome(const std::string& nome) {
    if (!sistema) {
        std::cerr << "Sistema não está configurado.\n";
        return false;
    }
    bool removido = sistema->removerUsuarioPorNome(nome);
    if (removido) {
        std::cout << "Usuário com nome " << nome << " removido com sucesso.\n";
    } else {
        std::cout << "Falha ao remover usuário com nome " << nome << ".\n";
    }
    return removido;
}

// Editar usuário
bool Administrador::editarUsuario(const std::string& cpf,
                                   const std::string& novoNome,
                                   const std::string& novoEndereco,
                                   const std::string& novoTelefone,
                                   const std::string& novaSenha) {
    if (!sistema) {
        std::cerr << "Sistema não está configurado.\n";
        return false;
    }
    bool atualizado = sistema->atualizarUsuario(cpf, novoNome, novoEndereco, novoTelefone, novaSenha);
    if (atualizado) {
        std::cout << "Usuário com CPF " << cpf << " atualizado com sucesso.\n";
    } else {
        std::cout << "Falha ao atualizar usuário com CPF " << cpf << ".\n";
    }
    return atualizado;
}

// Cadastrar um novo livro
bool Administrador::cadastrarLivro(Livro* novoLivro) {
    if (!sistema) {
        std::cerr << "Sistema não está configurado.\n";
        return false;
    }
    sistema->adicionarLivro(novoLivro);
    std::cout << "Livro cadastrado com sucesso.\n";
    return true;
}

// Remover livro por ISBN
bool Administrador::removerLivroPorISBN(const std::string& isbn) {
    if (!sistema) {
        std::cerr << "Sistema não está configurado.\n";
        return false;
    }
    bool removido = sistema->removerLivroPorISBN(isbn);
    if (removido) {
        std::cout << "Livro com ISBN " << isbn << " removido com sucesso.\n";
    } else {
        std::cout << "Falha ao remover livro com ISBN " << isbn << ".\n";
    }
    return removido;
}

// Remover livro por Título
bool Administrador::removerLivroPorTitulo(const std::string& titulo) {
    if (!sistema) {
        std::cerr << "Sistema não está configurado.\n";
        return false;
    }
    bool removido = sistema->removerLivroPorTitulo(titulo);
    if (removido) {
        std::cout << "Livro com título \"" << titulo << "\" removido com sucesso.\n";
    } else {
        std::cout << "Falha ao remover livro com título \"" << titulo << "\".\n";
    }
    return removido;
}

// Editar livro
bool Administrador::editarLivro(const std::string& isbn,
                                 const std::string& novoTitulo,
                                 const std::string& novoAutor,
                                 const std::string& novaEditora,
                                 double novoValorDiaria,
                                 int novoPesoGrama,
                                 const std::string& novaCapa,
                                 int novoEstoque,
                                 int novoTamanhoArquivo,
                                 const std::string& novoFormatoArquivo,
                                 int novaLicensaDigital) {
    if (!sistema) {
        std::cerr << "Sistema não está configurado.\n";
        return false;
    }
    bool atualizado = sistema->atualizarLivro(isbn, novoTitulo, novoAutor, novaEditora,
                                             novoValorDiaria, novoPesoGrama, novaCapa,
                                             novoEstoque, novoTamanhoArquivo,
                                             novoFormatoArquivo, novaLicensaDigital);
    if (atualizado) {
        std::cout << "Livro com ISBN " << isbn << " atualizado com sucesso.\n";
    } else {
        std::cout << "Falha ao atualizar livro com ISBN " << isbn << ".\n";
    }
    return atualizado;
}

// Encerrar empréstimo
bool Administrador::encerrarEmprestimo(const std::string& cpfUsuario, 
                                       const std::string& isbnLivro, 
                                       const std::string& dataDevolucao) {
    if (!sistema) {
        std::cerr << "Sistema não está configurado.\n";
        return false;
    }
    bool encerrado = sistema->encerrarEmprestimoCpfIsbn(cpfUsuario, isbnLivro, dataDevolucao);
    if (encerrado) {
        std::cout << "Empréstimo encerrado com sucesso para o usuário com CPF " 
                  << cpfUsuario << " e livro com ISBN " << isbnLivro << ".\n";
    } else {
        std::cout << "Falha ao encerrar empréstimo para o usuário com CPF " 
                  << cpfUsuario << " e livro com ISBN " << isbnLivro << ".\n";
    }
    return encerrado;
}

// Editar empréstimo
bool Administrador::editarEmprestimo(const std::string& cpfUsuario,
                                     const std::string& isbnLivro,
                                     const std::string& novaDataEmp,
                                     const std::string& novaDataDev,
                                     bool marcarFinalizado,
                                     int novoCusto) {
    if (!sistema) {
        std::cerr << "Sistema não está configurado.\n";
        return false;
    }
    bool atualizado = sistema->atualizarEmprestimo(cpfUsuario, isbnLivro, 
                                                   novaDataEmp, novaDataDev, novoCusto);
    if (atualizado) {
        std::cout << "Empréstimo atualizado com sucesso para o usuário com CPF " 
                  << cpfUsuario << " e livro com ISBN " << isbnLivro << ".\n";
    } else {
        std::cout << "Falha ao atualizar empréstimo para o usuário com CPF " 
                  << cpfUsuario << " e livro com ISBN " << isbnLivro << ".\n";
    }
    return atualizado;
}

// Getter para Sistema
Sistema* Administrador::getSistema() const {
    return sistema;
}

// Setter para Sistema
void Administrador::setSistema(Sistema* sis) {
    sistema = sis;
}
