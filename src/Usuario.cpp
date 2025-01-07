#include "Usuario.h"

// Implementação dos métodos não virtuais putos

// Nome
void Usuario::setNome(const std::string& n) {
    nome = n;
}

std::string Usuario::getNome() const {
    return nome;
}

// CPF
void Usuario::setCpf(const std::string& c) {
    cpf = c;
}

std::string Usuario::getCpf() const {
    return cpf;
}

// Endereço
void Usuario::setEndereco(const std::string& e) {
    endereco = e;
}

std::string Usuario::getEndereco() const {
    return endereco;
}

// Telefone
void Usuario::setTelefone(const std::string& t) {
    telefone = t;
}

std::string Usuario::getTelefone() const {
    return telefone;
}
