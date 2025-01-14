// main.cpp
#include <iostream>
#include "LivroFisico.h"
#include "LivroDigital.h"
#include "LeitorComum.h"
#include "Administrador.h"
#include "Sistema.h"
#include "Menu.h"

using namespace std;

int main(){

    exibirMenuLogin();

    int opcao;

    do{
        exibirMenuPrincipal();
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch(opcao){
            case 1:
                gerenciarLivros();
                break;
            case 2:
                gerenciarUsuarios();
                break;
            case 3:
                cout << "Saindo do Sistema...\n";
                break;
            default:
                cout << "Opção inválida! Tente novamente.\n";
                break;
        }
    } while (opcao != 3);
   

    return 0;
}
