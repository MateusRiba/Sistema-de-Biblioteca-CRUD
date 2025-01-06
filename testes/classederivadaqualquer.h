#ifndef LIVRO_DIGITAL_HPP
#define LIVRO_DIGITAL_HPP

#include "abstrata.hpp"
#include <string>

/*
  Classe derivada: "LivroDigital"
  - Herda da classe base abstrata "Livro".
  - Deve implementar todos os métodos virtuais puros da base 
    (ex.: exibirDetalhes()) para não ser também abstrata.
*/
class LivroDigital : public Livro {
private:
    // Atributos específicos de um livro digital
    double tamanhoArquivo;         // Em MB, por exemplo
    std::string formatoArquivo;    // PDF, EPUB, MOBI...
    bool temDRM;                   // Indica se há proteção DRM

public:
    /*
      Construtor que chama o construtor base "Livro(const std::string&, ...)"
      para inicializar atributos herdados (titulo, autor, isbn, anoPublicacao) 
      e depois inicializa os atributos específicos de "LivroDigital".
    */
    LivroDigital(const std::string& t, 
                 const std::string& a, 
                 const std::string& i, 
                 int anoPub,
                 double tamanhoMB, 
                 const std::string& formato, 
                 bool drm);

    /*
      Método virtual puro (exibirDetalhes) que estava na classe base "Livro".
      Aqui nós o implementamos, tornando "LivroDigital" uma classe concreta 
      (instanciável).
    */
    void exibirDetalhes() const override;

    // Métodos específicos de LivroDigital (getters e setters)
    void setTamanhoArquivo(double tamanhoMB);
    double getTamanhoArquivo() const;

    void setFormatoArquivo(const std::string& formato);
    std::string getFormatoArquivo() const;

    void setTemDRM(bool drm);
    bool getTemDRM() const;
};

#endif // LIVRO_DIGITAL_HPP