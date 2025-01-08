#include <iostream>
#include "Livro.h"
#include "LivroFisico.h"
#include "LivroDigital.h"
#include "Usuario.h"
#include "LeitorComum.h"
#include "Emprestimo.h"
#include "Sistema.h"

using namespace std;

int main(){

//define o Sistema
Sistema sis;

// Cria usuarios (no seu caso, poderia ser new Administrador, new LeitorComum, etc.)
Usuario* u1 = new LeitorComum("Joao Silva", "111.222.333-44", "Rua A, 123", "(81)99999-9999", "senhaA");
Usuario* u2 = new LeitorComum("Maria Souza", "555.666.777-88", "Av. B, 456", "(81)98888-8888", "senhaB");

LeitorComum usuario("João Silva", "123.456.789-00", "Rua das Flores, 123", "(81) 99999-9999", "1230");
LivroDigital HumanidadeD("Humanidade","Mateus","X4X8-345-YX8", 2024,"Digital.LTD",1, 400, "PNG", 45);
LivroFisico HumanidadeF("Humanidade", "Mateus", "X4X8-345-YX8", 2024, "Caçula.LTD", 2, 1,"Dura", 3);

//Adiciona usuarios
sis.adicionarUsuario(u1);
sis.adicionarUsuario(u2);
/*sis.adicionarUsuario(usuario); --> Isso não é possivel devido a uma incompatibilidade de tipos
alem da natureza do destrutor, Se usuario fosse um objeto na stack, não poderia ser liberado com delete
Em geral, sistemas de gerenciamento de alocação, o normal seria criar com "new"*/

//Cria Livros
Livro* l1 = new LivroFisico("C++ Basico", "Bjarne", "ABC-123", 2020, "EditoraXYZ", 1, 5,"Dura", 3);
Livro* l2 = new LivroDigital("O Mundo Digital", "Mateus", "XYZ-789", 2023, "Digital.LTD", 2, 320,"JPEG",32);

sis.adicionarLivro(l1);
sis.adicionarLivro(l2);
//sis.adicionarLivro(HumanidadeF); --> Isso não é possivel devido a uma incompatibilidade de tipos, alem da natureza do destrutor

// Listar usuarios e livros
std::cout << "\n--- LISTANDO Usuarios e Livros apos adicionar ---\n";
sis.listarUsuarios();
sis.listarLivros();

// Testar busca por CPF
std::cout << "\n--- TESTE de buscarUsuarioPorCPF(\"555.666.777-88\") ---\n";
Usuario* buscado = sis.buscarUsuarioPorCPF("555.666.777-88");
if (buscado) {
    std::cout << "Usuario encontrado: " << buscado->getNome() << "\n";
} else {
    std::cout << "Usuario nao encontrado!\n";
}

// Testar busca por ISBN
std::cout << "\n--- TESTE de buscarLivroPorISBN(\"ABC-123\") ---\n";
Livro* livroBuscado = sis.buscarLivroPorISBN("ABC-123");
if (livroBuscado) {
    std::cout << "Livro encontrado: " << livroBuscado->getTitulo() << "\n";
} else {
    std::cout << "Livro nao encontrado!\n";
}

// Criar Emprestimos
std::cout << "\n--- CRIANDO Emprestimos ---\n";
sis.realizarEmprestimo(u1, l1, "01/02/2025", "10/02/2025");
sis.realizarEmprestimo(u2, l2, "02/02/2025", "12/02/2025");

// Listar emprestimos
sis.listarEmprestimos();

// Encerrar primeiro emprestimo (pelo CPF e ISBN)
std::cout << "\n--- ENCERRANDO Emprestimo do Joao Silva (CPF \"111.222.333-44\") e ISBN \"ABC-123\" ---\n";
sis.encerrarEmprestimoCpfIsbn("111.222.333-44", "ABC-123", "05/02/2025");
sis.listarEmprestimos();

// Testar remocao de usuario por nome
std::cout << "\n--- REMOVENDO Usuario por Nome: \"Maria Souza\" ---\n";
bool removeu = sis.removerUsuarioPorNome("Maria Souza");
if (removeu) {
    std::cout << "Usuario removido com sucesso!\n";
} else {
    std::cout << "Falha ao remover usuario!\n";
}
sis.listarUsuarios();

// Testar remocao de livro por titulo
// Observacao: cuidado que no seu Sistema::removerLivroPorTitulo voce está comparando getISBN() com o titulo
// Então vou usar a string exata que l2->getTitulo() retorna: "O Mundo Digital"
std::cout << "\n--- REMOVENDO Livro por Titulo: \"O Mundo Digital\" ---\n";
bool removeuLivro = sis.removerLivroPorTitulo("O Mundo Digital");
if (removeuLivro) {
    std::cout << "Livro removido com sucesso!\n";
} else {
    std::cout << "Falha ao remover livro!\n";
}
sis.listarLivros();

// Final: Ao sair do main(), o destrutor ~Sistema() sera chamado, que por sua vez
//        chama delete para cada Usuario* e Livro* ainda presentes no vector.

std::cout << "\n--- FIM DOS TESTES DO SISTEMA ---\n";

//Criação de um Emprestimo:
Emprestimo emprestimo1(&usuario, &HumanidadeD, "01/02/2025", "15/02/2025");
std::cout << "=== Teste de Emprestimo (antes de finalizar) ===\n";
emprestimo1.exibirEmprestimo();

emprestimo1.finalizarEmprestimo("10/02/2025"); //Finalização do emprestimo

std::cout << "=== Teste de Emprestimo (depois de finalizar) ===\n";
emprestimo1.exibirEmprestimo();

std::cout << "Exibindo informações do usuário:\n";
usuario.exibir();

//Testando a função exibir
HumanidadeD.exibir();

//Testando os gets e sets manualmente
cout << "Nome: " << HumanidadeF.getTitulo() << endl;
cout << "Autor: " << HumanidadeF.getAutor() << endl;
cout << "Numero de Serie: " << HumanidadeF.getISBN() << endl;
cout << "Ano de Publicacao: " << HumanidadeF.getAnoPublicacao() << endl;
cout << "Editora: " << HumanidadeF.getEditora() << endl;
cout << "Valor da Diaria: " << HumanidadeF.getValorDiaria() << endl;
cout << "Peso em Kg: " << HumanidadeF.getPesoGrama() << endl;
cout << "Tipo de Capa: " << HumanidadeF.getTipoCapa() << endl;
cout << "Quantidade em Estoque: " << HumanidadeF.getQuantidadeEstoque() << endl;

//Mudando com Sets
HumanidadeD.setAutor("Marie Lu");
HumanidadeF.setAutor("Ariano Suassuna");
 usuario.setNome("Maria Oliveira");
usuario.setCpf("987.654.321-00");
usuario.setEndereco("Av. Brasil, 456");
usuario.setTelefone("(11) 98888-8888");

std::cout << "\nInformações atualizadas:\n";
usuario.exibir();

//Novas verificações
cout << "Novo Autor Fisico: " << HumanidadeF.getAutor() <<endl;
cout << "Novo Autor Digital: " << HumanidadeD.getAutor() <<endl;

cout << "Hello World!" << endl;
std::cin.get();
return 0;

};