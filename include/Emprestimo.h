#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include <string>

//Forward Declarations: para armazenar ponteiros (Usuario*, Livro*) sem precisar incluir todos os headers de Usuario e Livro neste arquivo.

class Usuario;
class Livro;

class Emprestimo {
private:
    //Ponteiro para a classe base abstrata Usuario
    Usuario* usuario;       
    //Ponteiro para a classe base abstrata Livro
    Livro* livro;           
    
    //Datas em formato string (Talvez seja modificado caso seja implementado biblioteca de tempo)
    std::string dataEmprestimo;  
    std::string dataDevolucao;   
    
    //Indica se o empréstimo já foi encerrado
    bool finalizado;

public:
    /*
      Construtor:
      Recebe ponteiros para Usuario e Livro.
      Recebe data de empréstimo e data de devolução.
      Marca o empréstimo como não finalizado (finalizado = false).
    */
    Emprestimo(Usuario* u, Livro* l, const std::string& dataEmp, const std::string& dataDev);

    /*
      Método para encerrar/finalizar o empréstimo:
      Recebe a data real de devolução e marca 'finalizado = true'.
    */
    void finalizarEmprestimo(const std::string& dataRealDevolucao);

    /*
      Método de exibição (para debugging ou interface simples):
      Mostra qual usuário pegou o livro, datas e status.
      Para chamar métodos de Usuario e Livro (como getNome(), getTitulo()) 
      é necessário o #include "Usuario.hpp" e "Livro.hpp" no arquivo .cpp (implementação).
    */
    void exibirEmprestimo() const;

    // Retorna true se o empréstimo já foi finalizado (livro devolvido).
    bool isFinalizado() const;
};

#endif 
