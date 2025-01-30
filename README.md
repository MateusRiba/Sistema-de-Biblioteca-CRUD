# Sistema-de-Informa-o-Biblioteca
Este projeto consiste em um Sistema de Informação Bibliotecário em C++, no estilo CRUD (Create, Read, Update, Delete). Ele possibilita a gestão de usuários (Leitor Comum e Administrador), cadastro e gerenciamento de livros (tanto físicos quanto digitais) e controle de empréstimos.

<a id="visao-geral"></a>

1. Visão Geral do Projeto
O objetivo é fornecer uma aplicação de linha de comando que:

Gere usuários e gerencie suas informações,
Cadastre e manipule livros (físicos ou digitais),
Controle empréstimos (criação, devolução e listagem),
Ofereça menus distintos para Administrador e Leitor Comum.
Tecnologias e Conceitos Utilizados
Linguagem C++
Programação Orientada a Objetos (POO)
Polimorfismo e Herança
Vetores dinâmicos (principalmente std::vector)
Estrutura CRUD (Create, Read, Update, Delete)
<a id="estrutura-de-pastas"></a>

2. Funcionalidades Principais
Cadastro de Usuários

Administrador: tem poderes para gerenciar outros usuários, livros e empréstimos.
Leitor Comum: pode alugar livros, devolver e gerenciar seus empréstimos.
Gerenciamento de Livros

Livro Físico: possui atributos como peso, tipo de capa e quantidade em estoque.
Livro Digital: possui atributos como tamanho do arquivo, licença digital e formato.
Controle de Empréstimos

Criar empréstimos (verifica estoque, decrementa se for livro físico).
Encerrar empréstimos (devolução do livro).
Atualizar datas e custos de empréstimo.
Listagem de empréstimos (ativos e históricos).
Menus Diferenciados

Administrador: Menu de gerenciamento de usuários, livros e empréstimos.
Leitor Comum: Menu de visualização de livros, pesquisa, criação e encerramento de empréstimos.

<a id="como-executar"></a>

3. Fluxo de Execução
main.cpp

Chama exibirMenuLogin().
Se o usuário logar como Administrador, chama exibirInterfaceAdministrador().
Se logar como Leitor Comum, chama exibirInterfaceLeitorComum().
exibirMenuLogin()

1: Possuo Cadastro → Autentica CPF e senha.
2: Cadastrar-se → Cria um novo Leitor Comum e retorna ao menu.
3: Sair → Encerra o sistema.
Interface de Administrador

Menu para gerenciar usuários, livros, empréstimos.
Pode criar/remover/editar usuários, livros e empréstimos.
Interface de Leitor Comum

Visualiza livros, pesquisa livro para alugar, gerencia seus empréstimos.
Quando escolhe “Visualizar Livros”, chama visualizarLivros().
Quando escolhe “Alugar Livro”, chama pesquisarLivro(leitor).
Gerencia aluguéis em gerenciarAluguel(leitor).
<a id="detalhes-de-implementacao"></a>

4. Detalhes de Implementação
<a id="classe-sistema"></a>

4.1. Classe Sistema
É responsável por manter:

Vetores de usuários e livros (físicos e digitais).
Lista de empréstimos (std::vector<Emprestimo>).
Métodos de busca (por CPF, ISBN etc.).
Métodos CRUD (adicionar/remover/atualizar) para usuários, livros e empréstimos.
realizarEmprestimo(), encerrarEmprestimoCpfIsbn(), etc.
<a id="classes-livro-livrofisico-livrodigital"></a>

4.2. Classes Livro, LivroFisico, LivroDigital
Livro é abstrata, com atributos básicos (título, autor, ISBN, etc.) e exibir() virtual.
LivroFisico deriva de Livro, tem peso, tipo de capa, quantidade em estoque.
LivroDigital deriva de Livro, tem tamanho de arquivo, licença digital, formato.
<a id="classes-usuario-leitorcomum-administrador"></a>

4.3. Classes Usuario, LeitorComum, Administrador
Usuario é abstrata, com exibir() virtual, CPF, nome, endereço, telefone, senha.
LeitorComum: pode manter um vetor de empréstimos do próprio leitor, e métodos para listar/encerrar.
Administrador: pode chamar métodos do Sistema para adicionar/remover/atualizar usuários, livros e empréstimos.
<a id="classe-emprestimo"></a>

4.4. Classe Emprestimo
Armazena:

Ponteiros para Usuario* e Livro*.
Data de empréstimo, data de devolução, custo e status (finalizado ou não).
Métodos como finalizarEmprestimo(...), exibirEmprestimo().
<a id="observacoes-e-proximos-passos"></a>

5. Observações e Próximos Passos
Validação e Tratamento de Erros

Persistência de Dados

