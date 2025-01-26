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


void MenuAdministradorLogado::on_btn_user_menu_clicked()
{
    this->close();
    gerenciamentousuarios gerenciamentoUsers;
    gerenciamentoUsers.exec();
}

