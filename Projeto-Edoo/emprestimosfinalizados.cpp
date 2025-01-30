#include "emprestimosfinalizados.h"
#include "ui_emprestimosfinalizados.h"
#include "sessao.h"

EmprestimosFinalizados::EmprestimosFinalizados(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EmprestimosFinalizados)
{
    ui->setupUi(this);
    listarEmprestimosFinalizados();
}

EmprestimosFinalizados::~EmprestimosFinalizados()
{
    delete ui;
}

void EmprestimosFinalizados::listarEmprestimosFinalizados()
{
    // Obtém o CPF do usuário logado
    QString cpfUsuario = Sessao::getCpfUsuario();

    if (cpfUsuario.isEmpty()) {
        QMessageBox::warning(this, "Erro", "Não foi possível obter o CPF do usuário logado.");
        return;
    }

    // Limpa a tabela antes de carregar os dados
    ui->tw_visualizar_emprestimos->setRowCount(0);

    ui->tw_visualizar_emprestimos->setColumnCount(6);
    ui->tw_visualizar_emprestimos->setHorizontalHeaderLabels(QStringList()
                                                             << "ID Empréstimo"
                                                             << "Título do Livro"
                                                             << "ISBN do Livro"  // Adicionando o título da coluna ISBN
                                                             << "Data do Empréstimo"
                                                             << "Data de Devolução"
                                                             << "Status"  // Adicionando o título da coluna Status
                                                             );


    // Consulta para buscar os empréstimos do usuário logado com status "Concluído"
    QSqlQuery query;
    query.prepare("SELECT id_emprestimo, titulo_livro, isbn_livro, data_emprestimo, data_devolucao, status "
                  "FROM Emprestimos "
                  "WHERE cpf_usuario = :cpfUsuario");
    query.bindValue(":cpfUsuario", cpfUsuario);

    if (query.exec()) {
        int linha = 0;

        // Preenche a tabela com os dados retornados
        while (query.next()) {
            ui->tw_visualizar_emprestimos->insertRow(linha);
            ui->tw_visualizar_emprestimos->setItem(linha, 0, new QTableWidgetItem(query.value("id_emprestimo").toString())); // ID do Empréstimo
            ui->tw_visualizar_emprestimos->setItem(linha, 1, new QTableWidgetItem(query.value("titulo_livro").toString())); // Título do Livro
            ui->tw_visualizar_emprestimos->setItem(linha, 2, new QTableWidgetItem(query.value("isbn_livro").toString()));   // ISBN do Livro
            ui->tw_visualizar_emprestimos->setItem(linha, 3, new QTableWidgetItem(query.value("data_emprestimo").toString())); // Data de Empréstimo
            ui->tw_visualizar_emprestimos->setItem(linha, 4, new QTableWidgetItem(query.value("data_devolucao").toString()));  // Data de Devolução
            ui->tw_visualizar_emprestimos->setItem(linha, 5, new QTableWidgetItem(query.value("status").toString()));       // Status
            ui->tw_visualizar_emprestimos->setRowHeight(linha, 20);
            linha++;
        }

        // Caso nenhum empréstimo "Concluído" seja encontrado
        if (linha == 0) {
            QMessageBox::information(this, "Sem empréstimos", "Nenhum empréstimo concluído encontrado para o usuário logado.");
        }
    } else {
        QMessageBox::warning(this, "Erro", "Erro ao carregar os empréstimos: " + query.lastError().text());
        qDebug() << "Erro na query:" << query.lastError().text();
    }
}
