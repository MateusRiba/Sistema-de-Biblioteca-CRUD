#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

