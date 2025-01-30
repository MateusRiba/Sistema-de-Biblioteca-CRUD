# Projeto-Edoo

## Descrição
O Projeto-Edoo é um Sistema de Informação Bibliotecário desenvolvido em C++ no estilo CRUD (Create, Read, Update, Delete). Ele possibilita a gestão de usuários (Leitor Comum e Administrador), cadastro e gerenciamento de livros (tanto físicos quanto digitais) e controle de empréstimos.

---

## Visão Geral do Projeto

O objetivo é fornecer uma aplicação que:

- Gere usuários e gerencie suas informações.
- Cadastre e manipule livros (físicos ou digitais).
- Controle empréstimos (criação, devolução e listagem).
- Ofereça menus distintos para Administrador e Leitor Comum.

### Tecnologias e Conceitos Utilizados
- Linguagem C++
- Programação Orientada a Objetos (POO)
- Polimorfismo e Herança
- Vetores dinâmicos (std::vector)
- Estrutura CRUD (Create, Read, Update, Delete)

---

## Estrutura do Projeto
```
Projeto-Edoo/
├── build/            # Arquivos compilados
├── data/             # Dados persistentes (banco de dados, JSON, etc.)
├── include/          # Arquivos de cabeçalho (.h)
├── src/              # Implementação do código-fonte (.cpp)
├── Projeto-EDOO/     # Interface gráfica do qt creator
├── meu_banco.db      # Banco de dados (SQLite, por exemplo)
├── main.cpp          # Arquivo principal
├── README.md         # Documentação do projeto
└── Projeto-Edoo.pro  # Arquivo de configuração do Qt Creator
```

---

## Como Executar o Projeto

### 1. Executar pelo Terminal do VS Code

1. **Clone o repositório**:
   ```bash
   git clone <URL-DO-REPOSITORIO>
   cd Projeto-Edoo
   ```

2. **Compile o projeto** usando g++:
   ```bash
   g++ -o projeto src/*.cpp -Iinclude -std=c++11
   ```
   Se houver bibliotecas externas, ajuste o comando conforme necessário.

3. **Execute o programa**:
   ```bash
   ./projeto
   ```

4. **Caso utilize CMake**, crie um diretório `build` e compile:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ./projeto
   ```

---

### 2. Executar pelo Qt Creator

1. **Abra o Qt Creator**
2. **Carregue o projeto**:
   - Vá em `Arquivo > Abrir Arquivo ou Projeto`
   - Selecione o arquivo `Projeto-Edoo.pro`
3. **Configure o Kit de Compilação**
   - Certifique-se de que o Qt adequado está selecionado
4. **Compile e execute**:
   - Clique em `Executar` ou pressione `Ctrl + R`

A interface será carregada conforme o design implementado no Qt Designer.

---

## Funcionalidades Principais

### Cadastro de Usuários
- **Administrador**: gerencia usuários, livros e empréstimos.
- **Leitor Comum**: pode alugar livros, devolver e gerenciar seus empréstimos.

### Gerenciamento de Livros
- **Livro Físico**: atributos como peso, tipo de capa e quantidade em estoque.
- **Livro Digital**: atributos como tamanho do arquivo, licença digital e formato.

### Controle de Empréstimos
- Criar e encerrar empréstimos.
- Atualizar datas e custos de empréstimo.
- Listagem de empréstimos ativos e históricos.

### Menus Diferenciados
- **Administrador**: gerenciamento de usuários, livros e empréstimos.
- **Leitor Comum**: visualização de livros, pesquisa e controle de empréstimos.

---

## Fluxo de Execução

### `main.cpp`
1. **exibirMenuLogin()**: autentica CPF e senha.
2. Se o usuário logar como **Administrador**, chama `exibirInterfaceAdministrador()`.
3. Se logar como **Leitor Comum**, chama `exibirInterfaceLeitorComum()`.

### Interface de Administrador
- Gerenciar usuários, livros e empréstimos.

### Interface de Leitor Comum
- Visualiza livros, pesquisa e gerencia empréstimos.

---

## Detalhes de Implementação

### Classe `Sistema`
- Mantém vetores de usuários e livros.
- Lista de empréstimos (`std::vector<Emprestimo>`).
- Métodos de busca e manipulação CRUD.

### Classes `Livro`, `LivroFisico`, `LivroDigital`
- `Livro` é abstrata com método `exibir()` virtual.
- `LivroFisico`: peso, tipo de capa, quantidade.
- `LivroDigital`: tamanho do arquivo, formato.

### Classes `Usuario`, `LeitorComum`, `Administrador`
- `Usuario`: CPF, nome, senha.
- `LeitorComum`: gerencia seus empréstimos.
- `Administrador`: pode alterar o sistema.

### Classe `Emprestimo`
- Armazena ponteiros para `Usuario*` e `Livro*`.
- Data de empréstimo, devolução, custo e status.

---

