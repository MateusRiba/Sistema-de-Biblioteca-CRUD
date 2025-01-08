#ifndef LIVROFISICO_H
#define LIVROFISICO_H

#include "Livro.h"
#include <string>
#include <iostream>

class LivroFisico : public Livro {
private:
    // Atributos específicos de um livro digital
    int pesoGrama;
    std::string tipoCapa;
    int quantidadeEstoque;

public:
    /*
      Construtor que chama o construtor base "Livro(const std::string&, ...)"
      para inicializar atributos herdados (titulo, autor, isbn, anoPublicacao) 
      e depois inicializa os atributos específicos de "LivroDigital".
    */

    LivroFisico(const std::string& t, const std::string& a, const std::string& i, int ano, const std::string& e, int valor, int p, const std::string& tc, int q) 
        :Livro(t, a, i, ano, e, valor), pesoGrama(p), tipoCapa(tc), quantidadeEstoque(q) {

        }
    /*
      Método virtual puro (exibirDetalhes) que estava na classe base "Livro".
      Aqui nós o implementamos, tornando "LivroDigital" uma classe concreta.
    */
    void exibir() const override;

    //Metodo de incremento e decremento de estoque
    void diminuirEstoque();
    void aumentarEstoque();

    // Métodos específicos (getters e setters)
    void setPesoGrama(int p);
    int getPesoGrama() const;

    void setTipoCapa(const std::string& tc);
    std::string getTipoCapa() const;

    void setQuantidadeEstoque(int q);
    int getQuantidadeEstoque() const;
};

#endif


