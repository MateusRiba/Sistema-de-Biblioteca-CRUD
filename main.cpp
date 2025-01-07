#include <iostream>
#include "Livro.h"
#include "LivroFisico.h"
#include "LivroDigital.h"
#include "Usuario.h"
#include "Emprestimo.h"

using namespace std;

// Classe derivada simples para teste
class UsuarioTeste : public Usuario {
public:
    // Construtor
    UsuarioTeste(const std::string& n, const std::string& c, const std::string& e, const std::string& t, const std::string& s)
        : Usuario(n, c, e, t, s) {}

    // Implementação do método virtual puro
    void exibir() const override {
        std::cout << "Nome: " << nome << "\n"
                  << "CPF: " << cpf << "\n"
                  << "Endereço: " << endereco << "\n"
                  << "Telefone: " << telefone << "\n";
    }
};

int main(){
UsuarioTeste usuario("João Silva", "123.456.789-00", "Rua das Flores, 123", "(81) 99999-9999", "1230");
LivroDigital HumanidadeD("Humanidade","Mateus","X4X8-345-YX8", 2024,"Digital.LTD",1, 400, "PNG", 45);
LivroFisico HumanidadeF("Humanidade", "Mateus", "X4X8-345-YX8", 2024, "Caçula.LTD", 2, 1,"Dura", 3);

//Criação de um Emprestimo:
Emprestimo emprestimo1(&usuario, &HumanidadeD, "01/02/2025", "15/02/2025");
std::cout << "=== Teste de Emprestimo (antes de finalizar) ===\n";
emprestimo1.exibirEmprestimo();

emprestimo1.finalizarEmprestimo("10/02/2025"); //Finalização do emprestimo

std::cout << "=== Teste de Emprestimo (depois de finalizar) ===\n";
emprestimo1.exibirEmprestimo();

std::cout << "Exibindo informações do usuário:\n";
usuario.exibir();

//Testando a função exibir
HumanidadeD.exibir();

//Testando os gets e sets manualmente
cout << "Nome: " << HumanidadeF.getTitulo() << endl;
cout << "Autor: " << HumanidadeF.getAutor() << endl;
cout << "Numero de Serie: " << HumanidadeF.getISBN() << endl;
cout << "Ano de Publicacao: " << HumanidadeF.getAnoPublicacao() << endl;
cout << "Editora: " << HumanidadeF.getEditora() << endl;
cout << "Valor da Diaria: " << HumanidadeF.getValorDiaria() << endl;
cout << "Peso em Kg: " << HumanidadeF.getPesoGrama() << endl;
cout << "Tipo de Capa: " << HumanidadeF.getTipoCapa() << endl;
cout << "Quantidade em Estoque: " << HumanidadeF.getQuantidadeEstoque() << endl;

//Mudando com Sets
HumanidadeD.setAutor("Marie Lu");
HumanidadeF.setAutor("Ariano Suassuna");
 usuario.setNome("Maria Oliveira");
usuario.setCpf("987.654.321-00");
usuario.setEndereco("Av. Brasil, 456");
usuario.setTelefone("(11) 98888-8888");

std::cout << "\nInformações atualizadas:\n";
usuario.exibir();

//Novas verificações
cout << "Novo Autor Fisico: " << HumanidadeF.getAutor() <<endl;
cout << "Novo Autor Digital: " << HumanidadeD.getAutor() <<endl;

cout << "Hello World!" << endl;
std::cin.get();
return 0;

};