#include "sessao.h"

// Inicialização das variáveis estáticas
QString Sessao::nomeUsuario = "";
QString Sessao::cpfUsuario = "";

// Implementação dos métodos públicos
QString Sessao::getNomeUsuario() {
    return nomeUsuario;
}

QString Sessao::getCpfUsuario() {
    return cpfUsuario;
}

void Sessao::setNomeUsuario(const QString &nome) {
    nomeUsuario = nome;
}

void Sessao::setCpfUsuario(const QString &cpf) {
    cpfUsuario = cpf;
}

