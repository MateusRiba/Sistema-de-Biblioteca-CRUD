#ifndef LIVRO_H
#define LIVRO_H

#include <string>
#include <iostream>

//  Classe abstrata: 

class Livro {
protected:
    // Atributo protegido (SOMENTE as classes derivadas podem acessar).
    std::string titulo;
    std::string autor;
    std::string isbn; //standard book number
    int anoPublicacao;
    std::string editora;
    int valorDiaria;

public:
    // Construtor (opcional) - se precisar inicializar algo básico.
    Livro() = default;
    // Construtor Especifico (para já iniciar o livro com os valores definidos!)
    Livro(const std::string& t, const std::string& a, const std::string& i, int ano, const std::string& e, int valor) 
        :titulo(t),autor(a),isbn(i),anoPublicacao(ano),editora(e),valorDiaria(valor) {

        }
    // Destrutor virtual é importante para garantir a chamada correta 
    virtual ~Livro() = default;

    
    //Método virtual puro (garante que é uma classe abstrata, TODAS as classes derivadas devem possuir um): 
    virtual void exibir() const = 0;

    
    //Métodos "comuns" (não são virtuais puros) Todos são Declarados aqui, mas não são definidos, são definidos apenas no ".Cpp".
    void setTitulo(const std::string& t);
    std::string getTitulo() const;

    void setAutor(const std::string& a);
    std::string getAutor() const;

    void setISBN(const std::string& i);
    std::string getISBN() const;

    void setAnoPublicacao(int ano);
    int getAnoPublicacao() const;

    void setEditora(const std::string& e);
    std::string getEditora() const;

    void setValorDiaria(int v);
    int getValorDiaria() const;
};

#endif 