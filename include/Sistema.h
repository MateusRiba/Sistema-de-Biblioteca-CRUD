#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>
#include <string>

//Foward Declarations:

class Usuario;
class Livro;
class Emprestimo;
class LivroFisico;
class LivroDigital;

class Sistema {
private:
    // Coleções de ponteiros:
    std::vector<Usuario*> usuarios; //Array de Usuarios
    std::vector<Livro*> livros; //Array de Livros
    std::vector<LivroFisico*> livrosFisicos;    // Array de Livros Físicos *
    std::vector<LivroDigital*> livrosDigitais;  // Array de Livros Digitais *
    std::vector<Emprestimo> emprestimos; //Array de Emprestimos

public:
    //Construtor e Destrutor
    Sistema() = default;
    ~Sistema();

    //Métodos (Focados em CRUD)

    // Métodos de adição:
    void adicionarUsuario(Usuario* usuario);
    void adicionarLivro(Livro* livro); 
    void adicionarLivroFisico(LivroFisico* livroFisico); //*
    void adicionarLivroDigital(LivroDigital* livroDigital); //*

    // Métodos de remoção (ex.: remover por CPF, ISBN, ou diretamente por ponteiro)
    bool removerUsuarioPorCPF(const std::string& cpf);
    bool removerUsuarioPorNome(const std::string& nome);
    bool removerLivroPorISBN(const std::string& isbn);
    bool removerLivroPorTitulo(const std::string& titulo);
    bool removerLivroFisicoPorISBN(const std::string& isbn); //*
    bool removerLivroDigitalPorISBN(const std::string& isbn); //*

    // Métodos de busca
    Usuario* buscarUsuarioPorCPF(const std::string& cpf) const;
    Usuario* buscarUsuarioPorNome(const std::string& nome) const;
    Livro* buscarLivroPorISBN(const std::string& isbn) const;
    Livro* buscarLivroPorTitulo(const std::string& titulo) const;

    // Métodos de empréstimo
    void realizarEmprestimo(Usuario* u, Livro* l, const std::string& dataEmp, const std::string& dataDev);

    bool encerrarEmprestimoCpfIsbn(const std::string& cpfUsuario, const std::string& isbnLivro, const std::string& dataRealDevolucao);
    bool encerrarEmprestimoNomeTitulo(const std::string& nomeUsuario, const std::string& tituloLivro, const std::string& dataRealDevolucao);

    // Métodos de Edição 

    //Atualiza dados do usuario (recebe CPF)
    bool atualizarUsuario(const std::string& cpf,const std::string& novoNome,const std::string& novoEndereco,const std::string& novoTelefone, const std::string& novaSenha);

    //Atualiza dados de um livro (Recebe ISBN)
    bool atualizarLivro(const std::string& isbn,
                    const std::string& novoTitulo,
                    const std::string& novoAutor,
                    const std::string& novaEditora,
                    double novoValorDiaria,
                    // Parâmetros específicos de físico
                    int novoPesoGrama = -1,
                    const std::string& novaCapa = "",
                    int novoEstoque = -1,
                    // Parâmetros específicos de digital
                    int novoTamanhoArquivo = -1, 
                    const std::string& novoFormatoArquivo = "",
                    int novaLicensaDigital = -1
                    //Valores default (-1 ou "") indicam que não quero alterar esse atributo
);

    //Atualiza dados de um empréstimo (Recebe CPF + ISBN)
    bool atualizarEmprestimo(const std::string& cpfUsuario,const std::string& isbnLivro,const std::string& novaDataEmp,const std::string& novaDataDev, int novoCusto);

    //Autenticação de Usuario
    Usuario* autenticarUsuarioCPFSenha(const std::string& cpf, const std::string& senha) const;
    bool isAdministrador(const Usuario* usuario) const;


    // Métodos de listar
    void listarUsuarios() const;
    void listarLivros() const;
    void listarLivrosFisicos() const;
    void listarLivrosDigitais() const;
    void listarEmprestimos() const;

};

#endif