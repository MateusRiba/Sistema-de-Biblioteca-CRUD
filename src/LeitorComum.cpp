#include "LeitorComum.h"

#include <string>
#include <iostream>

void LeitorComum::exibir() const {
    std::cout << "Nome: " << nome << "\n"
              << "CPF: " << cpf << "\n"
              << "Endereço: " << endereco << "\n"
              << "Telefone: " << telefone << "\n"
              << "Senha: " << senha << "\n";
}

//função de adicionar emprestimo a lista do leitor
void LeitorComum::adicionarEmprestimo(const Emprestimo& emp) {
    emprestimosDoLeitor.push_back(emp);
}

// Lista todos os empréstimos ativos deste leitor
void LeitorComum::listarEmprestimos() const {
    if (emprestimosDoLeitor.empty()) {
        std::cout << "Você não possui empréstimos ativos.\n";
        return;
    }
    bool encontrou = false;
    for (const auto& emp : emprestimosDoLeitor) {
        if (!emp.isFinalizado()) {
            emp.exibirEmprestimo(); // Método que exibe detalhes do Emprestimo
            encontrou = true;
        }
    }
    if(!encontrou){
        std::cout << "Nenhum empréstimo ativo encontrado.\n";
    }
}

bool LeitorComum::encerrarEmprestimo(const std::string& isbnLivro, const std::string& dataDevolucao) {
    for (auto& emp : emprestimosDoLeitor) {
        // Verifica se o ISBN do livro no empréstimo coincide e se ainda está ativo
        if (!emp.isFinalizado() && emp.getLivro()->getISBN() == isbnLivro) {
            emp.finalizarEmprestimo(dataDevolucao); 
            return true;
        }
    }
    return false;
}