#include "fmeditaremprestimo.h"
#include "ui_fmeditaremprestimo.h"
#include <QtSql>
#include <QMessageBox>

FmEditarEmprestimo::FmEditarEmprestimo(QWidget *parent, int idEmprestimo)
    : QDialog(parent)
    , ui(new Ui::FmEditarEmprestimo)
    , id_emprestimo(idEmprestimo)
{
    ui->setupUi(this);

    // Inicializa os campos com os dados do empréstimo
    carregarDadosEmprestimo();
}

FmEditarEmprestimo::~FmEditarEmprestimo()
{
    delete ui;
}

void FmEditarEmprestimo::carregarDadosEmprestimo()
{
    // Consulta para buscar os dados do empréstimo pelo ID, incluindo LivrosDigitais e LivrosFisicos
    QSqlQuery query;
    query.prepare(
        "SELECT e.id_emprestimo, u.nome, "
        "COALESCE(ld.titulo, lf.titulo_livro) AS titulo, " // Garante que o título correto seja pego
        "e.data_emprestimo, e.data_devolucao, e.status "
        "FROM Emprestimos e "
        "JOIN Usuarios u ON e.cpf_usuario = u.cpf "
        "LEFT JOIN LivrosDigitais ld ON e.isbn_livro = ld.isbn "
        "LEFT JOIN LivrosFisicos lf ON e.isbn_livro = lf.isbn "
        "WHERE e.id_emprestimo = :id_emprestimo");

    query.bindValue(":id_emprestimo", id_emprestimo);

    if (query.exec() && query.next()) {
        // Preenche os campos com os dados do empréstimo
        ui->label_id->setText(query.value("id_emprestimo").toString()); // ID do empréstimo
        ui->label_nome_user->setText(query.value("nome").toString());  // Nome do usuário
        ui->label_titulo->setText(query.value("titulo").toString()); // Título do livro
        ui->label_emprestimo->setText(query.value("data_emprestimo").toString()); // Data de empréstimo
        ui->label_devolucao->setText(query.value("data_devolucao").toString());   // Data de devolução
        ui->comboBox->setCurrentText(query.value("status").toString());        // Status atual
    } else {
        QMessageBox::warning(this, "Erro", "Erro ao carregar os dados do empréstimo: " + query.lastError().text());
        close(); // Fecha a janela se não for possível carregar os dados
    }

    // Desabilita os campos que não podem ser editados
    ui->label_id->setEnabled(false);
    ui->label_nome_user->setEnabled(false);
    ui->label_titulo->setEnabled(false);
    ui->label_emprestimo->setEnabled(false);
    ui->label_devolucao->setEnabled(false);
}

void FmEditarEmprestimo::on_btnSalvarEmprestimo_clicked()
{
    // Obtém o novo status selecionado
    QString novoStatus = ui->comboBox->currentText();

    // Atualiza o status no banco de dados
    QSqlQuery query;
    query.prepare("UPDATE Emprestimos SET status = :status WHERE id_emprestimo = :id_emprestimo");
    query.bindValue(":status", novoStatus);
    query.bindValue(":id_emprestimo", id_emprestimo);

    if (query.exec()) {
        QMessageBox::information(this, "Sucesso", "Status do empréstimo atualizado com sucesso!");
        close(); // Fecha a janela após salvar
    } else {
        QMessageBox::warning(this, "Erro", "Erro ao atualizar o status: " + query.lastError().text());
    }
}

void FmEditarEmprestimo::on_btnCancelarEmprestimo_clicked()
{
    close();
}
