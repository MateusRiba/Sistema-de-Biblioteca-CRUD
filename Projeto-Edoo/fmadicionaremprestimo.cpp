#include "fmadicionaremprestimo.h"
#include "ui_fmadicionaremprestimo.h"
#include <QtSql>
#include <QMessageBox>
#include <QDebug>

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
    QSqlQuery queryUsuario;
    queryUsuario.prepare("SELECT nome FROM Usuarios WHERE cpf = :cpf");
    queryUsuario.bindValue(":cpf", cpfUsuario);

    QString nomeUsuario;
    if (queryUsuario.exec() && queryUsuario.next()) {
        nomeUsuario = queryUsuario.value("nome").toString(); // Nome do usuário associado ao CPF
        ui->label_nome_user->setText(nomeUsuario); // Atualiza a label com o nome do usuário
    } else {
        QMessageBox::warning(this, "Erro", "O CPF informado não está registrado no sistema.");
        return;
    }
    QString tituloLivro;
    QSqlQuery queryLivro;

    // Verifica se o ISBN está na tabela LivrosDigitais
    queryLivro.prepare("SELECT titulo FROM LivrosDigitais WHERE isbn = :isbn");
    queryLivro.bindValue(":isbn", isbnLivro);

    if (queryLivro.exec() && queryLivro.next()) {
        tituloLivro = queryLivro.value("titulo").toString();
        qDebug() << "Livro encontrado em LivrosDigitais: " << tituloLivro;
    } else {
        qDebug() << "ISBN não encontrado em LivrosDigitais. Verificando LivrosFisicos...";

        // Criar um novo objeto QSqlQuery para evitar reset de bindValue
        QSqlQuery queryLivroFisico;
        queryLivroFisico.prepare("SELECT titulo_livro FROM LivrosFisicos WHERE isbn = :isbn");
        queryLivroFisico.bindValue(":isbn", isbnLivro);
        qDebug() << "ISBN informado:" << isbnLivro;
        qDebug() << "Título:" << tituloLivro;

        if (queryLivroFisico.exec() && queryLivroFisico.next()) {
            tituloLivro = queryLivroFisico.value("titulo_livro").toString();
            qDebug() << "Livro encontrado em LivrosFisicos: " << tituloLivro;
        } else {
            qDebug() << "ISBN não encontrado em LivrosFisicos.";
            QMessageBox::warning(this, "Erro", "O ISBN informado não está registrado no sistema.");
            return;
        }
    }

    // Prepara a query para adicionar o empréstimo
    QSqlQuery queryEmprestimo;
    queryEmprestimo.prepare("INSERT INTO Emprestimos (cpf_usuario, isbn_livro, data_emprestimo, data_devolucao, status) "
                            "VALUES (:cpf_usuario, :isbn_livro, :data_emprestimo, :data_devolucao, :status)");
    queryEmprestimo.bindValue(":cpf_usuario", cpfUsuario);
    queryEmprestimo.bindValue(":isbn_livro", isbnLivro);
    queryEmprestimo.bindValue(":data_emprestimo", dataEmprestimo);
    queryEmprestimo.bindValue(":data_devolucao", dataDevolucao);
    queryEmprestimo.bindValue(":status", "Ativo"); // Status padrão "Ativo"

    // Executa a query
    if (queryEmprestimo.exec()) {
        QMessageBox::information(this, "Sucesso", "Empréstimo cadastrado com sucesso!");
        close(); // Fecha a janela
    } else {
        QMessageBox::warning(this, "Erro", "Erro ao cadastrar o empréstimo: " + queryEmprestimo.lastError().text());
        qDebug() << "Erro ao inserir empréstimo:" << queryEmprestimo.lastError().text();
    }
}

void FmAdicionarEmprestimo::on_btnCancelar_clicked()
{
    close(); // Fecha a janela sem salvar
}
