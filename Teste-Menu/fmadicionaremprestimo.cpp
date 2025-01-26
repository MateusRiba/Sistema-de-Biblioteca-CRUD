#include "fmadicionaremprestimo.h"
#include "ui_fmadicionaremprestimo.h"
#include <QtSql>
#include <QMessageBox>

FmAdicionarEmprestimo::FmAdicionarEmprestimo(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FmAdicionarEmprestimo)
{
    ui->setupUi(this);

    // Configurações iniciais
    ui->dateEdit_emprestimo->setDate(QDate::currentDate()); // Data de empréstimo padrão
    ui->dateEdit_devolucao->setDate(QDate::currentDate().addDays(7)); // Data de devolução padrão
}

FmAdicionarEmprestimo::~FmAdicionarEmprestimo()
{
    delete ui;
}

void FmAdicionarEmprestimo::on_btnSalvar_clicked()
{
    // Obtém os valores preenchidos nos campos
    QString cpfUsuario = ui->lineEdit_cpf->text().trimmed();
    QString isbnLivro = ui->lineEdit_isbn->text().trimmed();
    QDate dataEmprestimo = ui->dateEdit_emprestimo->date();
    QDate dataDevolucao = ui->dateEdit_devolucao->date();

    // Valida os campos obrigatórios
    if (cpfUsuario.isEmpty() || isbnLivro.isEmpty()) {
        QMessageBox::warning(this, "Erro", "Por favor, preencha todos os campos obrigatórios!");
        return;
    }

    // Verifica se a data de devolução é válida
    if (dataDevolucao <= dataEmprestimo) {
        QMessageBox::warning(this, "Erro", "A data de devolução deve ser posterior à data de empréstimo.");
        return;
    }

    // Verifica se o CPF existe na tabela Usuarios
    QSqlQuery query;
    query.prepare("SELECT nome FROM Usuarios WHERE cpf = :cpf");
    query.bindValue(":cpf", cpfUsuario);

    QString nomeUsuario;
    if (query.exec() && query.next()) {
        nomeUsuario = query.value("nome").toString(); // Nome do usuário associado ao CPF
        ui->label_nome_user->setText(nomeUsuario); // Atualiza a label com o nome do usuário
    } else {
        QMessageBox::warning(this, "Erro", "O CPF informado não está registrado no sistema.");
        return;
    }

    // Verifica se o ISBN existe na tabela Livros
    query.prepare("SELECT titulo FROM LivrosDigitais WHERE isbn = :isbn");
    query.bindValue(":isbn", isbnLivro);

    QString tituloLivro;
    if (query.exec() && query.next()) {
        tituloLivro = query.value("titulo").toString(); // Título do livro associado ao ISBN
        ui->label_titulo_livro->setText(tituloLivro); // Atualiza a label com o título do livro
    } else {
        QMessageBox::warning(this, "Erro", "O ISBN informado não está registrado no sistema.");
        return;
    }

    // Prepara a query para adicionar o empréstimo
    query.prepare("INSERT INTO Emprestimos (cpf_usuario, isbn_livro, data_emprestimo, data_devolucao, status) "
                  "VALUES (:cpf_usuario, :isbn_livro, :data_emprestimo, :data_devolucao, :status)");
    query.bindValue(":cpf_usuario", cpfUsuario);
    query.bindValue(":isbn_livro", isbnLivro);
    query.bindValue(":data_emprestimo", dataEmprestimo);
    query.bindValue(":data_devolucao", dataDevolucao);
    query.bindValue(":status", "Ativo"); // Status padrão "Ativo"

    // Executa a query
    if (query.exec()) {
        QMessageBox::information(this, "Sucesso", "Empréstimo cadastrado com sucesso!");
        close(); // Fecha a janela
    } else {
        QMessageBox::warning(this, "Erro", "Erro ao cadastrar o empréstimo: " + query.lastError().text());
    }
}

void FmAdicionarEmprestimo::on_btnCancelar_clicked()
{
    close(); // Fecha a janela sem salvar
}
