#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

static QSqlDatabase bancoDeDados=QSqlDatabase::addDatabase("QSQLITE");

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , bancoDeDados(QSqlDatabase::addDatabase("QSQLITE"))
{
    ui->setupUi(this);
    bancoDeDados.setDatabaseName("C:/Users/parac/OneDrive/Documentos/Projetos/Sistema-de-Informa-o-Bibliotec-rio/meu_banco.db");

    if(!bancoDeDados.open()){
        QMessageBox::critical(this, "Erro", "Não foi possível abrir o banco de dados. Verifique o caminho e tente novamente.");
    }
    else{
        QMessageBox::information(this, "Sucesso", "Banco de dados aberto com sucesso.");
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnLoginUser_clicked()
{
    hide();
    login = new Login(this);
    login->show();

}


void MainWindow::on_btnCadastroUser_clicked()
{
    hide();
    cadastro = new Cadastro(this);
    cadastro->show();
}


void MainWindow::on_btnLoginAdm_clicked()
{
    hide();
    login = new Login(this);
    login->show();
}

