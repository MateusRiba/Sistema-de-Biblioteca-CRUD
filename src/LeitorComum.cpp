#include "LeitorComum.h"

#include <string>
#include <iostream>

void LeitorComum::exibir() const {
    std::cout << "Nome: " << nome << "\n"
              << "CPF: " << cpf << "\n"
              << "Endereço: " << endereco << "\n"
              << "Telefone: " << telefone << "\n";
}

void LeitorComum::buscarLivros() {
    std::cout << "Buscando livros...\n";
}

void LeitorComum::alugarLivro() {
    std::cout << "Alugando livro...\n";
}

void LeitorComum::devolverLivro() {
    std::cout << "Devolvendo livro...\n";
}
