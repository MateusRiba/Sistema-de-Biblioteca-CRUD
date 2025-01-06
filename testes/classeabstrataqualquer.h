#ifndef classequalquer_H
#define classequalquer_H

#include <string>
#include<iostream>

/*
  Classe abstrata: 
  - Possui pelo menos um método virtual puro (= 0).
  - Não pode ser instanciada diretamente.
  - Serve como "contrato" ou interface básica para as classes derivadas.
*/
class classequalquer {
protected:
    // Atributo protegido (SOMENTE as classes derivadas podem acessar).
    std::string titulo;
    std::string autor;
    std::string isbn; //standard book number
    int anoPublicação;
    std::string editora;
    int valorDiaria;


public:
    // Construtor padrão
    classequalquer() = default;
    // Construtor Especifico

    // Destrutor virtual 
    virtual ~classequalquer() = default;

    /*
      Método virtual puro: 
      - Torna esta classe abstrata.
      - As classes derivadas DEVEM implementar esse método.
    */
    virtual void exibir() = 0;

    /*
      Métodos "comuns" (não são virtuais puros).
      - Podem ser sobrescritos (override) nas derivadas, 
        se forem declarados como virtual.
      - Caso contrário, as derivadas herdam esses métodos como estão.
    */
    void setSomeAttribute(const std::string& value);
    std::string getSomeAttribute() const;
};

#endif 