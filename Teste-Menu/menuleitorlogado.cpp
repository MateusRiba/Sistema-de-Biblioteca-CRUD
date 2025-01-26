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
    emprestimosA = new EmprestimosAtivos(this);
    emprestimosA->show();
}


void MenuLeitorLogado::on_pushButton_clicked()
{
    emprestimosF = new EmprestimosFinalizados(this);
    emprestimosF->show();
}

