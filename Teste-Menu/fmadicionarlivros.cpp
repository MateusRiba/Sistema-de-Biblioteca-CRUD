#include "fmadicionarlivros.h"
#include "ui_fmadicionarlivros.h"

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
    this->close();

}

void FmAdicionarLivros::on_btnCadastroLivro_clicked()
{
    QString titulo = ui->lineEdit_titulo->text();
    QString autor = ui->lineEdit_autor->text();
    QString isbn = ui->lineEdit_isbn->text();
    QString ano = ui->lineEdit_ano->text();
    QString editora = ui->lineEdit_editora->text();

}

