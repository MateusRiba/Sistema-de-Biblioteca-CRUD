#include "gerenciamentolivros.h"
#include "ui_gerenciamentolivros.h"

GerenciamentoLivros::GerenciamentoLivros(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GerenciamentoLivros)
{
    ui->setupUi(this);
}

GerenciamentoLivros::~GerenciamentoLivros()
{
    delete ui;
}
