#include "fmadicionarlivrosfisicos.h"
#include "ui_fmadicionarlivrosfisicos.h"
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

void FmAdicionarLivrosFisicos::on_btnCadastroLivro_2_clicked()
{
    // Obtém os valores do formulário
    QString titulo = ui->lineEdit_titulo_2->text();
    QString autor = ui->lineEdit_autor_2->text();
    QString isbn = ui->lineEdit_ISBN->text();
    QString editora = ui->lineEdit_editora_2->text();
    QString ano = ui->lineEdit_ano_2->text();
    QString valor_dia = ui->lineEdit_valor_2->text();
    QString quantidade = ui->lineEdit_qtd_2->text();
    QString peso = ui->lineEdit_peso_2->text();
    QString capa = ui->lineEdit_capa_2->text();

    QSqlQuery query;

    query.prepare("insert into LivrosFisicos ( Titulo, Autor, ISBN, Editora, AnoPublicacao, Valor, Quantidade, Peso, TipoCapa) values"
                  "('"+titulo+"', '"+autor+"', '"+isbn+"', '"+editora+"', '"+ano+"', '"+valor_dia+"', '"+quantidade+"', '"+peso+"', '"+capa+"')");
    if(query.exec()) {
        QMessageBox::information(this, "Sucesso", "Livro cadastrado com sucesso.");
        this->close();
    }
    else {
        QMessageBox::critical(this, "Erro", "Erro ao executar a consulta no banco de dados.");
    }


}

