#include "Menu.h"            
#include "LeitorComum.h"     // Precisamos dessa classe para poder dynamic_cast
#include "Administrador.h"   // Precisamos dessa classe para usar dynamic_cast
#include <iostream>

// Declaração externa das variáveis globais definidas em Menu.cpp
extern Sistema sis;
extern Usuario* admin;

int main() {
    while(true) {
        // exibirMenuLogin() retorna ResultadoLogin { usuario, isADM }
        ResultadoLogin resultado = exibirMenuLogin();
        
        // Se o usuário for nulo (CPF ou senha inválidos e o usuário optou por sair)
        // ou se o usuário optou por sair do sistema no menu
        if (resultado.usuario == nullptr) {
            std::cout << "Encerrando o programa...\n";
            break;
        }

        // Checar se é administrador
        if (resultado.isADM) {
            // Converte ponteiro base para ponteiro Administrador*
            Administrador* adminPtr = dynamic_cast<Administrador*>(resultado.usuario);
            if (adminPtr) {
                exibirInterfaceAdministrador(sis, adminPtr);
            } else {
                std::cout << "Falha ao converter usuario para Administrador.\n";
            }
        } else {
            // Caso LeitorComum
            LeitorComum* leitorPtr = dynamic_cast<LeitorComum*>(resultado.usuario);
            if (leitorPtr) {
                exibirInterfaceLeitorComum(sis, leitorPtr);
            } else {
                std::cout << "Falha ao converter usuario para LeitorComum.\n";
            }
        }
    }

    // Ao sair do while, o sistema encerra
    std::cout << "Sistema finalizado.\n";
    return 0;
}
