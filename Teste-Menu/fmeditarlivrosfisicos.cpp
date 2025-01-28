#include "fmeditarlivrosfisicos.h"
#include "ui_fmeditarlivrosfisicos.h"
#include <QtSql>
#include <QMessageBox>
static QString var_isbn;

FmEditarLivrosFisicos::FmEditarLivrosFisicos(QWidget *parent, QString isbn)
    : QDialog(parent)
    , ui(new Ui::FmEditarLivrosFisicos)
{
    ui->setupUi(this);

    var_isbn=isbn;

    QSqlQuery query;

    query.prepare("select * from LivrosFisicos where isbn="+QString(isbn));
    qDebug() <<isbn;
    if (query.exec()) {
        query.first();  // Verifica se há um registro válido
            // Preenche os campos do formulário
        ui->lineEdit_titulo->setText(query.value(0).toString());  // Título
        ui->lineEdit_autor->setText(query.value(1).toString());   // Autor
        ui->lineEdit_editora->setText(query.value(3).toString()); // Editora
        ui->lineEdit_ano->setText(query.value(4).toString());     // Ano de Publicação
        ui->lineEdit_valor->setText(query.value(5).toString());   // Valor Diária
        ui->lineEdit_qtd->setText(query.value(6).toString());
        ui->lineEdit_peso->setText(query.value(7).toString());
        ui->lineEdit_capa->setText(query.value(8).toString());

    } else {
        QMessageBox::warning(this, "Erro", "Erro ao executar consulta no banco de dados.");
        qDebug() << "Erro na query:" << query.lastError().text();
    }
}

FmEditarLivrosFisicos::~FmEditarLivrosFisicos()
{
    delete ui;
}

void FmEditarLivrosFisicos::on_btnCadastroLivro_clicked()
{
    // Obtém os valores do formulário
    QString titulo = ui->lineEdit_titulo->text();
    QString autor = ui->lineEdit_autor->text();
    QString editora = ui->lineEdit_editora->text();
    QString ano = ui->lineEdit_ano->text();
    QString valor_dia = ui->lineEdit_valor->text();
    QString quantidade = ui->lineEdit_qtd->text();
    QString peso = ui->lineEdit_peso->text();
    QString capa = ui->lineEdit_capa->text();

    QSqlQuery query;

    QString sql = "UPDATE LivrosFisicos SET "
                  "Titulo = '" + titulo + "', "
                             "Autor = '" + autor + "', "
                            "Editora = '" + editora + "', "
                              "AnoPublicacao = '" + ano + "', "
                          "Valor = '" + valor_dia + "', "
                                "Quantidade = '" + quantidade + "', "
                                 "Peso = '" + peso + "', "
                           "TipoCapa = '" + capa + "' "
                           "WHERE isbn = '" + var_isbn + "'";

    qDebug() << "Query gerada:" << sql; // Depuração: exibe a query gerada
    query.prepare(sql);

    // Executa a query e verifica o resultado
    if (query.exec()) {
        QMessageBox::information(this, "Sucesso", "Livro atualizado com sucesso.");
        this->close(); // Fecha a janela de edição
    } else {
        QMessageBox::warning(this, "Erro", "Erro ao atualizar livro.");
        qDebug() << "Erro no query.exec():" << query.lastError().text(); // Depuração para exibir o erro
    }
}
