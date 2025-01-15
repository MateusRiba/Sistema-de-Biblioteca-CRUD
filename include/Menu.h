#ifndef MENU_H
#define MENU_H

#include "Sistema.h"
#include "Usuario.h"
#include "LivroFisico.h"
#include "LivroDigital.h"
#include "LeitorComum.h"
#include "Administrador.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

// Definição de uma estrutura para retornar o usuário e o status de administrador
struct ResultadoLogin {
    Usuario* usuario;
    bool isADM;
};

// Declaração das funções
ResultadoLogin exibirMenuLogin();
void gerenciarUsuarios();
void exibirInterfaceAdministrador(Sistema& sis, Administrador* admin);
void exibirInterfaceLeitorComum();

extern Sistema sis;
extern Usuario* admin;

#endif 