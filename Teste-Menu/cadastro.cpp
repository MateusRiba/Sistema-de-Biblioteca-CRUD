#include "cadastro.h"
#include "ui_cadastro.h"
#include <QMessageBox>

Cadastro::Cadastro(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Cadastro)
{
    ui->setupUi(this);
}

Cadastro::~Cadastro()
{
    delete ui;
}

void Cadastro::on_btnCadastro_clicked()
{
    QString nome = ui->lineEdit_nome->text();
    QString cpf = ui->lineEdit_cpf->text();
    QString endereco = ui->lineEdit_endereco->text();
    QString telefone = ui->lineEdit_telefone->text();
    QString senha = ui->lineEdit_senha->text();

    QSqlQuery query;
    query.prepare("insert into Usuarios ( nome, cpf, endereco, telefone, senha) values"
               "('"+nome+"', '"+cpf+"', '"+endereco+"', '"+telefone+"', '"+senha+"')");
    if(query.exec()) {
        QMessageBox::information(this, "Sucesso", "Usuário cadastrado com sucesso.");
        ui->lineEdit_nome->clear();
        ui->lineEdit_cpf->clear();
        ui->lineEdit_endereco->clear();
        ui->lineEdit_telefone->clear();
        ui->lineEdit_senha->clear();
        ui->lineEdit_nome->setFocus();
    }
    else {
        QMessageBox::critical(this, "Erro", "Erro ao executar a consulta no banco de dados.");
    }

}

