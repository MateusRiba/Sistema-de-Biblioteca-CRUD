#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>
#include <string>

//Foward Declarations:

class Usuario;
class Livro;
class Emprestimo;

class Sistema {
private:
    // Coleções de ponteiros:
    std::vector<Usuario*> usuarios; //Array de Usuarios
    std::vector<Livro*> livros; //Array de Livros
    std::vector<Emprestimo> emprestimos; //Array de Emprestimos
    
public:
    //Construtor e Destrutor
    Sistema() = default;
    ~Sistema();

    //Métodos (Focados em CRUD)
    
    // Métodos de adição:
    void adicionarUsuario(Usuario* usuario);
    void adicionarLivro(Livro* livro);

    // Métodos de remoção (ex.: remover por CPF, ISBN, ou diretamente por ponteiro)
    bool removerUsuarioPorCPF(const std::string& cpf);
    bool removerUsuarioPorNome(const std::string& nome);
    bool removerLivroPorISBN(const std::string& isbn);
    bool removerLivroPorTitulo(const std::string& titulo);

    // Métodos de busca
    Usuario* buscarUsuarioPorCPF(const std::string& cpf) const;
    Usuario* buscarUsuarioPorNome(const std::string& nome) const;
    Livro* buscarLivroPorISBN(const std::string& isbn) const;
    Livro* buscarLivroPorTitulo(const std::string& titulo) const;

    // Métodos de empréstimo
    void realizarEmprestimo(Usuario* u, Livro* l, const std::string& dataEmp, const std::string& dataDev);

    void encerrarEmprestimoCpfIsbn(const std::string& cpfUsuario, const std::string& isbnLivro, const std::string& dataRealDevolucao);
    void encerrarEmprestimoNomeTitulo(const std::string& nomeUsuario, const std::string& tituloLivro, const std::string& dataRealDevolucao);

    // Métodos de Edição 

    // Métodos de listar
    void listarUsuarios() const;
    void listarLivros() const;
    void listarEmprestimos() const;

};

#endif