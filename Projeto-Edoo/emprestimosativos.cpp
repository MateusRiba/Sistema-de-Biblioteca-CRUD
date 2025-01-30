#include "emprestimosativos.h"
#include "ui_emprestimosativos.h"
#include "sessao.h"

EmprestimosAtivos::EmprestimosAtivos(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EmprestimosAtivos)
{
    ui->setupUi(this);
    listarEmprestimosAtivos();
}

EmprestimosAtivos::~EmprestimosAtivos()
{
    delete ui;
}

void EmprestimosAtivos::listarEmprestimosAtivos() {
    // Verificar se o nome do usuário logado está definido
    QString nomeUsuario = Sessao::getNomeUsuario();
    if (nomeUsuario.isEmpty()) {
        QMessageBox::warning(this, "Erro", "Nenhum usuário logado.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT titulo_livro, data_emprestimo, data_devolucao "
                  "FROM Emprestimo "
                  "WHERE usuario = :nome AND devolvido = 0"); // Filtra pelo nome e empréstimos ativos
    query.bindValue(":nome", nomeUsuario);

    if (!query.exec()) {
        QMessageBox::critical(this, "Erro", "Erro ao consultar os empréstimos: " + query.lastError().text());
        return;
    }

    // Configurar o QTableWidget
    ui->tableWidget->setRowCount(0); // Limpa as linhas existentes
    ui->tableWidget->setColumnCount(3); // Três colunas: Título, Data de Empréstimo, Data de Devolução
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Título do Livro" << "Data do Empréstimo" << "Data de Devolução");

    int row = 0;

    // Preencher os dados no QTableWidget
    while (query.next()) {
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("titulo_livro").toString()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("data_emprestimo").toString()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value("data_devolucao").toString()));
        row++;
    }

    if (row == 0) {
        QMessageBox::information(this, "Informação", "Nenhum empréstimo ativo encontrado.");
    }
}
