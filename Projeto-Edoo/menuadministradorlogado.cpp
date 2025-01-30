#include "menuadministradorlogado.h"
#include "ui_menuadministradorlogado.h"
#include <QMessageBox>

MenuAdministradorLogado::MenuAdministradorLogado(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MenuAdministradorLogado)
{
    ui->setupUi(this);
}

MenuAdministradorLogado::~MenuAdministradorLogado()
{
    delete ui;
}

void MenuAdministradorLogado::on_pushButton_3_clicked()
{

    GerenciamentoLivros gerenciadorLivros;
    gerenciadorLivros.exec();
}


void MenuAdministradorLogado::on_btn_user_menu_clicked()
{

    gerenciamentousuarios gerenciamentoUsers;
    gerenciamentoUsers.exec();
}


void MenuAdministradorLogado::on_btn_Emprestimos_clicked()
{

    FmGerenciarEmprestimos fmGerenciarEmprestimo;
    fmGerenciarEmprestimo.exec();
}


void MenuAdministradorLogado::on_pushButton_4_clicked()
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


void MenuAdministradorLogado::on_pushButton_5_clicked()
{
    GerenciamentoLivrosFisicos gerenciarFisicos;
    gerenciarFisicos.exec();
}

