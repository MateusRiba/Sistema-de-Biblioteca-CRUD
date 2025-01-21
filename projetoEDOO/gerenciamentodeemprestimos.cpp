#include "gerenciamentodeemprestimos.h"
#include "ui_gerenciamentodeemprestimos.h"

GerenciamentodeEmprestimos::GerenciamentodeEmprestimos(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GerenciamentodeEmprestimos)
{
    ui->setupUi(this);
}

GerenciamentodeEmprestimos::~GerenciamentodeEmprestimos()
{
    delete ui;
}
