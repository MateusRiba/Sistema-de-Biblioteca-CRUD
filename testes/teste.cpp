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