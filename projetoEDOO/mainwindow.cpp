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

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
    userG = new GerenciamentoDeUsuarios(this);
    userG->exec();

}



void MainWindow::on_pushButton_3_clicked()
{
    this->close();
    livrosG = new GerenciamentoLivros(this);
    livrosG->show();
}


void MainWindow::on_pushButton_clicked()
{
    this->close();
    emprestG = new GerenciamentodeEmprestimos(this);
    emprestG->show();
}

