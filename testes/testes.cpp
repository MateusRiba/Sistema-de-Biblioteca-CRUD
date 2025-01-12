// main.cpp
#include <iostream>
#include "LivroFisico.h"
#include "LivroDigital.h"
#include "LeitorComum.h"
#include "Administrador.h"
#include "Sistema.h"

using namespace std;

int main(){
    // Cria uma instância do Sistema
    Sistema sis;

    // Cria um Administrador e associa ao Sistema
    Administrador* admin = new Administrador("Carlos Admin", "000.111.222-33", 
                                           "Rua Admin, 999", "(81)90000-0000", 
                                           "senhaAdmin", &sis);
    
    // Exibe informações do Administrador
    admin->exibir();
    
    // ========= Gerenciamento de Usuários =========
    
    // Cadastrar novos usuários via Administrador
    Usuario* u1 = new LeitorComum("Joao Silva", "111.222.333-44", "Rua A, 123", 
                                  "(81)99999-9999", "senhaA");
    Usuario* u2 = new LeitorComum("Maria Souza", "555.666.777-88", "Av. B, 456", 
                                  "(81)98888-8888", "senhaB");
    
    admin->cadastrarUsuario(u1);
    admin->cadastrarUsuario(u2);
    
    // Listar usuários após cadastro
    cout << "\n--- Lista de Usuários após cadastro ---\n";
    sis.listarUsuarios();
    
    // ========= Gerenciamento de Livros =========
    
    // Cadastrar novos livros via Administrador
    Livro* l1 = new LivroFisico("C++ Basico", "Bjarne Stroustrup", "ABC-123", 
                                2020, "EditoraXYZ", 1.5, 500, "Capa Dura", 10);
    Livro* l2 = new LivroDigital("O Mundo Digital", "Mateus", "XYZ-789", 
                                 2023, "Digital.LTD", 2.0, 320, "JPEG", 32);
    
    admin->cadastrarLivro(l1);
    admin->cadastrarLivro(l2);
    
    // Listar livros após cadastro
    cout << "\n--- Lista de Livros após cadastro ---\n";
    sis.listarLivros();
    
    // ========= Atualização de Usuário =========
    
    // Editar informações do usuário com CPF "555.666.777-88"
    cout << "\n--- Atualizando Usuário (CPF: 555.666.777-88) ---\n";
    admin->editarUsuario("555.666.777-88", "Maria Admin", "Av. Central, 1000", 
                         "(81)97777-7777", "novaSenhaAdmin");
    
    // Listar usuários após atualização
    cout << "\n--- Lista de Usuários após atualização ---\n";
    sis.listarUsuarios();
    
    // ========= Atualização de Livro =========
    
    // Editar informações do livro com ISBN "ABC-123"
    cout << "\n--- Atualizando Livro (ISBN: ABC-123) ---\n";
    admin->editarLivro("ABC-123", "C++ Intermediário", "Bjarne Stroustrup", "NovaEditoraXYZ", 
                       2.0, 550, "Capa Semi-Dura", 15, 
                       -1, "", -1); // -1 e strings vazias indicam que não serão alterados
    
    // Listar livros após atualização
    cout << "\n--- Lista de Livros após atualização ---\n";
    sis.listarLivros();
    
    // ========= Gerenciamento de Empréstimos =========
    
    // Criar empréstimos via Sistema (não via Administrador)
    cout << "\n--- Criando Empréstimos ---\n";
    sis.realizarEmprestimo(u1, l1, "01/02/2025", "10/02/2025");
    sis.realizarEmprestimo(u2, l2, "02/02/2025", "12/02/2025");
    
    // Listar empréstimos após criação
    cout << "\n--- Lista de Empréstimos após criação ---\n";
    sis.listarEmprestimos();
    
    // Editar um empréstimo via Administrador (mudar datas e custo)
    cout << "\n--- Editando Empréstimo (CPF: 111.222.333-44, ISBN: ABC-123) ---\n";
    admin->editarEmprestimo("111.222.333-44", "ABC-123", "03/02/2025", "15/02/2025", false, 75);
    
    // Listar empréstimos após edição
    cout << "\n--- Lista de Empréstimos após edição ---\n";
    sis.listarEmprestimos();
    
    // Encerrar um empréstimo via Administrador
    cout << "\n--- Encerrando Empréstimo (CPF: 111.222.333-44, ISBN: ABC-123) ---\n";
    admin->encerrarEmprestimo("111.222.333-44", "ABC-123", "05/02/2025");
    
    // Listar empréstimos após encerramento
    cout << "\n--- Lista de Empréstimos após encerramento ---\n";
    sis.listarEmprestimos();
    
    // ========= Remoção de Usuário e Livro =========
    
    // Remover usuário por nome via Administrador
    cout << "\n--- Removendo Usuário por Nome: Maria Admin ---\n";
    admin->removerUsuarioPorNome("Maria Admin");
    
    // Listar usuários após remoção
    cout << "\n--- Lista de Usuários após remoção ---\n";
    sis.listarUsuarios();
    
    // Remover livro por título via Administrador
    cout << "\n--- Removendo Livro por Título: O Mundo Digital ---\n";
    admin->removerLivroPorTitulo("O Mundo Digital");
    
    // Listar livros após remoção
    cout << "\n--- Lista de Livros após remoção ---\n";
    sis.listarLivros();
    
    // ========= Limpeza e Encerramento =========
    
    // Exibir informações atualizadas de um objeto específico (opcional)
    cout << "\n--- Informações Atualizadas ---\n";
    admin->exibir(); // Exibe dados do administrador
    
    // Finalização automática do Sistema (chamada do destrutor)
    cout << "\n--- FIM DOS TESTES DO SISTEMA ---\n";
    
    // Limpar memória alocada para Administrador
    delete admin;
    
    // Pausa para visualização (opcional)
    cin.get();
    return 0;
}
