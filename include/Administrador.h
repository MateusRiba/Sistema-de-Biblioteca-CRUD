// Administrador.h
#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "Usuario.h"     // Classe base Usuario
#include "Sistema.h"     // Para acessar os métodos do Sistema
#include "Livro.h"       // Necessário para manipular objetos Livro
#include "Emprestimo.h"  // Necessário para manipular objetos Emprestimo

#include <string>

class Administrador : public Usuario {
private:
    Sistema* sistema; // Ponteiro para o Sistema para gerenciar operações

public:
    // Construtor
    Administrador(const std::string& nome,
                 const std::string& cpf,
                 const std::string& endereco,
                 const std::string& telefone,
                 const std::string& senha,
                 Sistema* sis);

    // Implementação do método virtual exibir()
    void exibir() const override;

    // ========= Métodos para gerenciar usuários =========
    bool cadastrarUsuario(Usuario* novoUsuario);
    bool removerUsuarioPorCPF(const std::string& cpf);
    bool removerUsuarioPorNome(const std::string& nome);
    bool editarUsuario(const std::string& cpf,
                       const std::string& novoNome,
                       const std::string& novoEndereco,
                       const std::string& novoTelefone,
                       const std::string& novaSenha);

    // ========= Métodos para gerenciar livros =========
    bool cadastrarLivro(Livro* novoLivro);
    bool removerLivroPorISBN(const std::string& isbn);
    bool removerLivroPorTitulo(const std::string& titulo);
    bool editarLivro(const std::string& isbn,
                     const std::string& novoTitulo,
                     const std::string& novoAutor,
                     const std::string& novaEditora,
                     double novoValorDiaria,
                     int novoPesoGrama,
                     const std::string& novaCapa,
                     int novoEstoque,
                     int novoTamanhoArquivo,
                     const std::string& novoFormatoArquivo,
                     int novaLicensaDigital);

    // ========= Métodos para gerenciar empréstimos =========
    bool encerrarEmprestimo(const std::string& cpfUsuario,
                            const std::string& isbnLivro,
                            const std::string& dataDevolucao);
    bool editarEmprestimo(const std::string& cpfUsuario,
                          const std::string& isbnLivro,
                          const std::string& novaDataEmp,
                          const std::string& novaDataDev,
                          bool marcarFinalizado,
                          int novoCusto);

    // Getter/Setter para Sistema
    void setSistema(Sistema* sis);
    Sistema* getSistema() const;
};

#endif // ADMINISTRADOR_H
