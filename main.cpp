#include <iostream>
#include "LivroFisico.h"
#include "LivroDigital.h"
#include "LeitorComum.h"
#include "Administrador.h"
#include "Sistema.h"
#include "Menu.h"

using namespace std;

extern Sistema sis;
extern Usuario* admin;


int main(){

    // Chama a função de gerenciamento de usuários
    gerenciarUsuarios();
    
    // Opcional: Após o teste, você pode listar os usuários para verificar as alterações
    std::cout << "\n=== Lista de Usuários após o Gerenciamento ===\n";
    sis.listarUsuarios();
    
    return 0;
}