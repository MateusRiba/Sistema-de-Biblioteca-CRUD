#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <iostream>

//classe abstrata

class Usuario {
protected:
    // Atributo protegido (SOMENTE as classes derivadas podem acessar).
    std::string nome;
    std::string cpf;
    std::string endereco; 
    std::string telefone;

public:
    // Construtor (opcional) - se precisar inicializar algo básico.
    Usuario() = default;
    // Construtor Especifico (para já iniciar o Usuario com os valores definidos!)
    Usuario(const std::string& n, const std::string& c, const std::string& e, const std::string& t) 
        :nome(n),cpf(c),endereco(e), telefone(t) {

        }
    // Destrutor virtual é importante para garantir a chamada correta 
    virtual ~Usuario() = default;

    
    //Método virtual puro (garante que é uma classe abstrata, TODAS as classes derivadas devem possuir um): 
    virtual void exibir() const = 0;

    
    //Métodos "comuns" (não são virtuais puros) Todos são Declarados aqui, mas não são definidos, são definidos apenas no ".Cpp".
    void setNome(const std::string& n);
    std::string getNome() const;

    void setCpf(const std::string& c);
    std::string getCpf() const;

    void setEndereco(const std::string& e);
    std::string getEndereco() const;

    void setTelefone(const std::string& t);
    std::string getTelefone() const;

};


#endif