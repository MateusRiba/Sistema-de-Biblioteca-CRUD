#ifndef LEITORCOMUM_H
#define LEITORCOMUM_H

#include "Usuario.h"
#include <string>
#include <iostream>

class LeitorComum : public Usuario {
private:
    // Atributos específicos de um LeitorComum (Nada especifico)
public:
    /*
      Construtor que chama o construtor base "Usuario(const std::string&, ...)"
      para inicializar atributos herdados
      e depois inicializa os atributos específicos de "LeitorComum".
    */

    LeitorComum(const std::string& n, const std::string& c, const std::string& e, const std::string& t, const std::string& s) 
        :Usuario(n, c, e, t, s) {

        }
    /*
      Método virtual puro (exibirDetalhes) que estava na classe base "Usuario".
      Aqui nós o implementamos, tornando "LeitorComum" uma classe concreta.
    */
    void exibir() const override;

    // Métodos específicos (Nesse caso, sem getters e setters pois não temos atributos novos)

    void buscarLivros();
    void alugarLivro();
    void devolverLivro();

};


#endif