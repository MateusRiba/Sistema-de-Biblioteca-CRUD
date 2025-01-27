#include "menuleitorlogado.h"
#include "ui_menuleitorlogado.h"

MenuLeitorLogado::MenuLeitorLogado(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MenuLeitorLogado)
{
    ui->setupUi(this);
}

MenuLeitorLogado::~MenuLeitorLogado()
{
    delete ui;
}

void MenuLeitorLogado::on_btnVisualizarLivros_clicked()
{
    menuLivros = new MenuLivros(this);
    menuLivros->show();
}


void MenuLeitorLogado::on_btnVisualizarEmprestimo_clicked()
{
    emprestimos = new ListagemEmprestimos(this);
    emprestimos->show();
}


void MenuLeitorLogado::on_pushButton_clicked()
{
    emprestimosF = new EmprestimosFinalizados(this);
    emprestimosF->show();
}


void MenuLeitorLogado::on_btnSair_clicked()
{
    // Exibe uma mensagem de confirmação
    QMessageBox::StandardButton confirmacao;
    confirmacao = QMessageBox::question(this, "Confirmação",
                                        "Você realmente deseja sair?",
                                        QMessageBox::Yes | QMessageBox::No);

    // Verifica a resposta do usuário
    if (confirmacao == QMessageBox::Yes) {
        QApplication::quit(); // Fecha o programa
    }
    // Caso seja "No", não faz nada e retorna à janela
}

