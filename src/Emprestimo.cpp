#include "Emprestimo.h"

//Inclusão dos headers de Usuario e Livro, pois aqui na implementação será necessário
#include "Usuario.h"
#include "Livro.h"

//inclusão de bibliotecas que lidam com tempo
#include <sstream>
#include <iomanip>
#include <ctime>

//iostream
#include <iostream> 
using namespace std;

//Funções Auxiliares (Servem para a manipulação de Datas) --> Encontrei na Internet, talvez seja valido aplicar isso como uma função de Sistema, mas por agora está restrito aqui.

// Converte string no formato "dd/mm/yyyy" para std::tm
namespace { //isso serve para manter as funções não visiveis no arquivo, pois só é usado aqui
    std::tm stringParaData(const std::string& dataStr) {
        std::tm tm = {};
        std::istringstream ss(dataStr);
        ss >> std::get_time(&tm, "%d/%m/%Y"); // Formato: dd/mm/yyyy
        if (ss.fail()) {
            throw std::runtime_error("Formato de data inválido: " + dataStr);
        }
        return tm;
    }

    // Calcula a diferença em dias entre duas datas no formato "dd/mm/yyyy"
    int diferencaDias(const std::string& dataInicio, const std::string& dataFim) {
        std::tm inicio = stringParaData(dataInicio);
        std::tm fim = stringParaData(dataFim);

        std::time_t tInicio = std::mktime(&inicio);
        std::time_t tFim = std::mktime(&fim);

        if (tInicio == -1 || tFim == -1) {
            throw std::runtime_error("Erro ao converter data para tempo.");
        }

        double segundos = std::difftime(tFim, tInicio);
        return static_cast<int>(segundos / (60 * 60 * 24)); // Segundos por dia
    }
}

/*
  Construtor:
  - Inicializa os ponteiros de usuario e livro, Armazena as datas e finalizado começa como false (não devolvido ainda).
*/
Emprestimo::Emprestimo(Usuario* u, Livro* l, const std::string& dataEmp, const std::string& dataDev)
    : usuario(u), livro(l), dataEmprestimo(dataEmp), dataDevolucao(dataDev),finalizado(false) {
    //Tentativa de Calcular o Custo.
    try {

        if (diferencaDias(dataEmprestimo, dataDevolucao) < 0) {
        throw std::invalid_argument("A data de devolução não pode ser anterior à data de empréstimo.");
}
        custo = diferencaDias(dataEmprestimo,dataDevolucao) * l->getValorDiaria();

    } catch (const std::exception& e) {
        std::cerr << "Erro ao calcular custo do empréstimo: " << e.what() << "\n";
        custo = 0; // Define custo padrão em caso de erro
        }
}

//Destrutor:
Emprestimo::~Emprestimo() {
    // Nenhuma ação específica é necessária aqui, pois o destrutor não precisa liberar recursos diretamente.
}

void Emprestimo::finalizarEmprestimo(const std::string& dataRealDevolucao) {
    dataDevolucao = dataRealDevolucao;
    finalizado = true;
}
/*
  função de exibirEmprestimo:
  OBS: (IMPORTANTE) Como Usuario e Livro são abstratas, de fato "this->usuario" pode
    apontar para um LeitorComum ou Administrador; "this->livro" pode ser
    um LivroFisico ou LivroDigital.
*/
void Emprestimo::exibirEmprestimo() const {
    cout << "=== Emprestimo ===\n";
    
    cout << "Usuario que alugou o Livro:" << endl;
    cout << usuario->getNome() << endl; //Assim se chama o metodo de outra Classe
    cout << "Livro alugado:" << endl;
    cout << livro->getTitulo() << endl;

    cout << "Data de Emprestimo: " << dataEmprestimo << "\n";
    cout << "Data de Devolucao (prevista ou real): " << dataDevolucao << "\n";
    cout << "Status: " << (finalizado ? "Finalizado (Devolvido)" : "Em Aberto") << "\n"; //verificação de booleano
    cout << "Custo: R$ " << custo << "\n";
    cout << "====================\n";
}

//Usuario
Usuario* Emprestimo::getUsuario() const {
    return usuario;
}

void Emprestimo::setUsuario(Usuario* u) {
    usuario = u;
}

//Livro
Livro* Emprestimo::getLivro() const {
    return livro;
}

void Emprestimo::setLivro(Livro* l) {
    livro = l;
}

//dataEmprestimo
std::string Emprestimo::getDataEmprestimo() const {
    return dataEmprestimo;
}

void Emprestimo::setDataEmprestimo(const std::string& dataEmp) {
    dataEmprestimo = dataEmp;
}

//dataDevolucao
std::string Emprestimo::getDataDevolucao() const {
    return dataDevolucao;
}

void Emprestimo::setDataDevolucao(const std::string& dataDev) {
    dataDevolucao = dataDev;
}

// Getter e Setter para finalizado
bool Emprestimo::isFinalizado() const {
    return finalizado;
}

void Emprestimo::setFinalizado(bool status) {
    finalizado = status;
}

int Emprestimo::getCusto() const {
    return custo;
}

void Emprestimo::setCusto(int c){
    custo = c;
}

