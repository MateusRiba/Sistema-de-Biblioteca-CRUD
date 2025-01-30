#include "fmeditarlivrosfisicos.h"
#include "ui_fmeditarlivrosfisicos.h"
#include <QMessageBox>
#include <QtSql>

static QString var_isbn_fisico;

FmEditarLivrosFisicos::FmEditarLivrosFisicos(QWidget *parent, QString isbn)
    : QDialog(parent)
    , ui(new Ui::FmEditarLivrosFisicos)
{
    ui->setupUi(this);

    var_isbn_fisico = isbn;

    QSqlQuery query;
    query.prepare("select * from LivrosFisicos where isbn="+QString(isbn));

    qDebug() << "Valor de var_isbn 2:" << var_isbn_fisico;

    if (var_isbn_fisico.isEmpty()) {
        QMessageBox::warning(this, "Erro", "ISBN inválido. Não foi possível carregar os dados.");
        qDebug() << "Erro: ISBN vazio ao tentar carregar livro.";
        return;
    }

    if (query.exec()) {
        if (query.next()) {  // Se houver um registro válido
            ui->lineEdit_titulo->setText(query.value(0).toString());
            ui->lineEdit_autor->setText(query.value(1).toString());
            ui->label_isbn->setText(query.value(2).toString());
            ui->lineEdit_editora->setText(query.value(3).toString());
            ui->dateEdit_ano->setDate(query.value(4).toDate());
            ui->spinBox_estoque->setValue(query.value(5).toInt());
            ui->lineEdit_valor->setText(query.value(6).toString());
            ui->lineEdit_peso->setText(query.value(7).toString());
            ui->comboBox_capa->setCurrentText(query.value(8).toString());
        } else {
            QMessageBox::warning(this, "Erro", "Livro não encontrado no banco de dados.");
            qDebug() << "Nenhum livro encontrado com ISBN: " << var_isbn_fisico;
        }
    } else {
        QMessageBox::warning(this, "Erro", "Erro ao executar consulta no banco de dados: " + query.lastError().text());
        qDebug() << "Erro na query:" << query.lastError().text();
    }
}

FmEditarLivrosFisicos::~FmEditarLivrosFisicos()
{
    delete ui;
}

// **Botão Salvar**
void FmEditarLivrosFisicos::on_btnCadastroLivro_clicked()
{
    QString titulo_livro = ui->lineEdit_titulo->text();
    QString autor_livro = ui->lineEdit_autor->text();
    QString isbn = ui->label_isbn->text();
    QString editora = ui->lineEdit_editora->text();
    QDate ano_publicacao = ui->dateEdit_ano->date();
    QString valor_diaria = ui->lineEdit_valor->text();
    int qt_disponivel = ui->spinBox_estoque->value();
    double peso = ui->lineEdit_peso->text().toDouble();
    QString tipo_capa = ui->comboBox_capa->currentText();


    if (titulo_livro.isEmpty() || autor_livro.isEmpty() || editora.isEmpty() || tipo_capa.isEmpty()) {
        QMessageBox::warning(this, "Erro", "Todos os campos devem ser preenchidos.");
        return;
    }

    QSqlQuery query;
    query.prepare("UPDATE LivrosFisicos SET titulo_livro = :titulo, autor_livro = :autor, "
                  "editora = :editora, ano_publicacao = :ano, qt_disponivel = :estoque, valor_diaria = :valor, "
                  "peso = :peso, tipo_capa = :capa WHERE isbn = :isbn");

    query.bindValue(":titulo", titulo_livro);
    query.bindValue(":autor", autor_livro);
    query.bindValue(":isbn", isbn);
    query.bindValue(":editora", editora);
    query.bindValue(":ano", ano_publicacao);
    query.bindValue(":estoque", qt_disponivel);
    query.bindValue(":valor", valor_diaria);
    query.bindValue(":peso", peso);
    query.bindValue(":capa", tipo_capa);


    if (query.exec()) {
        QMessageBox::information(this, "Sucesso", "Livro atualizado com sucesso!");
        close();
    } else {
        QMessageBox::warning(this, "Erro", "Erro ao atualizar o livro: " + query.lastError().text());
        qDebug() << "Erro ao atualizar: " << query.lastError().text();
    }
}
