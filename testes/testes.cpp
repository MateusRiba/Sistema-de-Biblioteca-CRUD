#include <iostream>
#include "Livro.h"


using namespace std;

// Classe derivada provisoria
class LivroFiccao : public Livro {
public:
    LivroFiccao(const std::string& t, const std::string& a, const std::string& i, int ano, const std::string& e, int valor)
        : Livro(t, a, i, ano, e, valor) {}

    void exibir() const override {
        std::cout << "Título: " << titulo << "\n"
                  << "Autor: " << autor << "\n"
                  << "ISBN: " << isbn << "\n"
                  << "Ano de Publicação: " << anoPublicacao << "\n"
                  << "Editora: " << editora << "\n"
                  << "Valor Diário: " << valorDiaria << "\n";
    }
};

int main(){

// Criar um objeto Livro usando o construtor parametrizado
    LivroFiccao meuLivro("O Senhor dos Anéis", "J.R.R. Tolkien", "978-3-16-148410-0", 1954, "HarperCollins", 10);

    // Exibir os dados do livro usando os getters
    std::cout << "Título: " << meuLivro.getTitulo() << "\n";
    std::cout << "Autor: " << meuLivro.getAutor() << "\n";
    std::cout << "ISBN: " << meuLivro.getISBN() << "\n";
    std::cout << "Ano de Publicação: " << meuLivro.getAnoPublicacao() << "\n";
    std::cout << "Editora: " << meuLivro.getEditora() << "\n";
    std::cout << "Valor Diário: " << meuLivro.getValorDiaria() << "\n";

    // Modificar alguns valores usando os setters
    meuLivro.setTitulo("O Hobbit");
    meuLivro.setValorDiaria(15);

    // Exibir os dados novamente
    std::cout << "Título Atualizado: " << meuLivro.getTitulo() << "\n";
    std::cout << "Valor Diário Atualizado: " << meuLivro.getValorDiaria() << "\n";


cout << "Hello World!" << endl;
std::cin.get();
return 0;

};

#include <iostream>
#include "Livro.h"
#include "LivroFisico.h"
#include "LivroDigital.h"

using namespace std;

int main(){

LivroDigital HumanidadeD("Humanidade","Mateus","X4X8-345-YX8", 2024,"Digital.LTD",1, 400, "PNG", 45);
LivroFisico HumanidadeF("Humanidade", "Mateus", "X4X8-345-YX8", 2024, "Caçula.LTD", 2, 1,"Dura", 3);

cout << "Nome: " << HumanidadeF.getTitulo() << endl;
cout << "Autor: " << HumanidadeF.getAutor() << endl;
cout << "Numero de Serie: " << HumanidadeF.getISBN() << endl;
cout << "Ano de Publicacao: " << HumanidadeF.getAnoPublicacao() << endl;
cout << "Editora: " << HumanidadeF.getEditora() << endl;
cout << "Valor da Diaria: " << HumanidadeF.getValorDiaria() << endl;
cout << "Peso em Kg: " << HumanidadeF.getPesoGrama() << endl;
cout << "Tipo de Capa: " << HumanidadeF.getTipoCapa() << endl;
cout << "Quantidade em Estoque: " << HumanidadeF.getQuantidadeEstoque() << endl;


HumanidadeD.setAutor("Marie Lu");
HumanidadeF.setAutor("Ariano Suassuna");

cout << "Novo Autor Fisico: " << HumanidadeF.getAutor() <<endl;
cout << "Novo Autor Digital: " << HumanidadeD.getAutor() <<endl;

cout << "Hello World!" << endl;
std::cin.get();
return 0;

};