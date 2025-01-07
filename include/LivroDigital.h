#ifndef LIVRODIGITAL_H
#define LIVRODIGITAL_H

#include "Livro.h"
#include <string>
#include <iostream>

class LivroDigital : public Livro {
private:
    // Atributos específicos de um livro digital
    int tamanhoArquivoKB;
    std::string formatoArquivo;
    int licensaDigital;

public:
    /*
      Construtor que chama o construtor base "Livro(const std::string&, ...)"
      para inicializar atributos herdados (titulo, autor, isbn, anoPublicacao) 
      e depois inicializa os atributos específicos de "LivroDigital".
    */

    LivroDigital(const std::string& t, const std::string& a, const std::string& i, int ano, const std::string& e, int valor, int ta, const std::string& f, int l) 
        :Livro(t, a, i, ano, e, valor), tamanhoArquivoKB(ta), formatoArquivo(f), licensaDigital(l) {

        }
    /*
      Método virtual puro (exibirDetalhes) que estava na classe base "Livro".
      Aqui nós o implementamos, tornando "LivroDigital" uma classe concreta.
    */
    void exibir() const override;

    // Métodos específicos (getters e setters)
    void setTamanhoArquivoKB(int p);
    int getTamanhoArquivoKB() const;

    void setFormatoArquivo(const std::string& tc);
    std::string getFormatoArquivo() const;

    void setLicensaDigital(int q);
    int getLicensaDigital() const;
};

#endif


