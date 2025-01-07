#include "Emprestimo.h"

//Inclusão dos headers de Usuario e Livro, pois aqui na implementação será necessário
#include "Usuario.h"
#include "Livro.h"

#include <iostream> 
using namespace std;

/*
  Construtor:
  - Inicializa os ponteiros de usuario e livro, Armazena as datas e finalizado começa como false (não devolvido ainda).
*/
Emprestimo::Emprestimo(Usuario* u, Livro* l, const std::string& dataEmp, const std::string& dataDev)
    : usuario(u), livro(l), dataEmprestimo(dataEmp), dataDevolucao(dataDev),finalizado(false) {
    
}

void Emprestimo::finalizarEmprestimo(const std::string& dataRealDevolucao) {
    dataDevolucao = dataRealDevolucao;
    finalizado = true;
}
/*
  função de exibirEmprestimo:
  Se Usuario e Livro tiverem métodos para exibir nome, título, etc.,
    podemos chamá-los. Exemplo:
      usuario->getNome();
      livro->getTitulo();
  OBS: (IMPORTANTE) Como Usuario e Livro são abstratas, de fato "this->usuario" pode
    apontar para um LeitorComum ou Administrador; "this->livro" pode ser
    um LivroFisico ou LivroDigital.
*/
void Emprestimo::exibirEmprestimo() const {
    cout << "=== Emprestimo ===\n";
    
    cout << "Usuario que alugou o Livro:" << endl;
    cout << usuario->getNome() << endl;
    cout << "Livro alugado:" << endl;
    cout << livro->getTitulo() << endl;

    // Se Usuario.h tem um método 'exibir()' ou 'getNome()', poderíamos usar:
    //   usuario->exibir();   // se for polimórfico
    //   std::cout << "Usuario: " << usuario->getNome() << std::endl;
    // (Vai depender de como voce definiu a classe Usuario.)

    // Se Livro.h tem algo como getTitulo():
    //   std::cout << "Livro: " << livro->getTitulo() << std::endl;

    cout << "Data de Emprestimo: " << dataEmprestimo << "\n";
    cout << "Data de Devolucao (prevista ou real): " << dataDevolucao << "\n";
    cout << "Status: " << (finalizado ? "Finalizado (Devolvido)" : "Em Aberto") << "\n"; //verificação de booleano
    cout << "====================\n";
}
/*
  Apenas retorna o valor do atributo finalizado,
  indicando se o emprestimo esta encerrado ou nao.
*/
bool Emprestimo::isFinalizado() const {
    return finalizado;
}
