#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include "sessao.h"


Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_btnEntrar_clicked()
{
    QString cpf = ui->lineEdit_cpf->text();
    QString senha = ui->lineEdit_senha->text();

    QSqlQuery query;
    if(query.exec("SELECT * FROM Administrador WHERE cpf='"+ cpf +"' AND senha='"+ senha +"'")){
        int cont=0;
        while(query.next()){
            cont++;
        }
        if(cont > 0) {
            QMessageBox::information(this, "Sucesso", "Login efetuado com sucesso! Seja bem-vindo(a).");
            Sessao::setNomeUsuario(query.value("nome").toString());
            Sessao::setCpfUsuario(query.value("cpf").toString());
            this->close();
            MenuAdministradorLogado menuAdm;
            menuAdm.exec();
        }
    }
<<<<<<< HEAD
    if(query.exec("SELECT * FROM Usuarios WHERE cpf='" + cpf + "' AND senha='" + senha + "'")) {
=======
    if(query.exec("SELECT nome, cpf, senha FROM usuarios WHERE cpf='" + cpf + "' AND senha='" + senha + "'")) {
>>>>>>> 138b430510f3febcdcea37a80b110d597b009f0d
        int cont = 0;
        while(query.next()) {
            Sessao::setNomeUsuario(query.value("nome").toString());
            Sessao::setCpfUsuario(query.value("cpf").toString());
            cont++;
        }
        if(cont > 0) {

            QMessageBox::information(this, "Sucesso", "Login efetuado com sucesso! Seja bem-vindo(a).");
            qDebug() << "Nome armazenado na sessão: " << Sessao::getNomeUsuario();
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
