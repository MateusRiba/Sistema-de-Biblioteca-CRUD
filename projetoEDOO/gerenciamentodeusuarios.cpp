#include "gerenciamentodeusuarios.h"
#include "ui_gerenciamentodeusuarios.h"

GerenciamentoDeUsuarios::GerenciamentoDeUsuarios(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GerenciamentoDeUsuarios)
{
    ui->setupUi(this);
}

GerenciamentoDeUsuarios::~GerenciamentoDeUsuarios()
{
    delete ui;
}

void GerenciamentoDeUsuarios::on_pushButton_2_clicked()
{
    cadastroU = new CadastroUsuarioadm(this);
    cadastroU->show();
}


void GerenciamentoDeUsuarios::on_pushButton_5_clicked()
{
    removerU = new RemoverUsuarioCPF(this);
    removerU->show();
}

