#include "menuadministradorlogado.h"
#include "ui_menuadministradorlogado.h"

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
    this->close();
    GerenciamentoLivros gerenciadorLivros;
    gerenciadorLivros.exec();
}


void MenuAdministradorLogado::on_pushButton_5_clicked()
{
    this->close();
    GerenciamentoLivrosFisicos gerenciadorFisico;
    gerenciadorFisico.exec();

}

