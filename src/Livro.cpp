#include "Livro.h"

// Implementação dos métodos não virtuais puros

//titulo
void Livro::setTitulo(const std::string& t) {
    titulo = t;
}

std::string Livro::getTitulo() const {
    return titulo;
}
//autor
void Livro::setAutor(const std::string& a) {
    autor = a;
}

std::string Livro::getAutor() const {
    return autor;
}
// Serial Book Number
void Livro::setISBN(const std::string& i) {
    isbn = i;
}

std::string Livro::getISBN() const {
    return isbn;
}
// AnoPublicacao
void Livro::setAnoPublicacao(int ano) {
    anoPublicacao = ano;
}

int Livro::getAnoPublicacao() const {
    return anoPublicacao;
}

// Editora
void Livro::setEditora(const std::string& e) {
    editora = e;
}

std::string Livro::getEditora() const {
    return editora;
}

// ValorDiaria
void Livro::setValorDiaria(int v) {
    valorDiaria = v;
}

int Livro::getValorDiaria() const {
    return valorDiaria;
}


