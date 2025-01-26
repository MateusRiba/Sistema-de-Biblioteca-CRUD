#include "menulivros.h"
#include "ui_menulivros.h"

MenuLivros::MenuLivros(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MenuLivros)
{
    ui->setupUi(this);
}

MenuLivros::~MenuLivros()
{
    delete ui;
}

void MenuLivros::on_btnVisualizarLivros_clicked()
{
    DigitalBooksList *digitalBooks = new DigitalBooksList(this);
    digitalBooks->show();

}

void MenuLivros::on_btnVisualizarFisicos_clicked()
{
    ListagemLivrosFisicos *listar = new ListagemLivrosFisicos(this);
    listar->show();
}


void MenuLivros::on_btnSair_clicked()
{

}

