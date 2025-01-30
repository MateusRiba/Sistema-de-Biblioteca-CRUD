#include "fmeditarusuario.h"
#include "ui_fmeditarusuario.h"
#include <QtSql>
#include <QMessageBox>

static QString var_cpf;

FmEditarUsuario::FmEditarUsuario(QWidget *parent, QString cpf)
    : QDialog(parent)
    , ui(new Ui::FmEditarUsuario)
{
    ui->setupUi(this);
    var_cpf = cpf;

    QSqlQuery query;

    // Corrige a query para usar CPF
    query.prepare("SELECT nome, endereco, telefone FROM Usuarios WHERE cpf = :cpf");
    query.bindValue(":cpf", var_cpf);

    qDebug() << "CPF para edição:" << var_cpf;

    if (query.exec()) {
        if (query.first()) {
            // Preenche os campos do formulário
            ui->lineEdit_nome->setText(query.value(0).toString());
            ui->lineEdit_endereco->setText(query.value(1).toString());
            ui->lineEdit_telefone->setText(query.value(2).toString());
        } else {
            QMessageBox::warning(this, "Erro", "Usuário não encontrado.");
        }
    } else {
        QMessageBox::warning(this, "Erro", "Erro ao executar consulta no banco de dados.");
        qDebug() << "Erro na query:" << query.lastError().text();
    }
}

FmEditarUsuario::~FmEditarUsuario()
{
    delete ui;
}

void FmEditarUsuario::on_btnCadastroLivro_clicked()
{
    // Obtém os valores do formulário
    QString nome = ui->lineEdit_nome->text();
    QString endereco = ui->lineEdit_endereco->text();
    QString telefone = ui->lineEdit_telefone->text();

    QSqlQuery query;

    // Prepara a query de atualização
    query.prepare("UPDATE Usuarios SET nome = :nome, endereco = :endereco, telefone = :telefone WHERE cpf = :cpf");
    query.bindValue(":nome", nome);
    query.bindValue(":endereco", endereco);
    query.bindValue(":telefone", telefone);
    query.bindValue(":cpf", var_cpf);

    if (query.exec()) {
        QMessageBox::information(this, "Sucesso", "Usuário atualizado com sucesso.");
        this->close(); // Fecha a janela de edição
    } else {
        QMessageBox::warning(this, "Erro", "Erro ao atualizar usuário.");
        qDebug() << "Erro no query.exec(): " << query.lastError().text();
    }
}

void FmEditarUsuario::on_pushButton_clicked()
{
    this->close();
}

