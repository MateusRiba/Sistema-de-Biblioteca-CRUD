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
    
    //Indica o custo do emprestimo que será calculado imediatamente na sua criação
    int custo;

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

    //Destrutor Generico
    ~Emprestimo();

    /*
      Método para encerrar/finalizar o empréstimo:
      Recebe a data real de devolução e marca 'finalizado = true'.
    */
    void finalizarEmprestimo(const std::string& dataRealDevolucao);

    //Método de exibição (para debugging ou interface simples):
    void exibirEmprestimo() const;

    //Set e Gets (E verificação)

    Usuario* getUsuario() const;
    void setUsuario(Usuario* u);

    Livro* getLivro() const;
    void setLivro(Livro* l);

    std::string getDataEmprestimo() const;
    void setDataEmprestimo(const std::string& dataEmp);

    std::string getDataDevolucao() const;
    void setDataDevolucao(const std::string& dataDev);

    // Retorna true se o empréstimo já foi finalizado (livro devolvido).
    bool isFinalizado() const;
    void setFinalizado(bool status);

    int getCusto() const;
    void setCusto(int custo);

};

#endif 
