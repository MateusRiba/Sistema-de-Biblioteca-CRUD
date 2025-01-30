#ifndef SESSION_H
#define SESSION_H

#include <QString>

class Sessao {
public:
    // Métodos para acessar os dados do usuário
    static QString getNomeUsuario();
    static QString getCpfUsuario();

    // Métodos para definir os dados do usuário
    static void setNomeUsuario(const QString &nome);
    static void setCpfUsuario(const QString &cpf);

private:
    // Variáveis privadas para armazenar os dados do usuário
    static QString nomeUsuario;
    static QString cpfUsuario;
};

#endif // SESSION_H
