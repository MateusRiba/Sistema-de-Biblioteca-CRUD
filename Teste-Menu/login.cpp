#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

static QSqlDatabase bancoDeDados=QSqlDatabase::addDatabase("QSQLITE");

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
    , bancoDeDados(QSqlDatabase::addDatabase("QSQLITE"))
{
    ui->setupUi(this);
    bancoDeDados.setDatabaseName("C:/Users/giova/Documents/Projeto-Teste/meu_banco.db");

    if(!bancoDeDados.open()){
        QMessageBox::critical(this, "Erro", "Não foi possível abrir o banco de dados. Verifique o caminho e tente novamente.");
    }
    else{
        QMessageBox::information(this, "Sucesso", "Banco de dados aberto com sucesso.");
    }
}

Login::~Login()
{
    delete ui;
}

void Login::on_btnEntrar_clicked()
{
    QString cpf = ui->lineEdit_cpf->text();
    QString senha = ui->lineEdit_senha->text();

    if(!bancoDeDados.isOpen()){
        QMessageBox::critical(this, "Erro", "Banco de dados não está conectado.");
        return;
    }

    QSqlQuery query;
    if(query.exec("SELECT * FROM Administrador WHERE cpf='"+ cpf +"' AND senha='"+ senha +"'")){
        int cont=0;
        while(query.next()){
            cont++;
        }
        if(cont > 0) {
            QMessageBox::information(this, "Sucesso", "Login efetuado com sucesso! Seja bem-vindo(a).");
            this->close();
            MenuAdministradorLogado menuAdm;
            menuAdm.exec();
        }
    }
    if(query.exec("SELECT * FROM usuarios WHERE cpf='" + cpf + "' AND senha='" + senha + "'")) {
        int cont = 0;
        while(query.next()) {
            cont++;
        }
        if(cont > 0) {
            QMessageBox::information(this, "Sucesso", "Login efetuado com sucesso! Seja bem-vindo(a).");
            this->close();
            MenuLeitorLogado menuLeitor;
            menuLeitor.exec();
        }
    }
    else {
        QMessageBox::warning(this, "Erro", "Login não efetuado. CPF ou senha incorretos.");
        ui->lineEdit_cpf->clear();
        ui->lineEdit_senha->clear();
        ui->lineEdit_cpf->setFocus();
    }
}
