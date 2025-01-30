#include "fmeditarlivros.h"
#include <QMessageBox>
#include "ui_fmeditarlivros.h"

#include <QtSql>

static QString var_isbn;

FmEditarLivros::FmEditarLivros(QWidget *parent, QString isbn)
    : QDialog(parent)
    , ui(new Ui::FmEditarLivros)
{
    ui->setupUi(this);
    var_isbn=isbn;

    QSqlQuery query;

    query.prepare("select * from LivrosDigitais where isbn="+QString(isbn));
    qDebug() <<isbn;
    if (query.exec()) {
        query.first();  // Verifica se há um registro válido
            // Preenche os campos do formulário
        ui->lineEdit_titulo->setText(query.value(0).toString());  // Título
        ui->lineEdit_autor->setText(query.value(1).toString());   // Autor
        ui->lineEdit_editora->setText(query.value(3).toString()); // Editora
        ui->lineEdit_ano->setText(query.value(4).toString());     // Ano de Publicação
        ui->lineEdit_valor->setText(query.value(5).toString());   // Valor Diária

    } else {
        QMessageBox::warning(this, "Erro", "Erro ao executar consulta no banco de dados.");
        qDebug() << "Erro na query:" << query.lastError().text();
    }
}

FmEditarLivros::~FmEditarLivros()
{
    delete ui;
}

void FmEditarLivros::on_btnCadastroLivro_clicked()
{
    // Obtém os valores do formulário
    QString titulo = ui->lineEdit_titulo->text();
    QString autor = ui->lineEdit_autor->text();
    QString editora = ui->lineEdit_editora->text();
    QString ano = ui->lineEdit_ano->text();
    QString valor_dia = ui->lineEdit_valor->text();

    QSqlQuery query;

    // Prepara a query usando bindValue para evitar erros e injeção de SQL
    query.prepare("UPDATE LivrosDigitais SET titulo = :titulo, autor = :autor, editora = :editora, "
                  "ano_publicacao = :ano, valor_diaria = :valor WHERE isbn = :isbn");
    query.bindValue(":titulo", titulo);
    query.bindValue(":autor", autor);
    query.bindValue(":editora", editora);
    query.bindValue(":ano", ano);
    query.bindValue(":valor", valor_dia);
    query.bindValue(":isbn", var_isbn); // Usa o ISBN como identificador

    // Executa a query
    if (query.exec()) {
        QMessageBox::information(this, "Sucesso", "Livro atualizado com sucesso.");
        this->close(); // Fecha a janela de edição
    } else {
        QMessageBox::warning(this, "Erro", "Erro ao atualizar livro.");
        qDebug() << "Erro no query.exec(): " << query.lastError().text(); // Depuração para exibir o erro
    }
}


void FmEditarLivros::on_pushButton_clicked()
{
    this->close();
}

