#include "fmadicionarlivrosfisicos.h"
#include "ui_fmadicionarlivrosfisicos.h"
#include <QtSql>
#include <QMessageBox>

FmAdicionarLivrosFisicos::FmAdicionarLivrosFisicos(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FmAdicionarLivrosFisicos)
{
    ui->setupUi(this);
}

FmAdicionarLivrosFisicos::~FmAdicionarLivrosFisicos()
{
    delete ui;
}

void FmAdicionarLivrosFisicos::on_btnCadastroLivro_clicked()
{
    QString titulo = ui->lineEdit_titulo->text().trimmed();
    QString autor = ui->lineEdit_autor->text().trimmed();
    QString isbn = ui->lineEdit_isbn->text().trimmed();
    QString editora = ui->lineEdit_editora->text().trimmed();
    QDate ano_publicacao = ui->dateEdit_ano->date();
    double valor_diaria = ui->lineEdit_valor->text().toDouble();
    int qt_disponivel = ui->spinBox_estoque->value();
    double peso = ui->lineEdit_peso->text().toDouble();
    QString tipo_capa = ui->comboBox_capa->currentText().trimmed();

    // Validação de campos obrigatórios
    if (titulo.isEmpty() || autor.isEmpty() || isbn.isEmpty() || editora.isEmpty() || tipo_capa.isEmpty()) {
        QMessageBox::warning(this, "Erro", "Todos os campos devem ser preenchidos.");
        return;
    }

    // Insere os dados na tabela LivrosFisicos
    QSqlQuery query;
    query.prepare("INSERT INTO LivrosFisicos (titulo_livro, autor_livro, isbn, editora, ano_publicacao, "
                  "valor_diaria, qt_disponivel, peso, tipo_capa) "
                  "VALUES (:titulo, :autor, :isbn, :editora, :ano, :valor, :estoque, :peso, :capa)");

    query.bindValue(":titulo", titulo);
    query.bindValue(":autor", autor);
    query.bindValue(":isbn", isbn);
    query.bindValue(":editora", editora);
    query.bindValue(":ano", ano_publicacao);
    query.bindValue(":valor", valor_diaria);
    query.bindValue(":estoque", qt_disponivel);
    query.bindValue(":peso", peso);
    query.bindValue(":capa", tipo_capa);

    if (query.exec()) {
        QMessageBox::information(this, "Sucesso", "Livro físico cadastrado com sucesso!");
        this->close();
    } else {
        QMessageBox::critical(this, "Erro", "Erro ao executar a consulta no banco de dados: " + query.lastError().text());
    }

}

