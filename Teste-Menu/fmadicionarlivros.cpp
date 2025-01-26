#include "fmadicionarlivros.h"
#include "ui_fmadicionarlivros.h"
#include "gerenciamentolivros.h"

#include <QMessageBox>

FmAdicionarLivros::FmAdicionarLivros(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FmAdicionarLivros)
{
    ui->setupUi(this);
}

FmAdicionarLivros::~FmAdicionarLivros()
{
    delete ui;
}

void FmAdicionarLivros::on_commandLinkButton_clicked()
{

}

void FmAdicionarLivros::on_btnCadastroLivro_clicked()
{
    QString titulo = ui->lineEdit_titulo->text();
    QString autor = ui->lineEdit_autor->text();
    QString isbn = ui->lineEdit_isbn->text();
    QString editora = ui->lineEdit_editora->text();
    QString ano = ui->lineEdit_ano->text();
    QString valor_diaria = ui->lineEdit_valor->text();

    QSqlQuery query;
    query.prepare("insert into LivrosDigitais ( titulo, autor, isbn, editora, ano_publicacao, valor_diaria) values"
                  "('"+titulo+"', '"+autor+"', '"+isbn+"', '"+editora+"', '"+ano+"', '"+valor_diaria+"')");
    if(query.exec()) {
        QMessageBox::information(this, "Sucesso", "Livro cadastrado com sucesso.");
        this->close();
    }
    else {
        QMessageBox::critical(this, "Erro", "Erro ao executar a consulta no banco de dados.");
    }


}


void FmAdicionarLivros::on_pushButton_clicked()
{
    close();
}

