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
  OBS: (IMPORTANTE) Como Usuario e Livro são abstratas, de fato "this->usuario" pode
    apontar para um LeitorComum ou Administrador; "this->livro" pode ser
    um LivroFisico ou LivroDigital.
*/
void Emprestimo::exibirEmprestimo() const {
    cout << "=== Emprestimo ===\n";
    
    cout << "Usuario que alugou o Livro:" << endl;
    cout << usuario->getNome() << endl; //Assim se chama o metodo de outra Classe
    cout << "Livro alugado:" << endl;
    cout << livro->getTitulo() << endl;

    cout << "Data de Emprestimo: " << dataEmprestimo << "\n";
    cout << "Data de Devolucao (prevista ou real): " << dataDevolucao << "\n";
    cout << "Status: " << (finalizado ? "Finalizado (Devolvido)" : "Em Aberto") << "\n"; //verificação de booleano
    cout << "====================\n";
}

//Usuario
Usuario* Emprestimo::getUsuario() const {
    return usuario;
}

void Emprestimo::setUsuario(Usuario* u) {
    usuario = u;
}

//Livro
Livro* Emprestimo::getLivro() const {
    return livro;
}

void Emprestimo::setLivro(Livro* l) {
    livro = l;
}

//dataEmprestimo
std::string Emprestimo::getDataEmprestimo() const {
    return dataEmprestimo;
}

void Emprestimo::setDataEmprestimo(const std::string& dataEmp) {
    dataEmprestimo = dataEmp;
}

//dataDevolucao
std::string Emprestimo::getDataDevolucao() const {
    return dataDevolucao;
}

void Emprestimo::setDataDevolucao(const std::string& dataDev) {
    dataDevolucao = dataDev;
}

// Getter e Setter para finalizado
bool Emprestimo::isFinalizado() const {
    return finalizado;
}

void Emprestimo::setFinalizado(bool status) {
    finalizado = status;
}
