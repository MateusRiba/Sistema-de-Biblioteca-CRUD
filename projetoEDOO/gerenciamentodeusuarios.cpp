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
